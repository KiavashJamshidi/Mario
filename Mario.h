#ifndef MARIO_H
#define MARIO_H

#include <vector>
#include <string>
#include "src/rsdl.hpp"
#include "Defines.h"

class Mario{
public:
	Mario(std::vector<std::string> map);
	void showMario(Window& win,int& camera, std::string str);
	void Vxincrease(int dir);
	void setZeroVx();
	void setZeroVy();
	void MinusVx();
	void Jump(){ Vy=10; }
	void JumpBig(){ Vy=2; }
	void addVy(){ Vy+=2; }
	void DeltaVyJump(){	Vy -=1;	}
	void addCoin() { coins++; }
	void MinusLifes(){ marioLifes--; }	
	void Fall() { Vy = 0; }
	void DeltaVyFall(){ Vy -= 10; }
	void DeltaVyFallBig(){ Vy-=3; }
	void GameOver(Window& win);
	void showPointsLives(Window& win,int coins,int marioLifes);
	void ChangeSize();
	void clearLevel(Window& win);
	void firstXY();
	int WhatsSize1(){ return size1; }
	int WhatsSize2(){ return size2; }
	int WhatsVx();
	int WhatsVy();
	int WhatsX();
	int WhatsY();
	int Lifes(){ return marioLifes; }
	int Coins(){ return coins; }
	int addLifes(){	marioLifes++;  }
	bool MarioHalf();
	bool gameIsOver(){ return marioLifes==0; }
	bool canFall(std::vector<std::string> map);
	bool UpIsClear(std::vector<std::string> map);
	bool DownIsClear(std::vector<std::string> map);
	bool BesidesClear(std::vector<std::string> map, int dir);
	bool FallDie(std::vector<std::string> map); 
	bool BesidesClearJump(std::vector<std::string> map, int dir);
	bool isSmall(){ return size1 == 0; }
	Rectangle posMario = Rectangle(1000,300,MARIOSIZE,MARIOSIZE);
private:
	int x;
	int y;
	int Vx = 0;
	int Vy = 0;
	int Ax;
	int coins = 0;
	int marioLifes = 3;
	int size1=0;
	int size2=1;
	int savex;
	int savey;
};

void Mario::setZeroVy(){
	Vy = 0;
	posMario.y-=(posMario.y - (size1*MARIOSIZE))%MARIOSIZE;
}

void Mario::ChangeSize(){
	if (size1==0){
		size1=1;
		size2=2;
	}
	else {
		size1=0;
		size2=1;
	}
}

void Mario::clearLevel(Window& win){
	win.clear();
	win.show_text("YOU WIN!", Point(250, 330), WHITE, FONT , 110);
	win.pause_music();
	win.play_sound_effect(LEVELCLEAR);
	win.update_screen();
	delay(6000);
	exit(0);
}


void Mario::firstXY(){
	posMario.x=savex;
	posMario.y=savey;
}

void Mario::GameOver(Window& win){
	win.clear();
	win.show_text(GAMEOVER, Point(250, 330), WHITE, FONT , 110);
	win.pause_music();
	win.play_sound_effect(GAMEOVERSOUND);
	win.update_screen();
	delay(6000);
	exit(0);
}


bool Mario::FallDie(std::vector<std::string> map){ 
	return posMario.y - (size1*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE + 1 == map.size();
}

bool Mario::BesidesClearJump(std::vector<std::string> map, int dir){
	if (dir == 1)
		return (map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
		[WhatsX()/MARIOSIZE + 1] == SPACE)
		|| (map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
		[WhatsX()/MARIOSIZE + 1] == SPACE)
		|| (map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
		[WhatsX()/MARIOSIZE + 1] == SPACE);
	else
		return (map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
		[WhatsX()/MARIOSIZE - 1] == SPACE)
		|| (map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
		[WhatsX()/MARIOSIZE - 1] == SPACE)
		|| (map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
		[WhatsX()/MARIOSIZE - 1] == SPACE);				
}


void Mario::showPointsLives(Window& win,int coins,int marioLifes){
	win.show_text("COINS", Point(480, 27), WHITE, FONT , 25);
	win.show_text(std::to_string(coins), Point(513, 60), WHITE, FONT , 25);
	win.show_text("LIVES", Point(580, 27), WHITE, FONT , 25);
	win.show_text(std::to_string(marioLifes), Point(607, 60), WHITE, FONT , 25);
}

bool Mario::BesidesClear(std::vector<std::string> map, int dir){
	if (dir == 1)
		return (map[(posMario.y- (size1*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
		[WhatsX()/MARIOSIZE + 1] == SPACE);
	else
		return (map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
		[WhatsX()/MARIOSIZE - 1] == SPACE);
}


bool Mario::UpIsClear(std::vector<std::string> map){
	if(((posMario.y - (size1*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1)<1){
		return true;
	}
	return map[(posMario.y - (size1*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[WhatsX()/MARIOSIZE + 1]==SPACE 
	&&map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[WhatsX()/MARIOSIZE] == SPACE;
}

bool Mario::DownIsClear(std::vector<std::string> map){
	if(((posMario.y+size1*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1!=map.size()){
		posMario.y-=size1*MARIOSIZE;
		return map[(posMario.y- (size1*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
		[WhatsX()/MARIOSIZE] == SPACE;
	}
}

bool Mario::canFall(std::vector<std::string> map){
	return map[(posMario.y - (size1*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
	[WhatsX()/MARIOSIZE] == SPACE;
}

Mario::Mario(std::vector<std::string> map) {
	for (int i = 0;i < map.size(); i++)
		for (int j = 0; j < 100; j++)
			if(map[i][j]==MARIOO){
				posMario=Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE);
				savex = j*MARIOSIZE;
				savey = HEIGHT - MARIOSIZE*(map.size() - i);	
			}
}


void Mario::showMario(Window& win, int& camera, std::string str){
	showPointsLives(win,coins,marioLifes);
	 if (posMario.x - camera > WIDTH / 2)
		 camera = posMario.x - WIDTH / 2;
	win.draw_img(str,Rectangle(WhatsX() - camera, WhatsY()- (size1*MARIOSIZE),
		MARIOSIZE, size2*MARIOSIZE));
}

void Mario::Vxincrease(int dir){
	if (dir == 1) {
		if (Vx >= 2)
			Vx = 2;
		Vx+=2;
	}
	else {
		if (Vx<=-2)
			Vx=-2;
		Vx-=2;		
	}	
}	

void Mario::setZeroVx(){ Vx = 0;}

bool Mario::MarioHalf(){ return posMario.x >= WIDTH/2 - 120; }

int Mario::WhatsVx(){ return Vx; }

int Mario::WhatsVy() { return Vy; }

int Mario::WhatsX(){
	posMario.x = posMario.x + WhatsVx();
	return posMario.x;
}

int Mario::WhatsY(){
	posMario.y = posMario.y - WhatsVy();
	return posMario.y;
}

void Mario::MinusVx(){
	if (Vx == 0)
		return;
	Vx-=2;	
}
#endif