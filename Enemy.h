#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include "src/rsdl.hpp"
#include "Defines.h"
#include "Mario.h"
class Enemy {
public:
	Enemy(std::vector<std::string> map);
	bool BesidesClearGomba(std::vector<std::string> map, int i);
	bool BesidesClearGombaTrompa(std::vector<std::string> map, int i);
	bool canFall(std::vector<std::string> map, int i);
	bool canFallRed(std::vector<std::string> map, int i);
	bool canMove(std::vector<std::string> map, int i);
	bool MarioEatsMushroom(int i,Mario* mario);
	bool MarioEatsMushroomRed(int i,Mario* mario);
	bool GombaEatsMario(int i,Mario* mario);
	bool GombaTrompaEatsMario(int i,Mario* mario);
	bool MarioEatsGomba(int i,Mario* mario);
	bool canFallGomba(std::vector<std::string> map,int i);
	bool MushroomHasLife(int i);
	bool GombaTaccidentX(int i);
	bool GombaAccidentX(int i);
	bool GombaLife(int i);
	bool canFallGombaTrompa(std::vector<std::string> map,int i);
	bool MarioIsSmall(Mario* mario){ return mario->WhatsSize1()==0; }
	bool canMoveRed(std::vector<std::string> map, int i);
	bool MushroomRedHasLife(int i);
	int WhatsVxGomba(int i);
	int WhatsVxGombaTrompa(int i);
	int WhatsGombaX(int i);
	int WhatsGombaTrompaX(int i);
	int WhatsGombaY(int i);
 	int WhatsGombaTrompaY(int i);
	int WhatsMushroomX(int i);
	int WhatsMushroomY(int i);
	int WhatsMushroomRedY(int i);
	int WhatsMushroomRedX(int i);
	int direcionOfGomba(int i){ return directionGomba[i]; }
	int direcionOfGombaTrompa(int i){ return directionGombaTrompa[i]; }
	void MinusLifeMushroom(int i){ MushroomLive[i]=0; }
	void MinusLifeMushroomRed(int i){ MushroomRedLive[i]=0; }
	void MinusNumAccidentGomba(int i){ gombaAccident[i]=0; }
	void MinusNumAccidentGombaTrompa(int i){ gombaTrompaAccident[i]=0; }
	void MinsGombaLife(int i){ gombaLive[i] = 0;}
	void DeltaFallMushY(int i) { VyMushroom[i] -=1; }
	void DeltaFallMushRedY(int i){ VyMushroomRed[i]-=1; }
	void DeltaFallGombaY(int i){ VyGomba[i]-=1; }
	void DeltaFallGombaTrompaY(int i){ VyGombaTrompa[i]-=1; }
	void showGombas(Window& win,int& camera,std::vector<std::string>& map,
		std::string str,std::string str2,Mario* mario);
	void setZerVyMushroom(int i){
		VyMushroom[i]=0;
		Mushrooms[i].y-=Mushrooms[i].y%MARIOSIZE;
	}
	void setZeroVyMushroomRed(int i){ 
		VyMushroomRed[i]=0;
		MushroomsRed[i].y-=MushroomsRed[i].y%MARIOSIZE;
	}
	void setZeroVyGomba(int i){
		VyGomba[i]=0; 
 		posGombas[i].y-=posGombas[i].y%MARIOSIZE;
}
	void setZeroVyGombaTrompa(int i){ VyGombaTrompa[i]=0; }
	void pushBackMushroom(int x, int y);
	void pushBackMushroomRed(int x, int y);
	void ChangeMarioSize(Mario* mario){	mario->ChangeSize(); }
	void redMushroom(std::vector<std::string> map,Mario* mario,
		int& camera,Window& win);
	void mushroom(Window& win,std::vector<std::string> map,
		int& camera,Mario* mario);
	void gombatrompa(int& camera,std::vector<std::string> map,Mario* mario,
		std::string str2,Window& win);
	void gomba(Window& win,int& camera,Mario* mario,std::string str,
		std::vector<std::string> map);
	std::vector<Rectangle> posGombas;
	std::vector<Rectangle> posGombaTrompa;
private:
	std::vector<int> directionGomba;
	std::vector<int> directionGombaTrompa;
	std::vector<int> VxGomba;
	std::vector<int> VxGombaTrompa;
	std::vector<int> VyGomba;
	std::vector<int> VyGombaTrompa;
	std::vector<int> VxMushroom;
	std::vector<int> VyMushroom;
	std::vector<Rectangle> Mushrooms;
	std::vector<int> directionMushroom;
	std::vector<int> MushroomLive;
	std::vector<int> gombaAccident;
	std::vector<int> gombaTrompaAccident;
	std::vector<int> gombaLive;
	std::vector<int> gombaTrompaLive;
	std::vector<Rectangle> MushroomsRed;
	std::vector<int> VxMushroomRed;
	std::vector<int> VyMushroomRed;
	std::vector<int> directionMushroomRed;
	std::vector<int> MushroomRedLive;
};

