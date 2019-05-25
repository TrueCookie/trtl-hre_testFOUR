#include "Game.h"
#include "Init.h"
#include <iostream>
#include <sstream>
#include <conio.h>

Game::Game() {
	window.create(sf::VideoMode(1280, 224), "H&T");
	racersNum = 2;
	racers = new Animal*[racersNum];
	racers[0] = new Hare;
	racers[1] = new Turtle;
	gameOver = false;
	winner = nullptr;

	font.loadFromFile("images/calibrili.ttf");
	text.setFont(font);
}

Game::~Game() {}

void Game::update(){
	Clock clock;
	while (window.isOpen() && !gameOver){
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event)){
			if (event.type == Event::Closed)
				window.close();
		}
		moveThemAll();
		interactionWithMap();

		window.clear();
		drawItAll();
		window.display();
	}
	window.clear();
	drawItAll();
	endMessage();
	window.display();
	_getch();
}	

void Game::drawItAll() {
	for (int i = 0; i < Init::MAP_HEIGHT; i++) {
		for (int j = 0; j < Init::MAP_WIDTH; j++) {
			if (map.tileMap[i][j] == ' ') { map.sprite.setTextureRect(IntRect(0, 0, Init::TILE_SIZE, Init::TILE_SIZE)); }
			if (map.tileMap[i][j] == 's') { map.sprite.setTextureRect(IntRect(Init::TILE_SIZE, 0, Init::TILE_SIZE, Init::TILE_SIZE)); }
			if (map.tileMap[i][j] == '0') { map.sprite.setTextureRect(IntRect(64, 0, Init::TILE_SIZE, Init::TILE_SIZE)); }
			if (map.tileMap[i][j] == 'f') { map.sprite.setTextureRect(IntRect(96, 0, Init::TILE_SIZE, Init::TILE_SIZE)); }
			map.sprite.setPosition(j * Init::TILE_SIZE, i * Init::TILE_SIZE);
			window.draw(map.sprite);
		}
	}
	for (int i = 0; i < racersNum; i++) {
		window.draw(racers[i]->getSprite());
	}
	text.setString("");
	for (int i = 0; i < racersNum; i++) {
		std::ostringstream racersEnergy;
		racersEnergy << racers[i]->getEnergy();
		text.setString(text.getString() + racers[i]->getType() + ": " + racersEnergy.str()+" ");
	}
	text.setPosition(Init::TILE_SIZE, Init::TILE_SIZE*5);
	window.draw(text);
}

void Game::moveThemAll() {
	float speed = 0.1;
	static int i = 0;
	if ((racers[i]->getPos() > racers[i]->point + 5) || (racers[i]->getPos() < racers[i]->point - 5)) {
		racers[i]->moveToPoint(racers[i]->point, racers[i]->getYpos(), time);
	}else {
		racers[i]->point += racers[i]->defMove() * 10;
		correct(&(racers[i]->point));
		if (i == racersNum-1) {i = 0;}else {++i;}
		if (racers[i]->getEnergy() <= 0) {
			racers[i]->setEnergy(20);
			if (i == racersNum - 1) { i = 0; }else { ++i; }
		}
	}
}

void Game::correct(int* val) {
	if (*val < 0) {
		*val = 0;
	}else if (*val > Init::FINISH_LINE) {
		*val = Init::FINISH_LINE;
	}
}

void Game::endMessage() {
	Text congratulationsText;
	congratulationsText.setFont(font);
	congratulationsText.setFillColor(Color::Red);
	congratulationsText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	congratulationsText.setPosition(Init::MAP_WIDTH/2, Init::MAP_HEIGHT/2);
	congratulationsText.setString(winner->getType() + " win");
	text.scale(2, 2);
	window.draw(congratulationsText);
}

void Game::interactionWithMap() {
	for (int k = 0; k < racersNum; ++k) {
		int i = 3;
		for (int j = racers[k]->getPos() / Init::TILE_SIZE; j < (racers[k]->getPos() + Init::TILE_SIZE) / Init::TILE_SIZE; j++) {
			if (map.tileMap[i][j] == 's') {
				racers[k]->setEnergy(racers[k]->getEnergy()+5);
				map.tileMap[i][j] = ' ';
			}else if (map.tileMap[i][j] == 'f') {
				winner = racers[k];
				gameOver = true;
			}
		}
	}
}