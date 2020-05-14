#pragma once
#pragma comment(lib, "SDL2_mixer.lib")
#include"SDL.h"
#include<cmath>
#include<iostream>
#include<time.h>
#include<locale.h>
#include "SDL_mixer.h"
#include"SDL_image.h"
#include <stdio.h>
#include <stdlib.h>

#include"defines.h"


//#define scalekoef 1

#define xhighlighting_choiceFractal  Screen_Width *5/ 8
#define yhighlighting_choiceFractal  Screen_Height * 65 / 104 - Screen_Height / 100
#define width_highlighting  Screen_Width * 31 / 104
#define height_highlighting Screen_Height / 11
#define xhighlighting_exit  Screen_Width *5/ 8
#define yhighlighting_exit  Screen_Height * 3 / 4


using namespace std;

struct mainmenuType {

	
	SDL_Rect highlighting = { xhighlighting_exit ,yhighlighting_exit ,width_highlighting ,height_highlighting };
	SDL_Rect chooseFractal;
	SDL_Rect background = { 0,0,Screen_Width,Screen_Height };
	SDL_Texture* texturebackground = NULL;
	SDL_Texture* texturehighlighting = NULL;

};

SDL_Texture* create_texture(SDL_Renderer* renderer, char* path);
 
int initmenu(SDL_Renderer* renderer, mainmenuType& menu);

void drawhighlighting(SDL_Renderer* renderer, mainmenuType& menu, int x, int y);
//void ifsDendrit(SDL_Renderer* renderer, int iter);
//void biomorf(SDL_Renderer* renderer);
//void broun(SDL_Renderer* renderer);
//void list(SDL_Renderer* renderer);
//void zhulia(SDL_Renderer* renderer, int iterations);
//void lace(SDL_Renderer* renderer);
//void DrawMandelbrot(SDL_Renderer* renderer, int iterations);
void init_rect(SDL_Rect& rect, int x, int y, int w, int h);

