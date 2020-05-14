#pragma once

#include"arrows.h"
struct mandelbrotType {
	int iterations = 20;
	int plusiteration = 50;
	arrowsType arrows;
};
struct zhuliaType {
	int iteration = 20;
	int plusiteration = 5;
	arrowsType arrows;
};

struct algMenuType {

	SDL_Rect panel_mandelbrot = { acoordinateX_mandelbrot,acoordinateY_mandelbrot, asize_width_panel ,asize_height_panel };
	SDL_Rect panel_zhulia = { acoordinateX_zhulia,acoordinateY_zhulia, asize_width_panel ,asize_height_panel };

	SDL_Rect fon = { 0,0,Screen_Width,Screen_Height };
	SDL_Rect text_mandelbrot = { acoordinateX_inscription_mandelbrot,   acoordinateY_inscription_mandelbrot,   asize_width_inscription,   asize_height_inscription };
	SDL_Rect text_zhulia = { acoordinateX_inscription_zhulia,   acoordinateY_inscription_zhulia,   asize_width_inscription,   asize_height_inscription };

	SDL_Rect highlighting_txt = { 0,0,0,0 };
	SDL_Rect highlighting_pic = { 0,0,0,0 };
	SDL_Rect exit = { coordinateX_exit,coordinateY_exit,width_exit,height_exit };

	SDL_Texture* texture_mandelbrot = NULL;
	SDL_Texture* texture_zhulia = NULL;

	SDL_Texture* texture_text_mandelbrot = NULL;
	SDL_Texture* texture_text_zhulia = NULL;
	
	SDL_Texture* texture_fon = NULL;
	SDL_Texture* texture_exit = NULL;
	SDL_Texture* texture_highlighting_pic = NULL;
	SDL_Texture* texture_highlighting_txt = NULL;
	
	mandelbrotType mandelbrot;
	zhuliaType zhulia;

	bool init_flag = true;

};

void drawMandelbrot(SDL_Renderer* renderer, int iterations);
void drawzhulia(SDL_Renderer* renderer, int iter);

int init_alg_menu(SDL_Renderer* renderer, algMenuType& alg_menu);
void show_alg_menu(SDL_Renderer* renderer, algMenuType alg_menu);
void rehigh(algMenuType& alg_menu, int x_pic, int y_pic, int w_pic, int h_pic, int x_txt, int y_txt, int w_txt, int h_txt);
void  events_in_alg_menu(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu, int& numfrac);


void init_rect(SDL_Rect& rect, int x, int y, int w, int h);
int init_start_mandelbrot(SDL_Renderer* renderer, algMenuType& alg_menu);
void show_interface_mandelbrot(SDL_Renderer* renderer, algMenuType alg_menu);
void rehigh(mandelbrotType& mandelbrot, int x_pic, int y_pic, int w_pic, int h_pic);
bool events_in_mandelbrot(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu);
void mandelbrotmenu(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu);
void drawzhulia(SDL_Renderer* renderer, int iter);


int init_start_zhulia(SDL_Renderer* renderer, algMenuType& alg_menu);
void show_interface_zhulia(SDL_Renderer* renderer, algMenuType alg_menu);
void rehigh(zhuliaType& zhulia, int x_pic, int y_pic, int w_pic, int h_pic);
bool events_in_zhulia(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu);
void zhuliamenu(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu);