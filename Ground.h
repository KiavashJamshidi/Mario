#ifndef GROUND_H
#define GORUND_H

#include <vector>
#include <string>
#include <iostream>
#include "src/rsdl.hpp"
#include "Enemy.h"
#include "Mario.h"
#include "Functions.h"

class Ground{
public:
	Ground(std::vector<std::string> map);
	bool IsEnything(std::vector<std::string> map,Mario* mario,char ch);
	bool levelClear(Mario* mario){return mario->posMario.x + 2*MARIOSIZE == posFlag[0].x; }
	void showClaysBlocks(Window& win,int& camera);
	void showBricks(Window& win,int& camera);
	void showPipe(Window& win,int& camera);
	void showQuestions(Window& win,int& camera,std::string str);
	void showMarioStand(Window& win,int& camera,Enemy* enemy,
	Mario* mario, int r,std::vector<std::string> map);
	void showFlag(Window& win,int& camera);
	void showObstcales(Window& win,int& camera, std::string str);
	void showMarioMove(Window& win,int& camera,Enemy* enemy, Mario* mario,
	 int r,std::vector<std::string> map);
	void showMarioJump(Window& win,int& camera,Enemy* enemy, Mario* mario,
	 int r,std::vector<std::string> map, int& Q);
	void showCoin(Mario* mario,Window& win,int& camera);
	void SetCoinY(Mario* mario);
	void DeltaCoinY();
	void showCoins(Window& win,Mario* mario,int& camera);
	void showDeadQuestion(int& camera,Window& win);
	void pushbackDeadQuestion(std::vector<std::string> map);
	void MoveRightLeft(Window& win,Mario* mario,Enemy* enemy, int& Camera,
		int& Ques,int& Right,std::vector<std::string> map);
	void QuestionToEmpty(std::vector<std::string>& map,Mario* mario,char str1,char str2);
	int WhatsClayY (int i) { return posClay[i].y; }
	void Stand(Mario* mario,Window& win,int& Camera,std::vector<std::string> map,
		Enemy* enemy,int& Right,int& Ques);
	void JumpFunc(Mario* mario,int& Camera,Window& win,std::vector<std::string> map,int& Right,
		Enemy* enemy,int& Ques,char& press);
	void questionCoin(Mario* mario,std::vector<std::string> map,Window& win,int& Ques);
	void questionHealth(std::vector<std::string> map,Mario* mario,Window& win,Enemy* enemy);
	void questionRed(Window& win,std::vector<std::string> map,Mario* mario,Enemy* enemy);
	void brick(Window& win,Mario* mario,std::vector<std::string> map);
	void EverywhereEmpty(Mario* mario,Enemy* enemy,int& camera,
		std::vector<std::string> map,int& Right,Window& win,int& Ques);
	std::vector<Rectangle> posQuestionCoin;
private:
	std::vector<Rectangle> posClay;
	std::vector<Rectangle> posBlock;
	std::vector<Rectangle> posBrick;
	std::vector<Rectangle> posQuestionRed;
	std::vector<Rectangle> posQuestionHealth;
	std::vector<Rectangle> posPipe;
	std::vector<Rectangle> posFlag;
	std::vector<Rectangle> posDeadQuestion;
	std::vector<Rectangle> posDeadHealthQuestion;
	std::vector<Rectangle> posDeadRedQuestion;
	int y;
};

bool Ground::IsEnything(std::vector<std::string> map,Mario* mario,char ch){
	return map[(mario->posMario.y -(mario->WhatsSize1()*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[mario->WhatsX()/MARIOSIZE] == ch
	||  map[(mario->posMario.y -(mario->WhatsSize1()*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[mario->WhatsX()/MARIOSIZE + 1] == ch;
}


void Ground::QuestionToEmpty(std::vector<std::string>& map,Mario* mario,char str1,char str2){
	if (map[(mario->posMario.y-(mario->WhatsSize1()*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[mario->WhatsX()/MARIOSIZE] == str1)
		map[(mario->posMario.y-(mario->WhatsSize1()*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
		[mario->WhatsX()/MARIOSIZE] = str2;
	if (map[(mario->posMario.y-(mario->WhatsSize1()*MARIOSIZE)- HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
	[mario->WhatsX()/MARIOSIZE + 1] == str1)
		map[(mario->posMario.y-(mario->WhatsSize1()*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1]
		[mario->WhatsX()/MARIOSIZE + 1] = str2;
}

void Ground::pushbackDeadQuestion(std::vector<std::string> map){
	for (int i=0;i<map.size();i++){
		for (int j=0;j<map[i].size();j++){
			if (map[i][j] == QUESTIONDEAD)
				posDeadQuestion.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == QUESTIONHEALTHDEAD)
				posDeadHealthQuestion.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == QUESTIONREDDEAD)
				posDeadRedQuestion.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));		
		}
	}		
}

void Ground::showDeadQuestion(int& camera,Window& win){
	for (int i=0;i<posDeadQuestion.size();i++){
				win.draw_img(DEADQUESTION,Rectangle(posDeadQuestion[i].x - camera,posDeadQuestion[i].y,
				MARIOSIZE, MARIOSIZE));
	}
}

void Ground::showCoins(Window& win, Mario* mario,int& camera){
	win.draw_img(COIN,Rectangle(mario->WhatsX() - camera, y,
		MARIOSIZE, MARIOSIZE));
}

void Ground::SetCoinY(Mario* mario){
	y = mario->posMario.y - (mario->WhatsSize1()*MARIOSIZE) - 2 * MARIOSIZE;
}

void Ground::DeltaCoinY() {
	y-=35;
}

void Ground::showMarioStand(Window& win, int& camera,Enemy* enemy,
 Mario* mario, int r,std::vector<std::string> map){
	showObstcales(win,camera,QUESTION1);
	enemy->showGombas(win,camera,map,GOMBAWALK1,GOMBATROMPAWALKR1,mario);
	if (r == 1)
		mario->showMario(win,camera,STANDRIGHT);
	if (r == 0)	
		mario->showMario(win,camera,STANDLEFT);
	win.update_screen();
	delay(20);
	showObstcales(win,camera,QUESTION2);
	enemy->showGombas(win,camera,map,GOMBAWALK2,GOMBATROMPAWALKR2,mario);
	if (r == 1)
		mario->showMario(win,camera,STANDRIGHT);
	if (r == 0)
		mario->showMario(win,camera,STANDLEFT);
	win.update_screen();
	delay(20);
	showObstcales(win,camera,QUESTION3);
	if (r == 1)
		mario->showMario(win,camera,STANDRIGHT);
	if (r == 0)
		mario->showMario(win,camera,STANDLEFT);
	enemy->showGombas(win,camera,map,GOMBAWALK1,GOMBATROMPAWALKR1,mario);
	win.update_screen();
	delay(20);
}

void Ground::showMarioMove(Window& win,int& camera,Enemy* enemy,
 Mario* mario,int r,std::vector<std::string> map){
	showObstcales(win,camera,QUESTION1);
	enemy->showGombas(win,camera,map,GOMBAWALK1,GOMBATROMPAWALKR1,mario);
	if (r == 1)
		mario->showMario(win,camera,MOVETORIGHT1);
	if (r == 0)
		mario->showMario(win,camera,MOVETOLEFT1);
	win.update_screen();
	delay(20);
	showObstcales(win,camera,QUESTION2);
	enemy->showGombas(win,camera,map,GOMBAWALK2,GOMBATROMPAWALKR2,mario);
	if (r == 1)
		mario->showMario(win,camera,MOVETORIGHT2);
	if (r == 0)
		mario->showMario(win,camera,MOVETOLEFT2);
	win.update_screen();
	delay(20);
	showObstcales(win,camera,QUESTION3);
	if (r == 1)
		mario->showMario(win,camera,MOVETORIGHT3);
	if (r == 0)
		mario->showMario(win,camera,MOVETOLEFT3);
	enemy->showGombas(win,camera,map,GOMBAWALK1,GOMBATROMPAWALKR1,mario);
	win.update_screen();
	delay(20);
}

void Ground::showMarioJump(Window& win,int& camera,Enemy* enemy,
 Mario* mario, int r,std::vector<std::string> map, int& Q){
	showObstcales(win,camera,QUESTION1);
	enemy->showGombas(win,camera,map,GOMBAWALK1,GOMBATROMPAWALKR1,mario);
	if (r == 1)
		mario->showMario(win,camera,JUMPRIGHT);
	if (r == 0)
		mario->showMario(win,camera,JUMPLEFT);
	if (Q==1){
		showCoins(win,mario,camera);
		DeltaCoinY();
		Q=0;
	}	
	win.update_screen();
	delay(20);
	showObstcales(win,camera,QUESTION2);
	enemy->showGombas(win,camera,map,GOMBAWALK2,GOMBATROMPAWALKR2,mario);
	if (r == 1)
		mario->showMario(win,camera,JUMPRIGHT);
	if (r == 0)
		mario->showMario(win,camera,JUMPLEFT);	
	if (Q==1){
		showCoins(win,mario,camera);
		DeltaCoinY();
		Q=0;
	}	
	win.update_screen();
	delay(20);
	showObstcales(win,camera,QUESTION3);
	if (r == 1)
		mario->showMario(win,camera,JUMPRIGHT);
	if (r == 0)
		mario->showMario(win,camera,JUMPLEFT);	
	if (Q==1){
		showCoins(win,mario,camera);
		DeltaCoinY();
		Q=0;
	}	
	enemy->showGombas(win,camera,map,GOMBAWALK1,GOMBATROMPAWALKR1,mario);
	win.update_screen();
	delay(20);
}

void Ground::showQuestions(Window& win,int& camera,std::string str){
	for (int i = 0; i < posQuestionCoin.size(); i++)
		win.draw_img(str,Rectangle(posQuestionCoin[i].x - camera,posQuestionCoin[i].y,
		MARIOSIZE, MARIOSIZE));
	for (int i = 0; i < posQuestionRed.size(); i++)
		win.draw_img(str,Rectangle(posQuestionRed[i].x - camera,posQuestionRed[i].y,
		MARIOSIZE, MARIOSIZE));
	for (int i = 0; i < posQuestionHealth.size(); i++)
		win.draw_img(str,Rectangle(posQuestionHealth[i].x - camera,posQuestionHealth[i].y,
		MARIOSIZE, MARIOSIZE));
}

void Ground::showFlag(Window& win,int& camera){
	 for (int i=0;i<posFlag.size();i++){
			win.draw_img(FLAGHEAD,Rectangle(posFlag[i].x - camera,posFlag[i].y,
		MARIOSIZE, MARIOSIZE));

		for (int j=1;j<posFlag[i].h/MARIOSIZE;j++){
			win.draw_img(FLAGBODY,Rectangle(posFlag[i].x - camera,posFlag[i].y+MARIOSIZE*j,
			MARIOSIZE, MARIOSIZE));
		}
	 }
}

void Ground::showBricks(Window& win,int& camera){
	for (int i = 0; i < posBrick.size(); i++)
		win.draw_img(BRICKINPUT,Rectangle(posBrick[i].x - camera,posBrick[i].y,
		MARIOSIZE, MARIOSIZE));
}

void Ground::showPipe(Window& win,int& camera){
	for (int i = 0; i < posPipe.size(); i++){
		win.draw_img(PIPE_HEAD_LEFT_INPUT,Rectangle(posPipe[i].x - camera,posPipe[i].y,
		MARIOSIZE, MARIOSIZE));
		win.draw_img(PIPE_HEAD_RIGHT_INPUT,Rectangle(posPipe[i].x+MARIOSIZE - camera,posPipe[i].y,
		MARIOSIZE, MARIOSIZE));
		for(int j=1;j<posPipe[i].h/MARIOSIZE;j++){
			win.draw_img(PIPERIGHTINPUT,Rectangle(posPipe[i].x+MARIOSIZE - camera,posPipe[i].y+MARIOSIZE*j,
			MARIOSIZE, MARIOSIZE));
			win.draw_img(PIPELEFTINPUT,Rectangle(posPipe[i].x - camera,posPipe[i].y+MARIOSIZE*j,
			MARIOSIZE, MARIOSIZE));
		}
	}
}

void Ground::showClaysBlocks(Window& win,int& camera){
	for (int i = 0; i < posClay.size(); i++)
		win.draw_img(CLAYINPUT,Rectangle(posClay[i].x - camera,posClay[i].y,
		MARIOSIZE, MARIOSIZE));

	for (int i = 0; i < posBlock.size(); i++)
		win.draw_img(BLOCKINPUT,Rectangle(posBlock[i].x - camera,posBlock[i].y,
		MARIOSIZE, MARIOSIZE));
}

void Ground::showObstcales(Window& win,int& camera, std::string str){
	showBackground(win,camera);
	showClaysBlocks(win,camera);
	showBricks(win,camera);
	showPipe(win,camera);
	showFlag(win,camera);
	showQuestions(win,camera,str);
	showDeadQuestion(camera,win);
}


Ground::Ground(vector<string> map){
	for (int i=0;i<map.size();i++){
		for (int j=0;j<map[i].size();j++){
			if (map[i][j] == CLAY)
				posClay.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == BLOCK)
				posBlock.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == BRICK)
				posBrick.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == QUESTION)
				posQuestionCoin.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == QUESTIONRED)
				posQuestionRed.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == QUESTIONHEALTH)
				posQuestionHealth.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE));
			if (map[i][j] == PIPE && map[i-1][j]!=PIPE && map[i][j-1]!=PIPE){
				int m = 1;
				while(map[i+m][j]==PIPE){
					m++;
				}
				posPipe.push_back(Rectangle(j * MARIOSIZE,
				HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE*2,MARIOSIZE*m));
			}
			if (map[i][j]==FLAG && map[i-1][j]!=FLAG){
				int x=1;
				while(map[i+x][j]==FLAG)
					x++;
				 posFlag.push_back(Rectangle(j * MARIOSIZE,
					HEIGHT - MARIOSIZE*(map.size() - i),MARIOSIZE,MARIOSIZE*x));	
			}
		}
	}
}

void Ground::MoveRightLeft(Window& win,Mario* mario,Enemy* enemy, int& Camera,int& Ques,int& Right,
std::vector<std::string> map){
	// if ((mario.posMario.y - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE + 2 !=map.size()){
		if (mario->BesidesClear(map,Right)){
			mario->Vxincrease(Right);
			if (mario->canFall(map)){
				// mario->Fall();
				if (mario->isSmall())
					mario->DeltaVyFall();
				else
					mario->DeltaVyFallBig();	
				showMarioJump(win,Camera,enemy,mario,Right,map,Ques);
			}
			else
				showMarioMove(win,Camera,enemy,mario,Right,map);
		}
		else { 
			mario->setZeroVx();
			mario->posMario.x-= mario->posMario.x%MARIOSIZE;
			}
	// }
}

void Ground::Stand(Mario* mario,Window& win,int& Camera,std::vector<std::string> map,Enemy* enemy,int& Right,int& Ques){
	int tmp = 0;
	while (mario->canFall(map)){
		mario->Fall();
		if (mario->isSmall())
			mario->DeltaVyFall();
		else
			mario->DeltaVyFallBig();	
		showMarioJump(win,Camera,enemy,mario,Right,map,Ques);
		tmp=1;
	}
	if (tmp==0) {
		mario->setZeroVx();
		mario->setZeroVy();
		showMarioStand(win,Camera,enemy,mario, Right,map);
	}
}

void Ground::JumpFunc(Mario* mario,int& Camera,Window& win,std::vector<std::string> map,int& Right,
Enemy* enemy,int& Ques,char& press){
	if ((mario->posMario.y - (mario->WhatsSize1()*MARIOSIZE) - HEIGHT + map.size() * MARIOSIZE)/MARIOSIZE - 1 >= 1){
		if (mario->WhatsX() - Camera > 6){
			win.play_sound_effect(JUMPSMALL);
			if (mario->isSmall())					
				mario->Jump();
			else
				mario->JumpBig();		
			showMarioJump(win,Camera,enemy,mario,Right,map,Ques);
			while (mario->DownIsClear(map) && mario->BesidesClearJump(map,Right)){
				if (!mario->UpIsClear(map)){
					mario->setZeroVy();
					questionCoin(mario,map,win,Ques);
					questionHealth(map,mario,win,enemy);
					questionRed(win,map,mario,enemy);
					brick(win,mario,map);
					break;
				}
				showMarioJump(win,Camera,enemy,mario,Right,map,Ques);		
				KeyPress(win,press);
				{
				if (press==RIGHT){
					Right = 1;
					MoveRightLeft(win,mario,enemy,Camera,Ques,Right,map);
				}
				else if (press == LEFT){
					Right = 0; 
					MoveRightLeft(win,mario,enemy,Camera,Ques,Right,map);					
				}	
				else{
					mario->DeltaVyJump();
				}
				}		
			}
			EverywhereEmpty(mario,enemy,Camera,map,Right,win,Ques);	
		}	
	}
	else
		mario->setZeroVy();
}

void Ground::EverywhereEmpty(Mario* mario,Enemy* enemy,int& camera,
	std::vector<std::string> map,int& Right,Window& win,int& Ques){
	if (!mario->BesidesClearJump(map,Right)){
		mario->setZeroVx();
	}
	if (!mario->DownIsClear(map)){
		mario->setZeroVy();
	}
	showMarioJump(win,camera,enemy,mario,Right,map,Ques);	
}

void Ground::questionCoin(Mario* mario,std::vector<std::string> map,Window& win,int& Ques){
	if (IsEnything(map,mario,QUESTION)){
		win.play_sound_effect(COINSOUND);                     
		Ques = 1;
		SetCoinY(mario);
		mario->addCoin();
		QuestionToEmpty(map,mario,QUESTION,QUESTIONDEAD);
		pushbackDeadQuestion(map);
	}
	else
		Ques = 0;
}
void Ground::questionHealth(std::vector<std::string> map,Mario* mario,Window& win,Enemy* enemy){
	if (IsEnything(map,mario,QUESTIONHEALTH)){
		win.play_sound_effect(MUSHROOMSOUND);
		enemy->pushBackMushroom(mario->WhatsX(),mario->WhatsY() - (mario->WhatsSize1()*MARIOSIZE) - 2.5* MARIOSIZE);
		QuestionToEmpty(map,mario,QUESTIONHEALTH,QUESTIONDEAD);
		pushbackDeadQuestion(map);
	}
}
void Ground::questionRed(Window& win,std::vector<std::string> map,Mario* mario,Enemy* enemy){
	if (IsEnything(map,mario,QUESTIONRED)){
		win.play_sound_effect(MUSHROOMSOUND);
		enemy->pushBackMushroomRed(mario->WhatsX(),mario->WhatsY() - (mario->WhatsSize1()*MARIOSIZE) - 2.5* MARIOSIZE);
		QuestionToEmpty(map,mario,QUESTIONRED,QUESTIONDEAD);
		pushbackDeadQuestion(map);
	}
}
void Ground::brick(Window& win,Mario* mario,std::vector<std::string> map){
	if (IsEnything(map,mario,BRICK) && !mario->isSmall()){
		win.play_sound_effect(BRICKSOUND);
		QuestionToEmpty(map,mario,BRICK,SPACE);
	}
}
#endif