bool Enemy::GombaLife(int i){
	return gombaLive[i] == 1;
}

bool Enemy::GombaAccidentX(int i){
	return gombaAccident[i] == 1;
}

bool Enemy::GombaTaccidentX(int i){
	return gombaTrompaAccident[i] == 1;
}

bool Enemy::MushroomHasLife(int i){
	return MushroomLive[i] == 1;
}

bool Enemy::MushroomRedHasLife(int i){
	return MushroomRedLive[i] == 1;
}

bool Enemy::MarioEatsGomba(int i,Mario* mario){
	return abs(mario->WhatsX() - WhatsGombaX(i)) <= MARIOSIZE/7
	&& mario->WhatsY() - (mario->WhatsSize1()*MARIOSIZE) - WhatsGombaY(i) == MARIOSIZE;
}

bool Enemy::GombaEatsMario(int i,Mario* mario){
	return abs(mario->posMario.x - posGombas[i].x) <= MARIOSIZE
	&& abs(mario->WhatsY() -(mario->WhatsSize1()*MARIOSIZE) - posGombas[i].y) <= mario->WhatsSize1()*MARIOSIZE;
}

bool Enemy::GombaTrompaEatsMario(int i,Mario* mario){
	return abs(mario->posMario.x - posGombaTrompa[i].x) == MARIOSIZE
	&& abs(mario->WhatsY() -(mario->WhatsSize1()*MARIOSIZE) - posGombaTrompa[i].y) <= MARIOSIZE/7;
}

bool Enemy::MarioEatsMushroom(int i,Mario* mario){
	return abs(mario->WhatsX() - Mushrooms[i].x) <= MARIOSIZE
	&& abs(mario->WhatsY() - (mario->WhatsSize1()*MARIOSIZE)- Mushrooms[i].y) <= MARIOSIZE;
}

bool Enemy::MarioEatsMushroomRed(int i,Mario* mario){
	return abs(mario->WhatsX() - MushroomsRed[i].x) <= MARIOSIZE
	&& abs(mario->WhatsY()- (mario->WhatsSize1()*MARIOSIZE) - MushroomsRed[i].y) <= MARIOSIZE;
}

void Enemy::pushBackMushroom(int x, int y){
	Mushrooms.push_back(Rectangle(x,y,MARIOSIZE,MARIOSIZE));
	VxMushroom.push_back(1);
	VyMushroom.push_back(0);
	directionMushroom.push_back(1);
	MushroomLive.push_back(1);
}

void Enemy::pushBackMushroomRed(int x, int y){
	MushroomsRed.push_back(Rectangle(x,y,MARIOSIZE,MARIOSIZE));
	VxMushroomRed.push_back(1);
	VyMushroomRed.push_back(0);
	directionMushroomRed.push_back(1);
	MushroomRedLive.push_back(1);
}

int Enemy::WhatsMushroomY(int i){
	Mushrooms[i].y-=VyMushroom[i];
	return Mushrooms[i].y;
}

int Enemy::WhatsMushroomRedY(int i){
	MushroomsRed[i].y-=VyMushroomRed[i];
	return MushroomsRed[i].y;
}

int Enemy::WhatsMushroomX(int i){
	Mushrooms[i].x += VxMushroom[i];
	return Mushrooms[i].x;
}

