#include"Header.h"
#include"Menu_for_fractals.h"

void init_rect(SDL_Rect& rect, int x, int y, int w, int h) {
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void rehigh(secondMenuType& second_menu, int x_pic, int y_pic, int w_pic, int h_pic, int x_txt, int y_txt, int w_txt, int h_txt) {
	second_menu.highlighting_pic.x = x_pic;
	second_menu.highlighting_pic.y = y_pic;
	second_menu.highlighting_pic.w = w_pic;
	second_menu.highlighting_pic.h = h_pic;
	second_menu.highlighting_txt.x = x_txt;
	second_menu.highlighting_txt.y = y_txt;
	second_menu.highlighting_txt.w = w_txt;
	second_menu.highlighting_txt.h = h_txt;
}
void rehigh(secondMenuType& second_menu, int x, int y, int w, int h) {
	second_menu.highlighting_pic.x = x;
	second_menu.highlighting_pic.y = y;
	second_menu.highlighting_pic.w = w;
	second_menu.highlighting_pic.h = h;
}

int init_second_menu(SDL_Renderer* renderer, secondMenuType& second_menu) {
	char path_to_main_menu[] = "for2menu.bmp", path_to_picture_g[] = "geometric.bmp", path_to_picture_d[] = "dynamic.bmp", path_to_picture_s[] = "stohastic.bmp", path_to_exit[] = "exit.bmp";
	char text_g[] = "t_1.bmp", text_d[] = "t_2.bmp", text_s[] = "t_3.bmp", highlighting[] = "2highlighting.bmp";

	second_menu.texture_fon = create_texture(renderer, path_to_main_menu);
	if (second_menu.texture_fon == NULL) {
		cout << "texture_fon wasn't open" << endl;
		return 1;
	}

	second_menu.texture_geometricFractals = create_texture(renderer, path_to_picture_g);
	if (second_menu.texture_geometricFractals == NULL) {
		cout << "texture_geometricFractals wasn't open" << endl;
		return 1;
	}

	second_menu.texture_stohasticFractals = create_texture(renderer, path_to_picture_s);
	if (second_menu.texture_stohasticFractals == NULL) {
		cout << "texture_stohasticFractals wasn't open" << endl;
		return 1;
	}

	second_menu.texture_dynamicFractals = create_texture(renderer, path_to_picture_d);
	if (second_menu.texture_dynamicFractals == NULL) {
		cout << "texture_dynamicFractals wasn't open" << endl;
		return 1;
	}

	second_menu.texture_text_geometricFractals = create_texture(renderer, text_g);
	if (second_menu.texture_text_geometricFractals == NULL) {
		cout << "texture_text_geometricFractals wasn't open" << endl;
		return 1;
	}

	second_menu.texture_text_dynamicFractals = create_texture(renderer, text_d);
	if (second_menu.texture_text_dynamicFractals == NULL) {
		cout << "texture_text_dynamicFractals wasn't open" << endl;
		return 1;
	}

	second_menu.texture_text_stohasticFractals = create_texture(renderer, text_s);
	if (second_menu.texture_text_stohasticFractals == NULL) {
		cout << "texture_text_stohasticFractals wasn't open" << endl;
		return 1;
	}

	second_menu.texture_highlighting_pic = create_texture(renderer, highlighting);
	if (second_menu.texture_highlighting_pic == NULL) {
		cout << "texture_highlighting_pic wasn't open" << endl;
		return 1;
	}

	second_menu.texture_highlighting_txt = create_texture(renderer, highlighting);
	if (second_menu.texture_highlighting_txt == NULL) {
		cout << "texture_highlighting_txt wasn't open" << endl;
		return 1;
	}

	second_menu.texture_exit = create_texture(renderer, path_to_exit);
	if (second_menu.texture_exit == NULL) {
		cout << "texture_highlighting_txt wasn't open" << endl;
		return 1;
	}

	return 0;
}

void show_the_second_menu(SDL_Renderer* renderer, secondMenuType& second_menu) {

	SDL_RenderCopy(renderer, second_menu.texture_fon, NULL, &second_menu.fon);
	SDL_RenderCopy(renderer, second_menu.texture_geometricFractals, NULL, &second_menu.panel_geometricFractals);
	SDL_RenderCopy(renderer, second_menu.texture_stohasticFractals, NULL, &second_menu.panel_stohasticFractals);
	SDL_RenderCopy(renderer, second_menu.texture_dynamicFractals, NULL, &second_menu.panel_dynamicFractals);
	SDL_RenderCopy(renderer, second_menu.texture_text_geometricFractals, NULL, &second_menu.text_geometricFractals);
	SDL_RenderCopy(renderer, second_menu.texture_text_dynamicFractals, NULL, &second_menu.text_dynamicFractals);
	SDL_RenderCopy(renderer, second_menu.texture_text_stohasticFractals, NULL, &second_menu.text_stohasticFractals);
	SDL_RenderCopy(renderer, second_menu.texture_exit, NULL, &second_menu.exit);
	SDL_RenderCopy(renderer, second_menu.texture_highlighting_pic, NULL, &second_menu.highlighting_pic);
	SDL_RenderCopy(renderer, second_menu.texture_highlighting_txt, NULL, &second_menu.highlighting_txt);
}

void events_in_second_menu(SDL_Renderer* renderer, secondMenuType& second_menu, int& numbermenu, SDL_Event event) {
	if (((event.button.x >= coordinateX_geometric) && (event.button.x <= coordinateX_geometric + size_width_panel) && (event.button.y >= coordinateY_geometric) && (event.button.y <= coordinateY_geometric + size_height_panel)) || ((event.button.x >= coordinateX_inscription_geometric) && (event.button.x <= coordinateX_inscription_geometric + size_width_inscription) && (event.button.y >= coordinateY_inscription_geometric) && (event.button.y <= coordinateY_inscription_geometric + size_height_inscription))) {
		rehigh(second_menu, coordinateX_geometric, coordinateY_geometric, size_width_panel, size_height_panel, coordinateX_inscription_geometric, coordinateY_inscription_geometric, size_width_inscription, size_height_inscription);
		//SDL_RenderCopy(renderer, second_menu.texture_highlighting_pic, NULL, &second_menu.highlighting_pic);
		//SDL_RenderCopy(renderer, second_menu.texture_highlighting_txt, NULL, &second_menu.highlighting_txt);

		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 3;
			SDL_Delay(200);
		}

	}
	else if (((event.button.x >= coordinateX_dynamic) && (event.button.x <= coordinateX_dynamic + size_width_panel) && (event.button.y >= coordinateY_dynamic) && (event.button.y <= coordinateY_dynamic + size_height_panel)) || ((event.button.x >= coordinateX_inscription_dynamic) && (event.button.x <= coordinateX_inscription_dynamic + size_width_inscription) && (event.button.y >= coordinateY_inscription_dynamic) && (event.button.y <= coordinateY_inscription_dynamic + size_height_inscription))) {

		rehigh(second_menu, coordinateX_dynamic, coordinateY_dynamic, size_width_panel, size_height_panel, coordinateX_inscription_dynamic, coordinateY_inscription_dynamic, size_width_inscription, size_height_inscription);
		//SDL_RenderCopy(renderer, second_menu.texture_highlighting_pic, NULL, &second_menu.highlighting_pic);
		//SDL_RenderCopy(renderer, second_menu.texture_highlighting_txt, NULL, &second_menu.highlighting_txt);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 4;
			SDL_Delay(200);
		}
	}
	else if (((event.button.x >= coordinateX_stohastic) && (event.button.x <= coordinateX_stohastic + size_width_panel) && (event.button.y >= coordinateY_stohastic) && (event.button.y <= coordinateY_stohastic + size_height_panel)) || ((event.button.x >= coordinateX_inscription_stohastic) && (event.button.x <= coordinateX_inscription_stohastic + size_width_inscription) && (event.button.y >= coordinateY_inscription_stohastic) && (event.button.y <= coordinateY_inscription_stohastic + size_height_inscription))) {

		rehigh(second_menu, coordinateX_stohastic, coordinateY_stohastic, size_width_panel, size_height_panel, coordinateX_inscription_stohastic, coordinateY_inscription_stohastic, size_width_inscription, size_height_inscription);
		//SDL_RenderCopy(renderer, second_menu.texture_highlighting_pic, NULL, &second_menu.highlighting_pic);
		//SDL_RenderCopy(renderer, second_menu.texture_highlighting_txt, NULL, &second_menu.highlighting_txt);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 5;
			SDL_Delay(200);
		}

	}
	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {
		rehigh(second_menu, coordinateX_exit, coordinateY_exit, width_exit, height_exit);
		//SDL_RenderCopy(renderer, second_menu.texture_highlighting_pic, NULL, &second_menu.highlighting_pic);

		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 1;
			SDL_Delay(200);
		}
	}
	else {
		rehigh(second_menu, 0, 0, 0, 0, 0, 0, 0, 0);
		rehigh(second_menu, 0, 0, 0, 0);
	}
}


void drawhighlighting(SDL_Renderer* renderer, mainmenuType& menu, int x, int y) {
	menu.highlighting.x = x;
	menu.highlighting.y = y;
	SDL_RenderCopy(renderer, menu.texturehighlighting, NULL, &menu.highlighting);


}

int initmenu(SDL_Renderer* renderer, mainmenuType& menu) {
	char pathToBackground[14] = "mainmenu2.bmp";
	char pathToHighlighting[17] = "highlighting.bmp";
	menu.texturebackground = create_texture(renderer, pathToBackground);
	menu.texturehighlighting = create_texture(renderer, pathToHighlighting);
	SDL_RenderCopy(renderer, menu.texturebackground, NULL, &menu.background);
	SDL_RenderCopy(renderer, menu.texturehighlighting, NULL, &menu.highlighting);
	return 0;
}


void game(SDL_Renderer *renderer,SDL_Event event,int number_fractal,int& numbermenu, fracmenuType& frac) {
	bool quit = false;
	while(!quit){
		switch (number_fractal) {
		case 1: {
			if (frac.geometric_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
				SDL_RenderDrawLine(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width * 2 / 3, Screen_Height * 2 / 3);
				SDL_RenderDrawLine(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI));
				SDL_RenderDrawLine(renderer, Screen_Width * 2 / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI));
				functionKox(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width * 2 / 3, Screen_Height * 2 / 3, 0, -frac.geometric_menu.kox.iskre, frac.geometric_menu.kox.iteration);
				functionKox(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI), 0, frac.geometric_menu.kox.iskre, 1);
				functionKox(renderer, Screen_Width * 2 / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI), 0, -frac.geometric_menu.kox.iskre, 1);
				frac.geometric_menu.init_flag = false;
			}
			koxmenu(renderer, frac.geometric_menu, event, numbermenu);
			break;
		}
		case 2: {
			if (frac.geometric_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 204, 249, 247, 0);
				SDL_RenderClear(renderer);
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderDrawLine(renderer, int(Screen_Width * 2 / 8), int(Screen_Height * 7 / 10), int(Screen_Width * 6 / 8), Screen_Height * 7 / 10);
				SDL_RenderDrawLine(renderer, int(Screen_Width * 2 / 8), int(Screen_Height * 7 / 10), int(Screen_Width / 2), int(Screen_Height / 9));
				SDL_RenderDrawLine(renderer, int(Screen_Width / 2), int(Screen_Height / 9), int(Screen_Width * 6 / 8), int(Screen_Height * 7 / 10));

				functionSierpinskitriangle(renderer, Screen_Width * 2 / 8, Screen_Height * 7 / 10, Screen_Width / 2, Screen_Height / 9, Screen_Width * 6 / 8, Screen_Height * 7 / 10, 0, 1);
				frac.geometric_menu.init_flag = false;
			}
			tringlemenu(renderer, frac.geometric_menu, event, numbermenu);
			break;
		}
		case 3: {
			if (frac.geometric_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 204, 249, 247, 0);
				SDL_RenderClear(renderer);
				drawpifagorTree(renderer, Screen_Width / 2, double(Screen_Height - int(Screen_Height / 4)), double(Screen_Height / 5), 0, 0, frac.geometric_menu.tree.angle, 2);
				frac.geometric_menu.init_flag = false;
			}
			treemenu(renderer, frac.geometric_menu, event, numbermenu);

			break;
		}
		case 4: {
			if (frac.alg_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
				SDL_RenderClear(renderer);

				drawMandelbrot(renderer, frac.alg_menu.mandelbrot.iterations);
				frac.alg_menu.init_flag = false;
			}
			mandelbrotmenu(renderer, frac.alg_menu, event, numbermenu);
			break;
		}
		case 5: {
			if (frac.alg_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
				SDL_RenderClear(renderer);

				drawzhulia(renderer, frac.alg_menu.zhulia.iteration);
				frac.alg_menu.init_flag = false;
			}
			zhuliamenu(renderer, frac.alg_menu, event, numbermenu);
			break;

		}
		case 6: {
			if (frac.stoh_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
				SDL_RenderClear(renderer);
				ifsDendrit(renderer, frac.stoh_menu.dendrit.parameter);
				frac.stoh_menu.init_flag = false;

			}
			dendritmenu(renderer, frac.stoh_menu, event, numbermenu);
			break;
		}
		case 7: {

			if (frac.stoh_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
				SDL_RenderClear(renderer);
				drawlace(renderer, frac.stoh_menu.lace.iskr);
				frac.stoh_menu.init_flag = false;

			}
			lacemenu(renderer, frac.stoh_menu, event, numbermenu);
			break;
		}
		case 8: {
			if (frac.stoh_menu.init_flag) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				SDL_RenderClear(renderer);
				drawlist(renderer, frac.stoh_menu.list.kuchnost);
				frac.stoh_menu.init_flag = false;
			}
			listmenu(renderer, frac.stoh_menu, event, numbermenu);
			break;
		}
		}



	}
  }
