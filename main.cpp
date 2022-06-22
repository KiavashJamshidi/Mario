#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include "src/rsdl.hpp"
#include "Defines.h"
#include "Enemy.h"
#include "Mario.h"
#include "Ground.h"
#include "Functions.h"

using namespace std;

int main(int argc,char* argv[]){
	vector<string> mapVector;
	saveFromMap(mapVector,argv[1]);
	Window win(WIDTH,HEIGHT,TOPIC);
	win.play_music(MUSIC);
	Ground ground(mapVector);
	Enemy enemy(mapVector);
	Mario mario(mapVector);
	int Camera = 0, Right = 1, Ques = 0;
	char press;
	updateMap(mapVector);
	while (true){
		if (!ground.levelClear(&mario)){
			if (!mario.gameIsOver()){
				Ques = 0;
				press = 0;
				KeyPress(win,press);
				if (press == QUIT)
					return 0;				
				if (press == 0)
					ground.Stand(&mario,win,Camera,mapVector,&enemy,Right,Ques);
				if (press == JUMP){
					ground.JumpFunc(&mario,Camera,win,mapVector,Right,&enemy,Ques,press);
				}
				if (press == RIGHT){
					Right=1;
					ground.MoveRightLeft(win,&mario,&enemy,Camera,Ques,Right,mapVector);
				}
				if (press == LEFT){
					Right=0;
					ground.MoveRightLeft(win,&mario,&enemy,Camera,Ques,Right,mapVector);
				}
			}
			else
				mario.GameOver(win);		
		}
		else
			mario.clearLevel(win);
	}
}