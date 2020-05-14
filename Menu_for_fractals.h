#pragma once
#include"geometric.h"
#include"alg.h"
#include"stohastic.h"
#include"defines.h"

struct secondMenuType {
	SDL_Rect panel_geometricFractals = { coordinateX_geometric,coordinateY_geometric,size_width_panel ,size_height_panel };

	SDL_Rect panel_dynamicFractals = { coordinateX_dynamic,coordinateY_dynamic,size_width_panel ,size_height_panel };

	SDL_Rect panel_stohasticFractals = { coordinateX_stohastic,coordinateY_stohastic,size_width_panel ,size_height_panel };
	
	SDL_Rect fon = { 0,0,Screen_Width,Screen_Height };

	SDL_Rect text_geometricFractals = { coordinateX_inscription_geometric,    coordinateY_inscription_geometric,   size_width_inscription,   size_height_inscription };

	SDL_Rect text_dynamicFractals = { coordinateX_inscription_dynamic ,   coordinateY_inscription_dynamic,   size_width_inscription,  size_height_inscription };

	SDL_Rect text_stohasticFractals = { coordinateX_inscription_stohastic ,   coordinateY_inscription_stohastic,   size_width_inscription,   size_height_inscription };

	SDL_Rect highlighting_txt = { 0,0,0,0 };
	SDL_Rect highlighting_pic = { 0,0,0,0 };
	SDL_Rect exit = { coordinateX_exit ,coordinateY_exit,width_exit,height_exit};

	SDL_Texture* texture_geometricFractals = NULL;
	SDL_Texture* texture_dynamicFractals = NULL;
	SDL_Texture* texture_stohasticFractals = NULL;
	SDL_Texture* texture_text_geometricFractals = NULL;
	SDL_Texture* texture_text_dynamicFractals = NULL;
	SDL_Texture* texture_text_stohasticFractals = NULL;
	SDL_Texture* texture_fon = NULL;

	SDL_Texture* texture_highlighting_pic = NULL;
	SDL_Texture* texture_highlighting_txt= NULL;
	SDL_Texture* texture_exit = NULL;

};
 


struct fracmenuType {
	geometricMenuType geometric_menu;
	algMenuType alg_menu;
	stohasticMenuType stoh_menu;
	int numfrac = 0;
};
struct flagsType {
	bool mouseOnpanel = false;
	bool showsecondmenu = false;
	bool on_geom = false;
	bool on_alg = false;
	bool on_stoh = false;
	bool on_kox = true;
	bool on_tringle = true;
};



int init_second_menu(SDL_Renderer* renderer, secondMenuType&  second_menu);
void events_in_second_menu(SDL_Renderer* renderer, secondMenuType& second_menu, int& numbermenu, SDL_Event event);
void show_the_second_menu(SDL_Renderer* renderer, secondMenuType & second_menu);




void game(SDL_Renderer* renderer, SDL_Event event, int number_fractal,int&numbermeunu, fracmenuType& frac);

void destroy_all_textures(mainmenuType& menu, secondMenuType& second_menu, fracmenuType& fractals);

