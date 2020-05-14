#pragma once
#include"defines.h"
struct arrowsType {
	SDL_Rect right_change_1 = { 0,0,0,0 };
	SDL_Rect right_change_2 = { 0,0,0,0 };
	SDL_Rect right_change_3 = { 0,0,0,0 };
	SDL_Rect left_change_1 = { 0,0,0,0 };
	SDL_Rect left_change_2 = { 0,0,0,0 };
	SDL_Rect left_change_3 = { 0,0,0,0 };

	SDL_Rect color[5];

	SDL_Texture* texture_right_change_1 = NULL;
	SDL_Texture* texture_right_change_2 = NULL;
	SDL_Texture* texture_right_change_3 = NULL;

	SDL_Texture* texture_left_change_1 = NULL;
	SDL_Texture* texture_left_change_2 = NULL;
	SDL_Texture* texture_left_change_3 = NULL;

	SDL_Rect inskription_1 = { 0,0,0,0 };
	SDL_Rect inskription_2 = { 0,0,0,0 };
	SDL_Rect inskription_3 = { 0,0,0,0 };

	SDL_Texture* texture_inskription_1 = NULL;
	SDL_Texture* texture_inskription_2 = NULL;
	SDL_Texture* texture_inskription_3 = NULL;

	SDL_Rect highilighting_rect = { 0,0,0,0 };
	SDL_Texture* texture_highlighting = NULL;

	SDL_Texture* texture_exit = NULL;
	SDL_Rect exit = { coordinateX_exit,coordinateY_exit,width_exit,height_exit };
};