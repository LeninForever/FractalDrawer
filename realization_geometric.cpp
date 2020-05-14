
#include"Header.h"
#include"Menu_for_fractals.h"




#include"Header.h"
#include"Menu_for_fractals.h"
#include"geometric.h"

void drawpifagorTree(SDL_Renderer* renderer, double x0, double y0, double length, int iteration, double angle, int change_angle, int until_iteration) {
	SDL_SetRenderDrawColor(renderer, 255, iteration * 25, iteration * 25, 0);
	if (length > Screen_Height / 32)
		SDL_SetRenderDrawColor(renderer, 150, 75, 0, 0);
	else
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderDrawLine(renderer, x0, y0, x0 + length * sin(M_PI * angle / 180), y0 - length * cos(M_PI * angle / 180));
	x0 = x0 + length * sin(M_PI * angle / 180);
	y0 = y0 - length * cos(M_PI * angle / 180);
	length *= 0.7;


	iteration++;
	if (iteration < until_iteration) {

		drawpifagorTree(renderer, x0, y0, length, iteration, angle + change_angle, change_angle, until_iteration);

		drawpifagorTree(renderer, x0, y0, length, iteration, angle - change_angle, change_angle, until_iteration);


	}
}

void functionKox(SDL_Renderer* renderer, double x0, double y0, double x1, double y1, int iteration, double isk, int until_iteration) {

	double h = 0, a = 0, centerX = 0, centerY = 0;
	double x3, y3, x23, y23;

	x3 = x0 + ((x1 - x0) * 1.0) / 3.0;
	y3 = y0 + (y1 - y0) / 3.0;
	x23 = x0 + ((x1 - x0) * 2) / 3.0;
	y23 = y0 + ((y1 - y0) * 2) / 3.0;
	SDL_SetRenderDrawColor(renderer, 204, 249, 247, 0);
	SDL_RenderDrawLine(renderer, x3, y3, x23, y23);
	if (iteration < 5)
		for (double ii = -1; ii <= 1; ii += 0.5) {
			SDL_RenderDrawLine(renderer, x3 + ii, y3, x23 + ii, y23);
			SDL_RenderDrawLine(renderer, x3 - ii, y3 - ii, x23 - ii, y23 - ii);
		}



	h = sqrt(((x23 - x3) * (x23 - x3) + (y23 - y3) * (y23 - y3))) / (2.0 * sqrt(3));

	centerX = (x3 + x23) / 2 + h * isk * ((y23 - y3) / sqrt((x23 - x3) * (x23 - x3) + (y3 - y23) * (y3 - y23)));
	centerY = (y3 + y23) / 2 - h * isk * ((x23 - x3) / sqrt((x23 - x3) * (x23 - x3) + (y3 - y23) * (y3 - y23)));
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	SDL_RenderDrawLine(renderer, x3, y3, centerX, centerY);

	SDL_RenderDrawLine(renderer, centerX, centerY, x23, y23);
	//if ((iteration<max_iteration_kox)&&(iteration < until_iteration))
	iteration++;
	if (iteration < until_iteration) {

		functionKox(renderer, x0, y0, x3, y3, iteration, isk, until_iteration);
		functionKox(renderer, x3, y3, centerX, centerY, iteration, isk, until_iteration);
		functionKox(renderer, centerX, centerY, x23, y23, iteration, isk, until_iteration);
		functionKox(renderer, x23, y23, x1, y1, iteration, isk, until_iteration);

	}
}

void functionSierpinskitriangle(SDL_Renderer* renderer, double x1, double y1, double x2, double y2, double x3, double y3, int iteration, int until_iteration) {


	double mid1X, mid1Y, mid2X, mid2Y, mid3X, mid3Y;

	mid1X = ((x1 + x3) / 2.0);
	mid1Y = y1;
	mid2X = (x1 + x2) / 2.0;
	mid2Y = (y1 + y2) / 2.0;
	mid3X = (x2 + x3) / 2.0;
	mid3Y = (y2 + y3) / 2.0;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, mid1X, mid1Y, mid2X, mid2Y); //низ

	SDL_RenderDrawLine(renderer, mid2X, mid2Y, mid3X, mid3Y);// лево 


	SDL_RenderDrawLine(renderer, mid3X, mid3Y, mid1X, mid1Y);//право

	iteration++;
	if (iteration < until_iteration) {

		functionSierpinskitriangle(renderer, x1, y1, mid2X, mid2Y, mid1X, mid1Y, iteration, until_iteration);
		functionSierpinskitriangle(renderer, mid2X, mid2Y, x2, y2, mid3X, mid3Y, iteration, until_iteration);
		functionSierpinskitriangle(renderer, mid1X, mid1Y, mid3X, mid3Y, x3, y3, iteration, until_iteration);
	}

}

