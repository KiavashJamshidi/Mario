#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <fstream>
#include "src/rsdl.hpp"
#include "Defines.h"

using namespace std;

void saveFromMap(vector<string> &mapVector,string location);
void showBackground(Window& win,int Camera);
int isClose(Rectangle exist,Rectangle object,int mode);
void updateMap(vector<string>& map);
int KeyPress(Window& win,char& press);

int KeyPress(Window& win,char& press){
	while (win.has_pending_event()) {
		Event event = win.poll_for_event();
		if (event.get_type() == Event::KEY_PRESS){
			press = event.get_pressed_key();
		}
	}
}

void updateMap(vector<string>& map){
	for (int i=0;i<map.size();i++){
		for (int j=0;j<map[i].size();j++){
			if (map[i][j]== MARIOO)
				map[i][j]= SPACE;
			if (map[i][j]== GOMBA)
				map[i][j]= SPACE;
			if (map[i][j] == GOMBATROMPA)
				map[i][j] == SPACE;
		}
	}
}

void saveFromMap(vector<string> &mapVector,string location) {
    ifstream map(location);
    string line;
    while (getline(map, line)) { 
        mapVector.push_back(line);
    }
    map.close();
}

void showBackground(Window& win,int Camera){
	if (Camera % BACKWIDTH <= BACKWIDTH - WIDTH)
		win.draw_img(BACKGROUND,Rectangle(0,0,WIDTH,HEIGHT),Rectangle(Camera % BACKWIDTH,0,WIDTH,1600));
	else {
		win.draw_img(BACKGROUND,Rectangle(0,0,BACKWIDTH - (Camera % BACKWIDTH), HEIGHT),
			Rectangle(Camera % BACKWIDTH,0,BACKWIDTH-(Camera%BACKWIDTH),1700));
		win.draw_img(BACKGROUND,Rectangle(BACKWIDTH-(Camera%BACKWIDTH),0,
			(Camera%BACKWIDTH) - BACKWIDTH+WIDTH,HEIGHT),
				Rectangle(0,0,(Camera % BACKWIDTH) - BACKWIDTH + WIDTH,1700));
	}
}


int isClose(Rectangle exist,Rectangle object,int mode){
	if ((exist.y + exist.h == object.y)&&(exist.x < object.x + object.w)&&(exist.x + exist.w > object.x)&& mode==1)
		return 1;
	if ((exist.y == object.y + object.h)&&(exist.x < object.x + object.w)&&(exist.x + exist.w > object.x)&& mode==2)
		return 1;
	if ((exist.x + exist.w == object.x)&&(exist.y < object.y + object.h)&&(exist.y + exist.h > object.y)&& mode==3)
		return 1;
	if ((exist.x == object.x + object.w)&&(exist.y < object.y + object.h)&&(exist.y + exist.h > object.y)&& mode==4)	
		return 1;
	return 0;		
}

#endif