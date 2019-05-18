#include "Game.h"
#include "Init.h"
#include <iostream>
#include <sstream>
#include <conio.h>

Game::Game() {
	window.create(sf::VideoMode(1600, 768), "it's only testing");
	racersNum = 2;
	racers = new Animal*[racersNum];
	racers[0] = new Hare;
	racers[1] = new Turtle;
	gameOver = false;
	winner = nullptr;

	font.loadFromFile("images/calibrili.ttf");
	text.scale(0.5, 0.5);
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
		//main logic
		//Animal* finisher = whoFinished();
		moveThemAll();
		interactionWithMap();
		/*if (finisher != nullptr) {
			break;
		}*/

		window.clear();
		drawItAll();
		window.display();
	}
	endMessage();
	window.clear();
	drawItAll();
	window.display();
	_getch();
}	

void Game::drawItAll() {
	for (int i = 0; i < Init::MAP_HEIGHT; i++) {
		for (int j = 0; j < Init::MAP_WIDTH; j++) {
			if (map.tileMap[i][j] == ' ') { map.sprite.setTextureRect(IntRect(0, 0, 32, 32)); }
			if (map.tileMap[i][j] == 's') { map.sprite.setTextureRect(IntRect(32, 0, 32, 32)); }
			if (map.tileMap[i][j] == '0') { map.sprite.setTextureRect(IntRect(64, 0, 32, 32)); }
			if (map.tileMap[i][j] == 'f') { map.sprite.setTextureRect(IntRect(96, 0, 32, 32)); }
			map.sprite.setPosition(j * 32, i * 32);
			window.draw(map.sprite);
		}
	}
	for (int i = 0; i < racersNum; i++) {
		window.draw(racers[i]->getSprite());
	}
	//text
	text.setString("");
	for (int i = 0; i < racersNum; i++) {
		std::ostringstream racersEnergy;
		racersEnergy << racers[i]->getEnergy();
		text.setString(text.getString() + racers[i]->getType() + ": " + racersEnergy.str()+" ");
		std::cout << racers[i]->getType() + ": " + racersEnergy.str() + " " << std::endl;
	}
	text.setPosition(32, 128);
	window.draw(text);
}

void Game::moveThemAll() {
	float speed = 0.1;
	static int i = 0;
	if (racers[i]->getPos() > racers[i]->point + 0.1 || racers[i]->getPos() < racers[i]->point - 0.1) {
		racers[i]->moveToPoint(racers[i]->point, 0, time); 
	}else {
		racers[i]->point += racers[i]->defMove() * 10;
		correct(&(racers[i]->point));
		if (i == racersNum-1) {i = 0;}else {++i;}
		if (racers[i]->getEnergy() <= 0) {
			racers[i]->setEnergy(20);
			if (i == racersNum - 1) { i = 0; }
			else { ++i; }
		}
	}
}

Animal* Game::whoFinished() {
	for (int i = 0; i < racersNum; i++) {
		if (racers[i]->getPos() + 0.1 >= 1000) {
			return racers[i];
		}else {
			return nullptr;
		}
	}
}

void Game::correct(int* val) {
	if (*val < 0) {
		*val = 0;
	}else if (*val > 1248) {
		*val = 1248;
	}
}

void Game::endMessage() {
	Text congratulationsText;
	congratulationsText.setFont(font);
	congratulationsText.setFillColor(Color::Red);
	congratulationsText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	congratulationsText.setPosition(400, 96);
	congratulationsText.setString(winner->getType() + " win");
	std::cout << "That's all" << std::endl;
}

void Game::interactionWithMap() {
	for (int k = 0; k < racersNum; ++k) {
		int i = 2;
		for (int j = racers[k]->getPos() / 32; j < (racers[k]->getPos() + 32) / 32; j++) {
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