///////////////////

int init_geometric_menu(SDL_Renderer* renderer, geometricMenuType& geometric_menu) {

	char path_to_main_menu[] = "for2menu.bmp", path_to_picture_k[] = "kox.bmp", path_to_picture_tringle[] = "tringle.bmp", path_to_picture_tree[] = "tree.bmp", path_to_exit[] = "exit.bmp";
	char text_kox[] = "tg_1.bmp", text_tringle[] = "tg_2.bmp", text_tree[] = "tg_3.bmp", highlighting[] = "2highlighting.bmp";
	char hing_tree[] = "r_tg_1.bmp", hing_tringle[] = "r_tg_2.bmp";
	geometric_menu.texture_fon = create_texture(renderer, path_to_main_menu);
	if (geometric_menu.texture_fon == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_kox = create_texture(renderer, path_to_picture_k);
	if (geometric_menu.texture_kox == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_tringle = create_texture(renderer, path_to_picture_tringle);
	if (geometric_menu.texture_tringle == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_tree = create_texture(renderer, path_to_picture_tree);
	if (geometric_menu.texture_tree == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_text_kox = create_texture(renderer, text_kox);
	if (geometric_menu.texture_text_kox == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_text_tringle = create_texture(renderer, text_tringle);
	if (geometric_menu.texture_text_tringle == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_text_tree = create_texture(renderer, text_tree);
	if (geometric_menu.texture_text_tree == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_highlighting_pic_kox = create_texture(renderer, highlighting);
	if (geometric_menu.texture_highlighting_pic_kox == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_highlighting_txt_kox = create_texture(renderer, highlighting);
	if (geometric_menu.texture_highlighting_txt_kox == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_highlighting_pic_tringle = create_texture(renderer, hing_tringle);
	if (geometric_menu.texture_highlighting_pic_tringle == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_highlighting_txt_tringle = create_texture(renderer, hing_tringle);
	if (geometric_menu.texture_highlighting_txt_tringle == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_highlighting_pic_tree = create_texture(renderer, hing_tree);
	if (geometric_menu.texture_highlighting_pic_tree == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}
	geometric_menu.texture_highlighting_txt_tree = create_texture(renderer, hing_tree);
	if (geometric_menu.texture_highlighting_txt_tree == NULL) {
		cout << "Ошибка при открытии файла (<<init_geometric_menu>>)" << endl;
		return 1;

	}

	geometric_menu.texture_exit = create_texture(renderer, path_to_exit);
	if (geometric_menu.texture_exit == NULL) {
		cout << "texture_exit (<<init_geometric_menu>>) wasn't open" << endl;
		return 1;
	}
	return 0;
}

void show_geometric_menu(SDL_Renderer* renderer, geometricMenuType geometric_menu) {
	SDL_RenderCopy(renderer, geometric_menu.texture_fon, NULL, &geometric_menu.fon);
	SDL_RenderCopy(renderer, geometric_menu.texture_kox, NULL, &geometric_menu.panel_kox);
	SDL_RenderCopy(renderer, geometric_menu.texture_tringle, NULL, &geometric_menu.panel_tringle);
	SDL_RenderCopy(renderer, geometric_menu.texture_tree, NULL, &geometric_menu.panel_tree);
	SDL_RenderCopy(renderer, geometric_menu.texture_text_kox, NULL, &geometric_menu.text_kox);
	SDL_RenderCopy(renderer, geometric_menu.texture_text_tringle, NULL, &geometric_menu.text_tringle);
	SDL_RenderCopy(renderer, geometric_menu.texture_text_tree, NULL, &geometric_menu.text_tree);
	SDL_RenderCopy(renderer, geometric_menu.texture_exit, NULL, &geometric_menu.exit);
}

void  events_in_geometric_menu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu, int& numfrac) {
	if (((event.button.x >= gcoordinateX_kox) && (event.button.x <= gcoordinateX_kox + gsize_width_panel) && (event.button.y >= gcoordinateY_kox) && (event.button.y <= gcoordinateY_kox + gsize_height_panel)) || ((event.button.x >= gcoordinateX_inscription_kox) && (event.button.x <= gcoordinateX_inscription_kox + gsize_width_inscription) && (event.button.y >= gcoordinateY_inscription_kox) && (event.button.y <= gcoordinateY_inscription_kox + gsize_height_inscription))) {
		rehigh(geometric_menu, gcoordinateX_kox, gcoordinateY_kox, gsize_width_panel, gsize_height_panel, gcoordinateX_inscription_kox, gcoordinateY_inscription_kox, gsize_width_inscription, gsize_height_inscription);
		SDL_RenderCopy(renderer, geometric_menu.texture_highlighting_pic_kox, NULL, &geometric_menu.highlighting_pic);
		SDL_RenderCopy(renderer, geometric_menu.texture_highlighting_txt_kox, NULL, &geometric_menu.highlighting_txt);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 6;
			numfrac = 1;
			SDL_Delay(200);
		}

	}
	else if (((event.button.x >= gcoordinateX_tringle) && (event.button.x <= gcoordinateX_tringle + gsize_width_panel) && (event.button.y >= gcoordinateY_tringle) && (event.button.y <= gcoordinateY_tringle + gsize_height_panel)) || ((event.button.x >= gcoordinateX_inscription_tringle) && (event.button.x <= gcoordinateX_inscription_tringle + gsize_width_inscription) && (event.button.y >= gcoordinateY_inscription_tringle) && (event.button.y <= gcoordinateY_inscription_tringle + gsize_height_inscription))) {

		rehigh(geometric_menu, gcoordinateX_tringle, gcoordinateY_tringle, gsize_width_panel, gsize_height_panel, gcoordinateX_inscription_tringle, gcoordinateY_inscription_tringle, gsize_width_inscription, gsize_height_inscription);
		SDL_RenderCopy(renderer, geometric_menu.texture_highlighting_pic_tringle, NULL, &geometric_menu.highlighting_pic);
		SDL_RenderCopy(renderer, geometric_menu.texture_highlighting_txt_tringle, NULL, &geometric_menu.highlighting_txt);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 6;
			numfrac = 2;
			SDL_Delay(200);
		}

	}
	else if (((event.button.x >= gcoordinateX_tree) && (event.button.x <= gcoordinateX_tree + gsize_width_panel) && (event.button.y >= gcoordinateY_tree) && (event.button.y <= gcoordinateY_tree + gsize_height_panel)) || ((event.button.x >= gcoordinateX_inscription_tree) && (event.button.x <= gcoordinateX_inscription_tree + gsize_width_inscription) && (event.button.y >= gcoordinateY_inscription_tree) && (event.button.y <= gcoordinateY_inscription_tree + gsize_height_inscription))) {

		rehigh(geometric_menu, gcoordinateX_tree, gcoordinateY_tree, gsize_width_panel, gsize_height_panel, gcoordinateX_inscription_tree, gcoordinateY_inscription_tree, gsize_width_inscription, gsize_height_inscription);
		SDL_RenderCopy(renderer, geometric_menu.texture_highlighting_pic_tree, NULL, &geometric_menu.highlighting_pic);
		SDL_RenderCopy(renderer, geometric_menu.texture_highlighting_txt_tree, NULL, &geometric_menu.highlighting_txt);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 6;
			numfrac = 3;
			SDL_Delay(200);
		}

	}
	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {
		geometric_menu.highlighting_pic.x = coordinateX_exit;
		geometric_menu.highlighting_pic.y = coordinateY_exit;
		geometric_menu.highlighting_pic.w = width_exit;
		geometric_menu.highlighting_pic.h = height_exit;
		SDL_RenderCopy(renderer, geometric_menu.texture_highlighting_pic_kox, NULL, &geometric_menu.highlighting_pic);

		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 2;
			SDL_Delay(200);
		}
	}

}




//перевыделение 
void rehigh(koxType& kox, int x_pic, int y_pic, int w_pic, int h_pic) {
	kox.arrows.highilighting_rect.x = x_pic;
	kox.arrows.highilighting_rect.y = y_pic;
	kox.arrows.highilighting_rect.w = w_pic;
	kox.arrows.highilighting_rect.h = h_pic;

}
//создание всех текстур
int init_start_kox(SDL_Renderer* renderer, geometricMenuType& geometric_menu) {
	char path_left_arrow[] = "left_arrow.bmp", path_right_arrow[] = "right_arrow.bmp", path_exit[] = "exit2.bmp", path_insk_1[] = "iskr.bmp", path_insk_2[] = "razmernost.bmp", highlighting[] = "high_2.bmp";

	geometric_menu.kox.arrows.texture_left_change_1 = create_texture(renderer, path_left_arrow);
	if (geometric_menu.kox.arrows.texture_left_change_1 == NULL) {
		return 1;
	}
	init_rect(geometric_menu.kox.arrows.left_change_1, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);

	geometric_menu.kox.arrows.texture_left_change_2 = create_texture(renderer, path_left_arrow);
	if (geometric_menu.kox.arrows.texture_left_change_2 == NULL) {
		return 1;
	}

	init_rect(geometric_menu.kox.arrows.left_change_2, arrows_left_2_x, arrows_left_2_y, arrows_width, arrows_height);

	geometric_menu.kox.arrows.texture_right_change_1 = create_texture(renderer, path_right_arrow);

	if (geometric_menu.kox.arrows.texture_right_change_1 == NULL) {
		return 1;
	}
	init_rect(geometric_menu.kox.arrows.right_change_1, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);

	geometric_menu.kox.arrows.texture_right_change_2 = create_texture(renderer, path_right_arrow);
	if (geometric_menu.kox.arrows.texture_right_change_2 == NULL) {
		return 1;
	}
	init_rect(geometric_menu.kox.arrows.right_change_2, arrows_right_2_x, arrows_right_2_y, arrows_width, arrows_height);

	geometric_menu.kox.arrows.texture_inskription_1 = create_texture(renderer, path_insk_1);
	if (geometric_menu.kox.arrows.texture_inskription_1 == NULL) {
		return 1;
	}
	init_rect(geometric_menu.kox.arrows.inskription_1, arrows_text_1_x, arrows_text_1_y, arrows_text_width, arrows_text_height);

	geometric_menu.kox.arrows.texture_inskription_2 = create_texture(renderer, path_insk_2);
	if (geometric_menu.kox.arrows.texture_inskription_2 == NULL) {
		return 1;
	}
	init_rect(geometric_menu.kox.arrows.inskription_2, arrows_text_2_x, arrows_text_2_y, arrows_text_width, arrows_text_height);

	geometric_menu.kox.arrows.texture_highlighting = create_texture(renderer, highlighting);
	if (geometric_menu.kox.arrows.texture_highlighting == NULL) {
		return 1;
	}
	geometric_menu.kox.arrows.texture_exit = create_texture(renderer, path_exit);
	if (geometric_menu.kox.arrows.texture_highlighting == NULL) {
		return 1;
	}



	return 0;
}
//обработчик событий
bool events_in_kox(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu) {
	bool change = false;
	if ((event.button.x >= arrows_left_1_x) && (event.button.x <= arrows_left_1_x + arrows_width) && (event.button.y >= arrows_left_1_y) && (event.button.y <= arrows_left_1_y + arrows_height)) {

		rehigh(geometric_menu.kox, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_highlighting, NULL, &geometric_menu.kox.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.kox.iskre > -6.5) {
				geometric_menu.kox.iskre -= 0.5;
				change = true;
				SDL_Delay(200);
			}
		}
	}
	else if ((event.button.x >= arrows_left_2_x) && (event.button.x <= arrows_left_2_x + arrows_width) && (event.button.y >= arrows_left_2_y) && (event.button.y <= arrows_left_2_y + arrows_height)) {

		rehigh(geometric_menu.kox, arrows_left_2_x, arrows_left_2_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_highlighting, NULL, &geometric_menu.kox.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.kox.iteration > 1) {
				geometric_menu.kox.iteration--;
				change = true;
				SDL_Delay(200);
			}
		}
	}
	else if ((event.button.x >= arrows_right_1_x) && (event.button.x <= arrows_right_1_x + arrows_width) && (event.button.y >= arrows_right_1_y) && (event.button.y <= arrows_right_1_y + arrows_height)) {

		rehigh(geometric_menu.kox, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_highlighting, NULL, &geometric_menu.kox.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.kox.iskre < 5.5) {
				geometric_menu.kox.iskre += 0.5;
				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= arrows_right_2_x) && (event.button.x <= arrows_right_2_x + arrows_width) && (event.button.y >= arrows_right_2_y) && (event.button.y <= arrows_right_2_y + arrows_height)) {

		rehigh(geometric_menu.kox, arrows_right_2_x, arrows_right_2_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_highlighting, NULL, &geometric_menu.kox.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.kox.iteration < max_iteration_kox - 1) {
				geometric_menu.kox.iteration++;
				change = true;
				SDL_Delay(200);
			}
		}
	}
	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {

		rehigh(geometric_menu.kox, coordinateX_exit, coordinateY_exit, width_exit, height_exit);
		SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_highlighting, NULL, &geometric_menu.kox.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			numbermenu = 3;
			geometric_menu.init_flag = true;
			geometric_menu.kox.iteration = 1;
			geometric_menu.kox.iskre = 3;
			SDL_Delay(200);

		}


	}
	return change;
}
// перерисовка
void koxmenu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu) {
	show_interface_kox(renderer, geometric_menu);

	if (events_in_kox(renderer, geometric_menu, event, numbermenu)) {
		SDL_SetRenderDrawColor(renderer, 204, 249, 247, 0);
		SDL_RenderClear(renderer);
		if (geometric_menu.kox.iteration >= 7) {
			//func_inskription("Фрактал рисуется");
			SDL_RenderPresent(renderer);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
		SDL_RenderDrawLine(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width * 2 / 3, Screen_Height * 2 / 3);
		SDL_RenderDrawLine(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI));
		SDL_RenderDrawLine(renderer, Screen_Width * 2 / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI));
		functionKox(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width * 2 / 3, Screen_Height * 2 / 3, 0, -geometric_menu.kox.iskre, geometric_menu.kox.iteration);
		functionKox(renderer, Screen_Width / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI), 0, geometric_menu.kox.iskre, geometric_menu.kox.iteration);
		functionKox(renderer, Screen_Width * 2 / 3, Screen_Height * 2 / 3, Screen_Width / 2, Screen_Height * 2 / 3 - Screen_Width / 3 * sin(60 * 180 / M_PI), 0, -geometric_menu.kox.iskre, geometric_menu.kox.iteration);
		show_interface_kox(renderer, geometric_menu);
	}


}
//рисует все стрелки и надписи
void show_interface_kox(SDL_Renderer* renderer, geometricMenuType geometric_menu) {
	SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_left_change_1, NULL, &geometric_menu.kox.arrows.left_change_1);
	SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_left_change_2, NULL, &geometric_menu.kox.arrows.left_change_2);
	SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_right_change_1, NULL, &geometric_menu.kox.arrows.right_change_1);
	SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_right_change_2, NULL, &geometric_menu.kox.arrows.right_change_2);
	SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_inskription_1, NULL, &geometric_menu.kox.arrows.inskription_1);
	SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_inskription_2, NULL, &geometric_menu.kox.arrows.inskription_2);
	SDL_RenderCopy(renderer, geometric_menu.kox.arrows.texture_exit, NULL, &geometric_menu.kox.arrows.exit);
}



//перевыделение
void rehigh(geometricMenuType& geometric_menu, int x_pic, int y_pic, int w_pic, int h_pic, int x_txt, int y_txt, int w_txt, int h_txt) {
	geometric_menu.highlighting_pic.x = x_pic;
	geometric_menu.highlighting_pic.y = y_pic;
	geometric_menu.highlighting_pic.w = w_pic;
	geometric_menu.highlighting_pic.h = h_pic;
	geometric_menu.highlighting_txt.x = x_txt;
	geometric_menu.highlighting_txt.y = y_txt;
	geometric_menu.highlighting_txt.w = w_txt;
	geometric_menu.highlighting_txt.h = h_txt;
}
//создание всех текстур
int init_start_tringle(SDL_Renderer* renderer, geometricMenuType& geometric_menu) {
	char path_left_arrow[] = "left_arrow.bmp", path_right_arrow[] = "right_arrow.bmp", path_exit[] = "exit.bmp", path_insk_2[] = "razmernost.bmp", highlighting[] = "high_2.bmp";

	geometric_menu.tringle.arrows.texture_left_change_1 = create_texture(renderer, path_left_arrow);
	if (geometric_menu.tringle.arrows.texture_left_change_1 == NULL) {
		cout << "error" << endl;
		return 1;
	}
	init_rect(geometric_menu.tringle.arrows.left_change_1, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);

	geometric_menu.tringle.arrows.texture_right_change_1 = create_texture(renderer, path_right_arrow);
	if (geometric_menu.tringle.arrows.texture_right_change_1 == NULL) {
		cout << "error_2" << endl;
		return 1;
	}
	init_rect(geometric_menu.tringle.arrows.right_change_1, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);

	geometric_menu.tringle.arrows.texture_inskription_1 = create_texture(renderer, path_insk_2);
	if (geometric_menu.tringle.arrows.texture_inskription_1 == NULL) {
		cout << "error_3" << endl;
		return 1;
	}
	init_rect(geometric_menu.tringle.arrows.inskription_1, arrows_text_1_x, arrows_text_1_y, arrows_text_width, arrows_text_height);

	geometric_menu.tringle.arrows.texture_highlighting = create_texture(renderer, highlighting);
	if (geometric_menu.tringle.arrows.texture_highlighting == NULL) {
		cout << "error_4" << endl;
		return 1;
	}


	geometric_menu.tringle.arrows.texture_exit = create_texture(renderer, path_exit);
	if (geometric_menu.texture_exit == NULL) {
		cout << "error" << endl;
		return 1;
	}

	return 0;
}
//рисует все стрелки и надписи
void show_interface_tringle(SDL_Renderer* renderer, geometricMenuType geometric_menu) {
	SDL_RenderCopy(renderer, geometric_menu.tringle.arrows.texture_left_change_1, NULL, &geometric_menu.tringle.arrows.left_change_1);
	SDL_RenderCopy(renderer, geometric_menu.tringle.arrows.texture_right_change_1, NULL, &geometric_menu.tringle.arrows.right_change_1);
	SDL_RenderCopy(renderer, geometric_menu.tringle.arrows.texture_inskription_1, NULL, &geometric_menu.tringle.arrows.inskription_1);
	SDL_RenderCopy(renderer, geometric_menu.tringle.arrows.texture_exit, NULL, &geometric_menu.tringle.arrows.exit);
}
//изменяет координаты прямоугольника, который выделяет текст или меню
void rehigh(tringleType& tringle, int x_pic, int y_pic, int w_pic, int h_pic) {
	tringle.arrows.highilighting_rect.x = x_pic;
	tringle.arrows.highilighting_rect.y = y_pic;
	tringle.arrows.highilighting_rect.w = w_pic;
	tringle.arrows.highilighting_rect.h = h_pic;

}
//обработчик событий
bool events_in_tringle(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu) {

	bool change = false;
	if ((event.button.x >= arrows_left_1_x) && (event.button.x <= arrows_left_1_x + arrows_width) && (event.button.y >= arrows_left_1_y) && (event.button.y <= arrows_left_1_y + arrows_height)) {

		rehigh(geometric_menu.tringle, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.tringle.arrows.texture_highlighting, NULL, &geometric_menu.tringle.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.tringle.iteration > 1) {
				geometric_menu.tringle.iteration--;

				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= arrows_right_1_x) && (event.button.x <= arrows_right_1_x + arrows_width) && (event.button.y >= arrows_right_1_y) && (event.button.y <= arrows_right_1_y + arrows_height)) {

		rehigh(geometric_menu.tringle, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.tringle.arrows.texture_highlighting, NULL, &geometric_menu.tringle.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.tringle.iteration < max_iteration_tringle) {
				geometric_menu.tringle.iteration++;
				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {

		rehigh(geometric_menu.tringle, coordinateX_exit, coordinateY_exit, width_exit, height_exit);
		SDL_RenderCopy(renderer, geometric_menu.tringle.arrows.texture_highlighting, NULL, &geometric_menu.tringle.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			numbermenu = 3;
			geometric_menu.init_flag = true;
			geometric_menu.tringle.iteration = 1;
			SDL_Delay(200);

		}


	}
	return change;
}
// перерисовка
void tringlemenu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu) {
	show_interface_tringle(renderer, geometric_menu);

	if (events_in_tringle(renderer, geometric_menu, event, numbermenu)) {
		SDL_SetRenderDrawColor(renderer, 204, 249, 247, 0);
		SDL_RenderClear(renderer);
		if (geometric_menu.tringle.iteration >= 7) {
			//func_inskription("Фрактал рисуется");
			SDL_RenderPresent(renderer);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawLine(renderer, int(Screen_Width * 2 / 8), int(Screen_Height * 7 / 10), int(Screen_Width * 6 / 8), Screen_Height * 7 / 10);
		SDL_RenderDrawLine(renderer, int(Screen_Width * 2 / 8), int(Screen_Height * 7 / 10), int(Screen_Width / 2), int(Screen_Height / 9));
		SDL_RenderDrawLine(renderer, int(Screen_Width / 2), int(Screen_Height / 9), int(Screen_Width * 6 / 8), int(Screen_Height * 7 / 10));

		functionSierpinskitriangle(renderer, Screen_Width * 2 / 8, Screen_Height * 7 / 10, Screen_Width / 2, Screen_Height / 9, Screen_Width * 6 / 8, Screen_Height * 7 / 10, 0, geometric_menu.tringle.iteration);
		show_interface_tringle(renderer, geometric_menu);
	}

}




//перевыделение
void rehigh(treeType& tree, int x, int y, int w, int h) {
	tree.arrows.highilighting_rect.x = x;
	tree.arrows.highilighting_rect.y = y;
	tree.arrows.highilighting_rect.w = w;
	tree.arrows.highilighting_rect.h = h;
}
//создание всех текстур
int init_start_tree(SDL_Renderer* renderer, geometricMenuType& geometric_menu) {
	char path_left_arrow[] = "left_arrow.bmp", path_right_arrow[] = "right_arrow.bmp", path_exit[] = "exit.bmp", path_insk_1[] = "angle.bmp", path_insk_2[] = "razmernost.bmp", highlighting[] = "high_2.bmp";
	geometric_menu.tree.arrows.texture_left_change_1 = create_texture(renderer, path_left_arrow);
	if (geometric_menu.tree.arrows.texture_left_change_1 == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}
	init_rect(geometric_menu.tree.arrows.left_change_1, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);
	geometric_menu.tree.arrows.texture_left_change_2 = create_texture(renderer, path_left_arrow);
	if (geometric_menu.tree.arrows.texture_left_change_2 == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}

	init_rect(geometric_menu.tree.arrows.left_change_2, arrows_left_2_x, arrows_left_2_y, arrows_width, arrows_height);

	geometric_menu.tree.arrows.texture_right_change_1 = create_texture(renderer, path_right_arrow);
	if (geometric_menu.tree.arrows.texture_right_change_1 == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}

	init_rect(geometric_menu.tree.arrows.right_change_1, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);
	geometric_menu.tree.arrows.texture_right_change_2 = create_texture(renderer, path_right_arrow);
	if (geometric_menu.tree.arrows.texture_right_change_2 == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}
	init_rect(geometric_menu.tree.arrows.right_change_2, arrows_right_2_x, arrows_right_2_y, arrows_width, arrows_height);



	geometric_menu.tree.arrows.texture_inskription_1 = create_texture(renderer, path_insk_1);
	if (geometric_menu.tree.arrows.texture_inskription_1 == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}
	init_rect(geometric_menu.tree.arrows.inskription_1, arrows_text_1_x, arrows_text_1_y, arrows_text_width, arrows_height);

	geometric_menu.tree.arrows.texture_inskription_2 = create_texture(renderer, path_insk_2);
	if (geometric_menu.tree.arrows.texture_inskription_2 == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}
	init_rect(geometric_menu.tree.arrows.inskription_2, arrows_text_2_x, arrows_text_2_y, arrows_text_width, arrows_height);

	geometric_menu.tree.arrows.texture_exit = create_texture(renderer, path_exit);
	if (geometric_menu.tree.arrows.texture_exit == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}
	geometric_menu.tree.arrows.texture_highlighting = create_texture(renderer, highlighting);
	if (geometric_menu.tree.arrows.texture_highlighting == NULL) {
		cout << "Не удалось открыть файл <<init_start_tree>>" << endl;
		return 1;
	}
	return 0;
}
//рисует все стрелки и надписи
void show_interface_tree(SDL_Renderer* renderer, geometricMenuType geometric_menu) {

	SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_left_change_1, NULL, &geometric_menu.tree.arrows.left_change_1);
	SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_right_change_1, NULL, &geometric_menu.tree.arrows.right_change_1);
	SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_left_change_1, NULL, &geometric_menu.tree.arrows.left_change_2);
	SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_right_change_1, NULL, &geometric_menu.tree.arrows.right_change_2);

	SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_inskription_1, NULL, &geometric_menu.tree.arrows.inskription_1);
	SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_inskription_2, NULL, &geometric_menu.tree.arrows.inskription_2);
	SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_exit, NULL, &geometric_menu.tree.arrows.exit);
}
//обработчик событий
bool events_in_tree(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu) {
	bool change = false;

	if ((event.button.x >= arrows_left_1_x) && (event.button.x <= arrows_left_1_x + arrows_width) && (event.button.y >= arrows_left_1_y) && (event.button.y <= arrows_left_1_y + arrows_height)) {

		rehigh(geometric_menu.tree, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_highlighting, NULL, &geometric_menu.tree.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.tree.angle >= 10) {
				geometric_menu.tree.angle -= 10;
				change = true;
				SDL_Delay(200);
			}
		}
	}
	else if ((event.button.x >= arrows_left_2_x) && (event.button.x <= arrows_left_2_x + arrows_width) && (event.button.y >= arrows_left_2_y) && (event.button.y <= arrows_left_2_y + arrows_height)) {

		rehigh(geometric_menu.tree, arrows_left_2_x, arrows_left_2_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_highlighting, NULL, &geometric_menu.tree.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.tree.iteration > 2) {
				geometric_menu.tree.iteration--;
				change = true;
				SDL_Delay(200);
			}
		}
	}
	else if ((event.button.x >= arrows_right_1_x) && (event.button.x <= arrows_right_1_x + arrows_width) && (event.button.y >= arrows_right_1_y) && (event.button.y <= arrows_right_1_y + arrows_height)) {

		rehigh(geometric_menu.tree, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_highlighting, NULL, &geometric_menu.tree.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (geometric_menu.tree.angle <= 80) {
				geometric_menu.tree.angle += 10;
				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= arrows_right_2_x) && (event.button.x <= arrows_right_2_x + arrows_width) && (event.button.y >= arrows_right_2_y) && (event.button.y <= arrows_right_2_y + arrows_height)) {

		rehigh(geometric_menu.tree, arrows_right_2_x, arrows_right_2_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_highlighting, NULL, &geometric_menu.tree.arrows.highilighting_rect);

		if (event.type == SDL_MOUSEBUTTONDOWN)

		{
			if (geometric_menu.tree.iteration < max_iteration_tree - 1) {
				geometric_menu.tree.iteration++;
				change = true;
				SDL_Delay(200);
			}
		}
	}
	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {

		rehigh(geometric_menu.tree, coordinateX_exit, coordinateY_exit, width_exit, height_exit);
		SDL_RenderCopy(renderer, geometric_menu.tree.arrows.texture_highlighting, NULL, &geometric_menu.tree.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			numbermenu = 3;
			geometric_menu.init_flag = true;
			geometric_menu.tree.iteration = 2;
			geometric_menu.tree.angle = 30;
			SDL_Delay(200);

		}


	}
	return change;
}
// перерисовка
void treemenu(SDL_Renderer* renderer, geometricMenuType& geometric_menu, SDL_Event event, int& numbermenu) {

	show_interface_tree(renderer, geometric_menu);

	if (events_in_tree(renderer, geometric_menu, event, numbermenu)) {
		SDL_SetRenderDrawColor(renderer, 204, 249, 247, 0);
		SDL_RenderClear(renderer);
		if (geometric_menu.tree.iteration >= 7) {
			//func_inskription("Фрактал рисуется");
			SDL_RenderPresent(renderer);
		}

		drawpifagorTree(renderer, double(Screen_Width / 2), double(Screen_Height - int(Screen_Height / 4)), Screen_Height / 5, 0, 0, geometric_menu.tree.angle, geometric_menu.tree.iteration);

		show_interface_tree(renderer, geometric_menu);

	}

}











