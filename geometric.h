

#pragma once
#include"arrows.h"
struct frontColorType {
	int redcolor = 0;
	int greencolor = 0;
	int bluecolor = 0;
};
struct backColorType {
	int redcolor = 0;
	int greencolor = 0;
	int bluecolor = 0;
};
struct colorType {
	backColorType backcolor;
	frontColorType frontcolor;
};
struct koxType {
	
	int iteration = 1;
	double iskre = 3;
	colorType color;
	arrowsType arrows;
	
	
};
struct tringleType {
	
	int iteration = 0;
	arrowsType arrows;
	colorType color;
	
	};
struct treeType {
	
	int iteration = 2;
	int angle = 30;
	arrowsType arrows;
	colorType color;
};
struct geometricMenuType {

	SDL_Rect panel_kox = { gcoordinateX_kox,gcoordinateY_kox, gsize_width_panel ,gsize_height_panel };

	SDL_Rect panel_tringle = { gcoordinateX_tringle,gcoordinateY_tringle,gsize_width_panel ,gsize_height_panel };

	SDL_Rect panel_tree = { gcoordinateX_tree,gcoordinateY_tree, gsize_width_panel ,gsize_height_panel };

	SDL_Rect fon = { 0,0,Screen_Width,Screen_Height };

	SDL_Rect text_kox = { gcoordinateX_inscription_kox,    gcoordinateY_inscription_kox,   gsize_width_inscription,   gsize_height_inscription };

	SDL_Rect text_tringle = { gcoordinateX_inscription_tringle ,   gcoordinateY_inscription_tringle,   gsize_width_inscription,  gsize_height_inscription };

	SDL_Rect text_tree = { gcoordinateX_inscription_tree,   gcoordinateY_inscription_tree,   gsize_width_inscription,   gsize_height_inscription };

	SDL_Rect highlighting_txt = { 0,0,0,0 };
	SDL_Rect highlighting_pic = { 0,0,0,0 };

	SDL_Rect exit = { coordinateX_exit,coordinateY_exit,width_exit,height_exit };

	SDL_Texture* texture_kox = NULL;
	SDL_Texture* texture_tringle = NULL;
	SDL_Texture* texture_tree = NULL;
	SDL_Texture* texture_text_kox = NULL;
	SDL_Texture* texture_text_tringle = NULL;
	SDL_Texture* texture_text_tree = NULL;
	SDL_Texture* texture_fon = NULL;

	SDL_Texture* texture_highlighting_pic_kox = NULL;
	SDL_Texture* texture_highlighting_txt_kox = NULL;

	SDL_Texture* texture_highlighting_pic_tringle = NULL;
	SDL_Texture* texture_highlighting_txt_tringle = NULL;

	SDL_Texture* texture_highlighting_pic_tree = NULL;
	SDL_Texture* texture_highlighting_txt_tree = NULL;

	SDL_Texture* texture_exit = NULL;

	koxType kox;
	tringleType tringle;
	treeType tree;

	bool init_flag = true;
};

// функции рисования фракталов
void functionKox(SDL_Renderer* renderer, double x0, double y0, double x1, double y1, int iteration, double iskr, int until_iter);  //(x0;y0) - начальная координата 1/3 прямой, (x1;y1) - конечная координата 1/3 прямой, iteration - приближение  
void functionSierpinskitriangle(SDL_Renderer* renderer, double x1, double y1, double x2, double y2, double x3, double y3, int iteration,int until_iteration);
void drawpifagorTree(SDL_Renderer* renderer, double x0, double y0, double length,int iteration, double angle,int change_angle, int until_iteration);

int init_geometric_menu(SDL_Renderer* renderer, geometricMenuType& geometric_menu);
void show_geometric_menu(SDL_Renderer* renderer, geometricMenuType geometric_menu);
void  events_in_geometric_menu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu, int& numfrac);

void rehigh(koxType& kox, int x_pic, int y_pic, int w_pic, int h_pic);
int init_start_kox(SDL_Renderer* renderer, geometricMenuType& geometric_menu);
bool events_in_kox(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu);
void koxmenu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu);
void show_interface_kox(SDL_Renderer* renderer, geometricMenuType geometric_menu);

void rehigh(geometricMenuType& geometric_menu, int x_pic, int y_pic, int w_pic, int h_pic, int x_txt, int y_txt, int w_txt, int h_txt);
int init_start_tringle(SDL_Renderer* renderer, geometricMenuType& geometric_menu);
void show_interface_tringle(SDL_Renderer* renderer, geometricMenuType geometric_menu);
void rehigh(tringleType& tringle, int x_pic, int y_pic, int w_pic, int h_pic);
bool events_in_tringle(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu);
void tringlemenu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu);

void rehigh(treeType& tree, int x, int y, int w, int h);
int init_start_tree(SDL_Renderer* renderer, geometricMenuType& geometric_menu);
void show_interface_tree(SDL_Renderer* renderer, geometricMenuType geometric_menu);
bool events_in_tree(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu);
void treemenu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu);