void destroy_all_textures(mainmenuType& menu, secondMenuType& second_menu, fracmenuType& fractals_menu) {
	
	//first
	SDL_DestroyTexture(menu.texturebackground);
	SDL_DestroyTexture(menu.texturehighlighting);
	//second_menu
	SDL_DestroyTexture(second_menu.texture_geometricFractals);
	SDL_DestroyTexture(second_menu.texture_dynamicFractals);
	SDL_DestroyTexture(second_menu.texture_stohasticFractals);
	SDL_DestroyTexture(second_menu.texture_fon);
	SDL_DestroyTexture(second_menu.texture_highlighting_pic);
	SDL_DestroyTexture(second_menu.texture_highlighting_txt);
	SDL_DestroyTexture(second_menu.texture_text_geometricFractals);
	SDL_DestroyTexture(second_menu.texture_text_dynamicFractals);
	SDL_DestroyTexture(second_menu.texture_text_stohasticFractals);
	SDL_DestroyTexture(second_menu.texture_exit);
	//third menu (geometric)

	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_fon);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_pic_kox);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_pic_tree);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_pic_tringle);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_txt_kox);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_txt_tree);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_txt_tringle);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_kox);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_text_kox);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_text_tree);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_text_tringle);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_tree);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_tringle);
	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_exit);
	
	//4 menu (динамические)
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_fon);
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_highlighting_pic);
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_highlighting_txt);
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_mandelbrot);
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_zhulia);
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_text_mandelbrot);
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_text_zhulia);
	SDL_DestroyTexture(fractals_menu.alg_menu.texture_exit);
	//5 menu (стохастические)
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_fon);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_highlighting_pic);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_highlighting_txt);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_dendrit);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_lace);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_list);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_text_dendrit);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_text_lace);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_text_list);
	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_exit);
	//kox
	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_left_change_2);
	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_right_change_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_right_change_2);

	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_inskription_2);

	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_exit);
	//tringle
	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_right_change_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_exit);

	//tree
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_right_change_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_left_change_2);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_right_change_2);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_inskription_2);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_exit);

	//mandelbrot
	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_exit);
	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_right_change_1);

	//zhulia
	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_exit);
	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_right_change_1);
	//dendrit
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_right_change_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_left_change_2);
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_right_change_2);
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_inskription_2);
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_exit);
	//lace
	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_right_change_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_exit);
	//list
	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_left_change_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_right_change_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_inskription_1);
	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_highlighting);
	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_exit);
}

