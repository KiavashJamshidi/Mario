#ifndef DEFINES_H
#define DEFINES_H

#define STANDRIGHT "assets/sprites/mario/normal/standing-right.png"
#define STANDLEFT "assets/sprites/mario/normal/standing-left.png"
#define BACKGROUND "assets/background_image.png"
#define MOVETORIGHT3 "assets/sprites/mario/normal/walking-right-3.png"
#define MOVETORIGHT2 "assets/sprites/mario/normal/walking-right-2.png"
#define MOVETORIGHT1 "assets/sprites/mario/normal/walking-right-1.png"
#define MOVETOLEFT3 "assets/sprites/mario/normal/walking-left-3.png"
#define MOVETOLEFT2 "assets/sprites/mario/normal/walking-left-2.png"
#define MOVETOLEFT1 "assets/sprites/mario/normal/walking-left-1.png"
#define INPUTMAP "assets/maps/1/1.txt"
#define CLAYINPUT "assets/sprites/objects/bricks_blocks/clay.png"
#define BRICKINPUT "assets/sprites/objects/bricks_blocks/brick.png"
#define BLOCKINPUT "assets/sprites/objects/bricks_blocks/block.png"
#define PIPE_HEAD_RIGHT_INPUT "assets/sprites/objects/pipe/head-right.png"
#define PIPE_HEAD_LEFT_INPUT "assets/sprites/objects/pipe/head-left.png"
#define PIPERIGHTINPUT "assets/sprites/objects/pipe/right.png"
#define PIPELEFTINPUT "assets/sprites/objects/pipe/left.png"
#define JUMPLEFT "assets/sprites/mario/normal/jumping-left.png"
#define JUMPRIGHT "assets/sprites/mario/normal/jumping-right.png"
#define FONT "gnu-freefont_freesans/FreeSansBold.ttf"
#define MUSIC "assets/sounds/Super Mario Bros. theme music.ogg"
#define DEATHSOUND "assets/sounds/sound_effects/mario-death.wav"
#define UPSOUND "assets/sounds/sound_effects/1-up.wav"
#define GAMEOVERSOUND "assets/sounds/sound_effects/gameover.wav"
#define JUMPSMALL "assets/sounds/sound_effects/jump-small.wav"
#define GOMBAWALK1 "assets/sprites/enemies/little_goomba/walking-1.png"
#define GOMBAWALK2 "assets/sprites/enemies/little_goomba/walking-2.png"
#define GOMBADEAD "assets/sprites/enemies/little_goomba/dead.png"
#define QUESTION1 "assets/sprites/objects/bricks_blocks/question-1.png"
#define QUESTION2 "assets/sprites/objects/bricks_blocks/question-2.png"
#define QUESTION3 "assets/sprites/objects/bricks_blocks/question-3.png"
#define GOMBATROMPAWALKR1 "assets/sprites/enemies/koopa_troopa/walking-right-1.png"
#define GOMBATROMPAWALKR2 "assets/sprites/enemies/koopa_troopa/walking-right-2.png"
#define GOMBATROMPAWALKL1 "assets/sprites/enemies/koopa_troopa/walking-left-1.png"
#define GOMBATROMPAWALKL2 "assets/sprites/enemies/koopa_troopa/walking-left-2.png"
#define GOMBATROMPADEAD "assets/sprites/enemies/koopa_troopa/dead.png"
#define FLAGHEAD "assets/sprites/objects/flag/head.png"
#define FLAGBODY "assets/sprites/objects/flag/body.png"
#define COIN "assets/sprites/objects/coin.png"
#define COINSOUND "assets/sounds/sound_effects/coin.wav"
#define DEADQUESTION "assets/sprites/objects/bricks_blocks/question-empty.png"
#define BRICKSOUND "assets/sounds/sound_effects/brick-smash.wav"
#define MUSHROOMHEALTH "assets/sprites/objects/mushroom/health.png"
#define MUSHROOMRED "assets/sprites/objects/mushroom/red.png"
#define POWERUP "assets/sounds/sound_effects/powerup.wav"
#define MUSHROOMSOUND "assets/sounds/sound_effects/powerup-appears.wav"
#define BRICKSMASH "assets/sprites/objects/brick-debris.png"
#define LEVELCLEAR "assets/sounds/sound_effects/level-clear.wav"

#include <string>

const std::string GAMEOVER = "Game Over";
const std::string TOPIC = "SuperMario";
const char RIGHT='d';
const char BRICK = 'b';;
const char CLAY = '#';
const char BLOCK = '@';
const char LEFT = 'a';
const char JUMP = 'w';
const char MARIOO = 'M';
const char QUIT = 'q';
const char PIPE = '|';
const char SPACE = '.';
const char GOMBA = 'l';
const char QUESTION = '?';
const char QUESTIONRED = 'm';
const char QUESTIONHEALTH = 'h';
const char GOMBATROMPA = 'k';
const char FLAG = 'f';
const char QUESTIONDEAD = 'X';
const char QUESTIONHEALTHDEAD = 'Y';
const char QUESTIONREDDEAD='Z';
const int HEIGHT = 735;
const int WIDTH = 1150;
const int MARIOSIZE = 35;
const int BACKWIDTH = 2000;
#endif