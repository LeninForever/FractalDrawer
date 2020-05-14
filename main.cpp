#include"Header.h"
#include "Menu_for_fractals.h"

SDL_Texture* create_texture(SDL_Renderer* renderer, char* path) {
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = IMG_Load(path);
	if (surface == NULL) {
		cout << "Произошла ошибка при открытии файла" << endl;
		return NULL;
	}
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
};

void soundscroll(Mix_Chunk* sound)
{
	sound = Mix_LoadWAV("11.wav");
	if (sound == NULL)
		cout << "!!!!";
	Mix_PlayChannel(-1, sound, 0);
}

int main(int argc, char** argv) {
	srand(time(0));
	

	SDL_Init(SDL_INIT_EVERYTHING);
	if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
		std::cout << "Не удалось инициализировать SDL";
		SDL_Quit();
		return -1;
	}
	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	setlocale(LC_ALL, "rus");
	SDL_Window* window = SDL_CreateWindow(u8"Фракталлллы", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Screen_Width, Screen_Height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		SDL_Quit();
		return -1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
			
	SDL_Event event;
	Mix_Chunk* scroll = NULL;
	int numbermenu = 1;
	int numfrac = 0;
	bool mouseOnpanel = false;
	fracmenuType fractals;
	mainmenuType menu;
	secondMenuType  second_menu;
	flagsType flags;
	
	bool quit = false, showsecondmenu=false;
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	
	if (initmenu(renderer, menu)) {
		cout << "mainMenu" << endl;
		return 1;
	}
	if (init_second_menu(renderer, second_menu)) {
		cout << "secMenu" << endl;
		return 1;
	}
	if (init_geometric_menu(renderer, fractals.geometric_menu))
		return 1;
	
	if (init_alg_menu(renderer, fractals.alg_menu))
		return 1;

	if (init_stohastic_menu(renderer, fractals.stoh_menu))
		return 1;
	if (init_start_kox(renderer, fractals.geometric_menu))
		return 1;
	if (init_start_tringle(renderer, fractals.geometric_menu))
		return 1;
	if (init_start_tree(renderer, fractals.geometric_menu))
		return 1;
	
	if (init_start_mandelbrot(renderer, fractals.alg_menu))
		return 1;
	
	if (init_start_zhulia(renderer, fractals.alg_menu))
		return 1;

	if (init_start_dendrit(renderer, fractals.stoh_menu))
		return 1;
	if (init_start_lace(renderer, fractals.stoh_menu))
		return 1;
	if (init_start_list(renderer, fractals.stoh_menu))
		return 1;

	while (!quit)
	{


		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				quit = true;

			switch (numbermenu) {
			case 1: {
				SDL_RenderCopy(renderer, menu.texturebackground, NULL, &menu.background);
				if (event.button.x >= xhighlighting_choiceFractal && event.button.x <= xhighlighting_choiceFractal + width_highlighting && event.button.y >= yhighlighting_choiceFractal && event.button.y <= yhighlighting_choiceFractal + height_highlighting) {
					drawhighlighting(renderer, menu, xhighlighting_choiceFractal, yhighlighting_choiceFractal);
					if (!flags.mouseOnpanel)
						soundscroll(scroll);
					flags.mouseOnpanel = true;
				}
				else if (event.button.x >= xhighlighting_exit && event.button.x <= xhighlighting_exit + width_highlighting / 2 && event.button.y >= yhighlighting_exit && event.button.y <= yhighlighting_exit + height_highlighting) {
					drawhighlighting(renderer, menu, xhighlighting_exit, yhighlighting_exit);
					if (!flags.mouseOnpanel)
						soundscroll(scroll);
					flags.mouseOnpanel = true;
				}
				else flags.mouseOnpanel = false;

				if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.x >= xhighlighting_exit && event.button.x <= xhighlighting_exit + width_highlighting / 2 && event.button.y >= yhighlighting_exit && event.button.y <= yhighlighting_exit + height_highlighting))
					quit = true;
				else if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.x >= xhighlighting_choiceFractal && event.button.x <= xhighlighting_choiceFractal + width_highlighting && event.button.y >= yhighlighting_choiceFractal && event.button.y <= yhighlighting_choiceFractal + height_highlighting)) {
					numbermenu = 2;


				}
				break;
			}
			case 2: {
				show_the_second_menu(renderer, second_menu);
				events_in_second_menu(renderer, second_menu, numbermenu, event);
				break;
			}
			case 3: {
				show_geometric_menu(renderer, fractals.geometric_menu);
				events_in_geometric_menu(renderer, fractals.geometric_menu, event, numbermenu, numfrac);
				if (numbermenu == 6) {
					SDL_SetRenderDrawColor(renderer, 204, 249, 247, 0);
					SDL_RenderClear(renderer);
				}
				break;
			}

			case 4: {
				show_alg_menu(renderer, fractals.alg_menu);
				events_in_alg_menu(renderer, fractals.alg_menu, event, numbermenu, numfrac);
				break;
			}
			case 5: {
				show_stohastic_menu(renderer, fractals.stoh_menu);
				events_in_stohastic_menu(renderer, fractals.stoh_menu, event, numbermenu, numfrac);
				break;
			}
			case 6: {

				game(renderer, event, numfrac, numbermenu, fractals);
				break;
			}

			}
		}
		switch (numbermenu) {
		case 1: {
			SDL_RenderCopy(renderer, menu.texturebackground, NULL, &menu.background);
			if (event.button.x >= xhighlighting_choiceFractal && event.button.x <= xhighlighting_choiceFractal + width_highlighting && event.button.y >= yhighlighting_choiceFractal && event.button.y <= yhighlighting_choiceFractal + height_highlighting) {
				drawhighlighting(renderer, menu, xhighlighting_choiceFractal, yhighlighting_choiceFractal);
				if (!flags.mouseOnpanel)
					soundscroll(scroll);
				flags.mouseOnpanel = true;
			}
			else if (event.button.x >= xhighlighting_exit && event.button.x <= xhighlighting_exit + width_highlighting / 2 && event.button.y >= yhighlighting_exit && event.button.y <= yhighlighting_exit + height_highlighting) {
				drawhighlighting(renderer, menu, xhighlighting_exit, yhighlighting_exit);
				if (!flags.mouseOnpanel)
					soundscroll(scroll);
				flags.mouseOnpanel = true;
			}
			else flags.mouseOnpanel = false;

			if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.x >= xhighlighting_exit && event.button.x <= xhighlighting_exit + width_highlighting / 2 && event.button.y >= yhighlighting_exit && event.button.y <= yhighlighting_exit + height_highlighting))
				quit = true;
			else if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.x >= xhighlighting_choiceFractal && event.button.x <= xhighlighting_choiceFractal + width_highlighting && event.button.y >= yhighlighting_choiceFractal && event.button.y <= yhighlighting_choiceFractal + height_highlighting)) {
				numbermenu = 2;


			}
			break;
		}
		case 2: {
			show_the_second_menu(renderer, second_menu);
		
			break;
		}
		case 3: {
			show_geometric_menu(renderer, fractals.geometric_menu);
			
			break;
		}

		case 4: {
			show_alg_menu(renderer, fractals.alg_menu);
			
			break;
		}
		case 5: {
			show_stohastic_menu(renderer, fractals.stoh_menu);
		
			break;
		}
		case 6: {

			game(renderer, event, numfrac, numbermenu, fractals);
			break;
		}

		}
	SDL_RenderPresent(renderer);
		if (numbermenu!=6)
		SDL_RenderClear(renderer);
	}


	destroy_all_textures(menu, second_menu, fractals);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeChunk(scroll);
	Mix_CloseAudio();

	
	SDL_Quit();
	return 0;
} //3 - Для геометрических
 // 4 - динамические 
// 5 - стохастические