int Enemy::WhatsMushroomRedX(int i){
	MushroomsRed[i].x += VxMushroomRed[i];
	return MushroomsRed[i].x;
}

int Enemy::WhatsGombaX(int i){
	posGombas[i].x+=VxGomba[i];
	return posGombas[i].x;
}

int Enemy::WhatsGombaY(int i){
	posGombas[i].y-=VyGomba[i];
	return posGombas[i].y;
}

int Enemy::WhatsGombaTrompaX(int i){
	posGombaTrompa[i].x+=VyGombaTrompa[i];
	return posGombaTrompa[i].x;
}
int Enemy::WhatsGombaTrompaY(int i){
	posGombaTrompa[i].y-=VyGombaTrompa[i];
	return posGombaTrompa[i].y;
}

bool Enemy::BesidesClearGomba(std::vector<std::string> map, int i){
	return map[(WhatsGombaY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[WhatsGombaX(i)/MARIOSIZE + 1] == SPACE 
	&& map[(WhatsGombaY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
	[WhatsGombaX(i)/MARIOSIZE + 1] == SPACE;
}  


bool Enemy::BesidesClearGombaTrompa(std::vector<std::string> map, int i){
	return map[(WhatsGombaTrompaY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[WhatsGombaTrompaX(i)/MARIOSIZE + 1] == SPACE 
	&& map[(WhatsGombaTrompaY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
	[WhatsGombaTrompaX(i)/MARIOSIZE + 1] == SPACE;
}  

int Enemy::WhatsVxGomba(int i){
	return VxGomba[i];
}

int Enemy::WhatsVxGombaTrompa(int i){
	return VxGombaTrompa[i];
}

Enemy::Enemy(std::vector<std::string> map){
	for (int j=0;j<map[0].size();j++){
		for (int i=0;i<map.size();i++){
			if (map[i][j]==GOMBA){
				posGombas.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
				directionGomba.push_back(1);
				VxGomba.push_back(1);
				VyGomba.push_back(0);
				gombaAccident.push_back(1);
				gombaLive.push_back(1);
			}
			if (map[i][j]==GOMBATROMPA){
				posGombaTrompa.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
				directionGombaTrompa.push_back(1);
				VxGombaTrompa.push_back(1);
				VyGombaTrompa.push_back(0);
				gombaTrompaAccident.push_back(1);
				gombaTrompaLive.push_back(1);
			}
		}
	}
}

void Enemy::showGombas(Window& win,int& camera,std::vector<std::string>& map,std::string str,
	std::string str2,Mario* mario){
	delay(3);
	gomba(win,camera,mario,str,map);
	gombatrompa(camera,map,mario,str2,win);	
	mushroom(win,map,camera,mario);
	redMushroom(map,mario,camera,win);
}

void Enemy::gomba(Window& win,int& camera,Mario* mario,std::string str,std::vector<std::string> map){
	for (int i = 0; i < posGombas.size(); i++){
		if (posGombas[i].x - camera < WIDTH){
			if (GombaAccidentX(i)){
				if (canFallGomba(map,i))
					DeltaFallGombaY(i);
				else
					setZeroVyGomba(i);	
				if (!BesidesClearGomba(map,i)){
					directionGomba[i]*=-1;
					VxGomba[i]*=-1;
				}
				if (GombaEatsMario(i,mario)){
					if (!mario->gameIsOver()){
						if (MarioIsSmall(mario)){
							mario->MinusLifes();
							MinusNumAccidentGomba(i);
							win.pause_music();
							win.play_sound_effect(DEATHSOUND);
							mario->setZeroVx();
							mario->setZeroVy();
							delay(4000);
							win.resume_music();
							camera=0;
							mario->firstXY();
						}
						else
							ChangeMarioSize(mario);				
				}
				else{
					mario->GameOver(win);
					exit(0);
				}				
			}
				if (MarioEatsGomba(i,mario)){

				}
			}	
			win.draw_img(str, Rectangle(WhatsGombaX(i) - camera, WhatsGombaY(i),
			MARIOSIZE, MARIOSIZE));
		}
	}
}

void Enemy::mushroom(Window& win,std::vector<std::string> map,int& camera,Mario* mario){
	for (int i = 0; i < Mushrooms.size(); i++){
		if (MushroomHasLife(i)){
			if (canFall(map,i))
				DeltaFallMushY(i);
			else
				setZerVyMushroom(i);
			if (!canMove(map,i)){
				directionMushroom[i]*=-1;
				VxMushroom[i]*=-1;
			}
			if (MarioEatsMushroom(i,mario)){
				win.play_sound_effect(POWERUP);
				mario->addLifes();
				MinusLifeMushroom(i);
			}
			win.draw_img(MUSHROOMHEALTH,Rectangle(WhatsMushroomX(i) - camera,Mushrooms[i].y,
			MARIOSIZE, MARIOSIZE));	
		}	
	}
}

void Enemy::redMushroom(std::vector<std::string> map,Mario* mario,int& camera,Window& win){
	for (int i = 0;i< MushroomsRed.size();i++){
		if (MushroomRedHasLife(i)){
			if (canFallRed(map,i))
				DeltaFallMushRedY(i);
			else
				setZeroVyMushroomRed(i);
			if(!canMoveRed(map,i)){
				directionMushroomRed[i]*=-1;
				VxMushroomRed[i]*=-1;
			}
			if (MarioEatsMushroomRed(i,mario) && mario->isSmall()){
				MinusLifeMushroomRed(i);
				win.play_sound_effect(POWERUP);
				ChangeMarioSize(mario);
			}
			win.draw_img(MUSHROOMRED,Rectangle(WhatsMushroomRedX(i) - camera,MushroomsRed[i].y,
			MARIOSIZE, MARIOSIZE));	
		}		
	}
}

void Enemy::gombatrompa(int& camera,std::vector<std::string> map,Mario* mario,std::string str2,Window& win){
	for (int i = 0; i < posGombaTrompa.size(); i++){
		if (posGombaTrompa[i].x - camera < WIDTH){
			if (GombaTaccidentX(i)){
				if (canFallGombaTrompa(map,i))
					DeltaFallGombaTrompaY(i);
				else
					setZeroVyGombaTrompa(i);
				if (!BesidesClearGombaTrompa(map,i)){
					directionGombaTrompa[i]*=-1;
					VxGombaTrompa[i]*=-1;
				}
				if (GombaTrompaEatsMario(i,mario)){
					mario->MinusLifes();
					MinusNumAccidentGombaTrompa(i);
					win.pause_music();
					win.play_sound_effect(DEATHSOUND);
				}
			}
		}
		win.draw_img(str2,Rectangle(WhatsGombaTrompaX(i) - camera,posGombaTrompa[i].y,
		MARIOSIZE, MARIOSIZE));
	}
}


bool Enemy::canFall(std::vector<std::string> map,int i){
	return map[(WhatsMushroomY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
	[WhatsMushroomX(i)/MARIOSIZE] == SPACE;
}

bool Enemy::canFallRed(std::vector<std::string> map,int i){
	return map[(WhatsMushroomRedY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
	[WhatsMushroomRedX(i)/MARIOSIZE] == SPACE;
}

bool Enemy::canFallGomba(std::vector<std::string> map,int i){
	return map[(WhatsGombaY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
	[WhatsGombaX(i)/MARIOSIZE] == SPACE;
}

bool Enemy::canFallGombaTrompa(std::vector<std::string> map,int i){
	return map[(WhatsGombaTrompaY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 1]
	[WhatsGombaTrompaX(i)/MARIOSIZE] == SPACE;
}

bool Enemy::canMove(std::vector<std::string> map, int i){
	return map[(WhatsMushroomY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[WhatsMushroomX(i)/MARIOSIZE + 1] == SPACE 
	&& map[(WhatsMushroomY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
	[WhatsMushroomX(i)/MARIOSIZE + 1] == SPACE;
}

bool Enemy::canMoveRed(std::vector<std::string> map, int i){
	return map[(WhatsMushroomRedY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[WhatsMushroomRedX(i)/MARIOSIZE + 1] == SPACE 
	&& map[(WhatsMushroomRedY(i) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE]
	[WhatsMushroomRedX(i)/MARIOSIZE + 1] == SPACE;
}
#endif