#include"Header.h"

#include"alg.h"

#define scalecoef 1
struct complexType {
	double x;
	double y;
};
void drawMandelbrot(SDL_Renderer* renderer, int iterations)
{
	double xTemp, yTemp;
	double x, y;

	for (double a = -2; a < 2; a += 0.001)
	{
		for (double b = -2; b < 2; b += 0.001)
		{
			x = a, //x и y изначально - координаты исследуемой точки
				y = b;
			int iterator = 0; //счетчик
			while (iterator < iterations && x * x + y * y < 4)
			{
				xTemp = x * x - y * y + a;
				yTemp = 2 * x * y + b;
				x = xTemp;
				y = yTemp;
				iterator++;
			}
			if ((iterator <= iterations) && (iterator > 10)) {
				SDL_SetRenderDrawColor(renderer, iterator * 10, (255 / iterator + 1), iterator * 10, 255);
				SDL_RenderDrawPoint(renderer, Screen_Width / 2 + Screen_Width / 8 + Screen_Width / 4 * a, Screen_Height / 2 + Screen_Height / 4 * b * 1.5);

			}

		}
		SDL_RenderPresent(renderer);
	}

}
void drawzhulia(SDL_Renderer* renderer, int iter) {


	complexType z, t, c;
	int x, y, n;

	float mx, my; //обход плоскости
	const int max = 100; //область

	double koefY = 2; //масштаб по y// убрать
	double koefX = 1; //масштаб по x // убрать 


	mx = Screen_Width / scalecoef;// +koefX;
	my = Screen_Height / scalecoef;
	for (float x = -mx; x <= mx; x += 1.0 / (scalecoef * 1.0)) {
		for (float y = -my; y < my; y += 1.0 / (scalecoef * 1.0)) {

			n = 0;
			z.x = x * 0.005;
			z.y = y * 0.005;
			c.x = 0.00011;
			c.y = -0.66;
			while (((z.x * z.x) + (z.y * z.y) < max) && (n < iter)) {
				t = z;
				//{z^2 + c}
				z.x = t.x * t.x - t.y * t.y;
				z.y = 2 * t.x * t.y;
				z.x = z.x + c.x;
				z.y = z.y + c.y;
				n++;
			};
			if (n <= iter) {


				if ((n >= iter - iter / 2) && (n <= iter)) {

					SDL_SetRenderDrawColor(renderer, 0, n * 255 / iter * 4, 255, 255);
					SDL_RenderDrawPoint(renderer, Screen_Width / 2 - Screen_Width / 8 + Screen_Width / 6 + scalecoef * x, Screen_Height / koefY - scalecoef * y);
				}
				else if (n < iter) {
					SDL_SetRenderDrawColor(renderer, n * 255 / iter * 3, n * 255 / iter, n * 255 / iter, 255);
					SDL_RenderDrawPoint(renderer, Screen_Width / 2 - Screen_Width / 8 + Screen_Width / 6 + scalecoef * x, Screen_Height / koefY - scalecoef * y);
				}
				else if (n == iter) {
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
					SDL_RenderDrawPoint(renderer, Screen_Width / 2 - Screen_Width / 8 + Screen_Width / 6 + scalecoef * x, Screen_Height / koefY - scalecoef * y);
				}
			}

		}
		SDL_RenderPresent(renderer);
	}

}


void rehigh(algMenuType& alg_menu, int x_pic, int y_pic, int w_pic, int h_pic, int x_txt, int y_txt, int w_txt, int h_txt) {
	alg_menu.highlighting_pic.x = x_pic;
	alg_menu.highlighting_pic.y = y_pic;
	alg_menu.highlighting_pic.w = w_pic;
	alg_menu.highlighting_pic.h = h_pic;
	alg_menu.highlighting_txt.x = x_txt;
	alg_menu.highlighting_txt.y = y_txt;
	alg_menu.highlighting_txt.w = w_txt;
	alg_menu.highlighting_txt.h = h_txt;
}

int init_alg_menu(SDL_Renderer* renderer, algMenuType& alg_menu) {

	char path_to_main_menu[] = "for2menu.bmp", path_to_picture_m[] = "mandelbrot.bmp", path_to_picture_zhulia[] = "dynamic.bmp", path_to_exit[] = "exit.bmp";
	char text_mandelbrot[] = "ta_1.bmp", text_zhulia[] = "ta_2.bmp", highlighting[] = "2highlighting.bmp";
	
	alg_menu.texture_fon = create_texture(renderer, path_to_main_menu);
	if (alg_menu.texture_fon == NULL) {
		cout << "Ошибка при открытии файла (<<init_alg_menu>>)" << endl;
		return 1;

	}
	
	alg_menu.texture_mandelbrot = create_texture(renderer, path_to_picture_m);
	if (alg_menu.texture_mandelbrot == NULL) {
		cout << "Ошибка при открытии файла (<<init_alg_menu>>)" << endl;
		return 1;

	}
	alg_menu.texture_zhulia = create_texture(renderer, path_to_picture_zhulia);
	if (alg_menu.texture_zhulia== NULL) {
		cout << "Ошибка при открытии файла (<<init_alg_menu>>)" << endl;
		return 1;

	}
	alg_menu.texture_text_mandelbrot= create_texture(renderer, text_mandelbrot);
	if (alg_menu.texture_text_mandelbrot == NULL) {
		cout << "Ошибка при открытии файла (<<init_alg_menu>>)" << endl;
		return 1;

	}
	alg_menu.texture_text_zhulia = create_texture(renderer, text_zhulia);
	if (alg_menu.texture_text_zhulia == NULL) {
		cout << "Ошибка при открытии файла (<<init_alg_menu>>)" << endl;
		return 1;

	}
	
	alg_menu.texture_highlighting_pic = create_texture(renderer, highlighting);
	if (alg_menu.texture_highlighting_pic == NULL) {
		cout << "Ошибка при открытии файла (<<init_alg_menu>>)" << endl;
		return 1;

	}
	alg_menu.texture_highlighting_txt = create_texture(renderer, highlighting);
	if (alg_menu.texture_highlighting_txt== NULL) {
		cout << "Ошибка при открытии файла (<<init_alg_menu>>)" << endl;
		return 1;

	
	}

	alg_menu.texture_exit = create_texture(renderer, path_to_exit);
	if (alg_menu.texture_exit == NULL) {
		cout << "texture_exit (<<init_alg_menu>>) wasn't open" << endl;
		return 1;
	}

	return 0;
}

void destroy_alg_texture(algMenuType& alg_menu){

}

void show_alg_menu(SDL_Renderer* renderer, algMenuType alg_menu) {
	SDL_RenderCopy(renderer, alg_menu.texture_fon, NULL, &alg_menu.fon);
	SDL_RenderCopy(renderer, alg_menu.texture_mandelbrot, NULL, &alg_menu.panel_mandelbrot);
	
	SDL_RenderCopy(renderer, alg_menu.texture_zhulia, NULL, &alg_menu.panel_zhulia);
	SDL_RenderCopy(renderer, alg_menu.texture_text_mandelbrot, NULL, &alg_menu.text_mandelbrot);
	
	SDL_RenderCopy(renderer, alg_menu.texture_text_zhulia, NULL, &alg_menu.text_zhulia);
	SDL_RenderCopy(renderer, alg_menu.texture_exit, NULL, &alg_menu.exit);
}

void  events_in_alg_menu(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu, int& numfrac) {
	if (((event.button.x >= acoordinateX_mandelbrot) && (event.button.x <= acoordinateX_mandelbrot + asize_width_panel) && (event.button.y >= acoordinateY_mandelbrot) && (event.button.y <= acoordinateY_mandelbrot + asize_height_panel)) || ((event.button.x >= acoordinateX_inscription_mandelbrot) && (event.button.x <= acoordinateX_inscription_mandelbrot + asize_width_inscription) && (event.button.y >= acoordinateY_inscription_mandelbrot) && (event.button.y <= acoordinateY_inscription_mandelbrot + asize_height_inscription))) {
		rehigh(alg_menu, acoordinateX_mandelbrot, acoordinateY_mandelbrot, asize_width_panel, asize_height_panel, acoordinateX_inscription_mandelbrot, acoordinateY_inscription_mandelbrot, asize_width_inscription, asize_height_inscription);
		SDL_RenderCopy(renderer, alg_menu.texture_highlighting_pic, NULL, &alg_menu.highlighting_pic);
		SDL_RenderCopy(renderer, alg_menu.texture_highlighting_txt, NULL, &alg_menu.highlighting_txt);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 6;
			numfrac = 4;
			SDL_Delay(200);
		}

	}
	else if (((event.button.x >= acoordinateX_zhulia) && (event.button.x <= acoordinateX_zhulia + asize_width_panel) && (event.button.y >= acoordinateY_zhulia) && (event.button.y <= acoordinateY_zhulia + asize_height_panel)) || ((event.button.x >= acoordinateX_inscription_zhulia) && (event.button.x <= acoordinateX_inscription_zhulia + asize_width_inscription) && (event.button.y >= acoordinateY_inscription_zhulia) && (event.button.y <= acoordinateY_inscription_zhulia + asize_height_inscription))) {

		rehigh(alg_menu, acoordinateX_zhulia, acoordinateY_zhulia, asize_width_panel, asize_height_panel, acoordinateX_inscription_zhulia, acoordinateY_inscription_zhulia, asize_width_inscription, asize_height_inscription);
		SDL_RenderCopy(renderer, alg_menu.texture_highlighting_pic, NULL, &alg_menu.highlighting_pic);
		SDL_RenderCopy(renderer, alg_menu.texture_highlighting_txt, NULL, &alg_menu.highlighting_txt);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 6;
			numfrac = 5;
			SDL_Delay(200);
		}

	}
	
	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {
		alg_menu.highlighting_pic.x = coordinateX_exit;
		alg_menu.highlighting_pic.y = coordinateY_exit;
		alg_menu.highlighting_pic.w = width_exit;
		alg_menu.highlighting_pic.h = height_exit;
		SDL_RenderCopy(renderer, alg_menu.texture_highlighting_pic, NULL, &alg_menu.highlighting_pic);

		if (event.type == SDL_MOUSEBUTTONDOWN) {
			numbermenu = 2;
			SDL_Delay(200);
		}
	}

}




int init_start_mandelbrot(SDL_Renderer* renderer, algMenuType& alg_menu) {
	char path_left_arrow[] = "left_arrow.bmp", path_right_arrow[] = "right_arrow.bmp", path_exit[] = "exit.bmp", path_insk_2[] = "razmernost.bmp", highlighting[] = "high_2.bmp";

	alg_menu.mandelbrot.arrows.texture_left_change_1 = create_texture(renderer, path_left_arrow);
	if (alg_menu.mandelbrot.arrows.texture_left_change_1 == NULL) {
		cout << "error" << endl;
		return 1;
	}
	init_rect(alg_menu.mandelbrot.arrows.left_change_1, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);

	alg_menu.mandelbrot.arrows.texture_right_change_1 = create_texture(renderer, path_right_arrow);
	if (alg_menu.mandelbrot.arrows.texture_right_change_1 == NULL) {
		cout << "error_2" << endl;
		return 1;
	}
	init_rect(alg_menu.mandelbrot.arrows.right_change_1, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);

	alg_menu.mandelbrot.arrows.texture_inskription_1 = create_texture(renderer, path_insk_2);
	if (alg_menu.mandelbrot.arrows.texture_inskription_1 == NULL) {
		cout << "error_3" << endl;
		return 1;
	}
	init_rect(alg_menu.mandelbrot.arrows.inskription_1, arrows_text_1_x, arrows_text_1_y, arrows_text_width, arrows_text_height);

	alg_menu.mandelbrot.arrows.texture_highlighting = create_texture(renderer, highlighting);
	if (alg_menu.mandelbrot.arrows.texture_highlighting == NULL) {
		cout << "error_4" << endl;
		return 1;
	}


	alg_menu.mandelbrot.arrows.texture_exit = create_texture(renderer, path_exit);
	if (alg_menu.texture_exit == NULL) {
		cout << "error" << endl;
		return 1;
	}

	return 0;
}
//рисует все стрелки и надписи
void show_interface_mandelbrot(SDL_Renderer* renderer, algMenuType alg_menu) {
	SDL_RenderCopy(renderer, alg_menu.mandelbrot.arrows.texture_left_change_1, NULL, &alg_menu.mandelbrot.arrows.left_change_1);
	SDL_RenderCopy(renderer, alg_menu.mandelbrot.arrows.texture_right_change_1, NULL, &alg_menu.mandelbrot.arrows.right_change_1);
	SDL_RenderCopy(renderer, alg_menu.mandelbrot.arrows.texture_inskription_1, NULL, &alg_menu.mandelbrot.arrows.inskription_1);
	SDL_RenderCopy(renderer, alg_menu.mandelbrot.arrows.texture_exit, NULL, &alg_menu.mandelbrot.arrows.exit);
}
//изменяет координаты прямоугольника, который выделяет текст или меню
void rehigh(mandelbrotType& mandelbrot, int x_pic, int y_pic, int w_pic, int h_pic) {
	mandelbrot.arrows.highilighting_rect.x = x_pic;
	mandelbrot.arrows.highilighting_rect.y = y_pic;
	mandelbrot.arrows.highilighting_rect.w = w_pic;
	mandelbrot.arrows.highilighting_rect.h = h_pic;

}
//обработка событий
bool events_in_mandelbrot(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu) {

	bool change = false;
	if ((event.button.x >= arrows_left_1_x) && (event.button.x <= arrows_left_1_x + arrows_width) && (event.button.y >= arrows_left_1_y) && (event.button.y <= arrows_left_1_y + arrows_height)) {

		rehigh(alg_menu.mandelbrot, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, alg_menu.mandelbrot.arrows.texture_highlighting, NULL, &alg_menu.mandelbrot.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (alg_menu.mandelbrot.iterations > 200) {
				alg_menu.mandelbrot.iterations-=200;

				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= arrows_right_1_x) && (event.button.x <= arrows_right_1_x + arrows_width) && (event.button.y >= arrows_right_1_y) && (event.button.y <= arrows_right_1_y + arrows_height)) {

		rehigh(alg_menu.mandelbrot, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);
		SDL_RenderCopy(renderer, alg_menu.mandelbrot.arrows.texture_highlighting, NULL, &alg_menu.mandelbrot.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (alg_menu.mandelbrot.iterations < max_iteration_mandelbrot) {
				alg_menu.mandelbrot.iterations+=200;
				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {

		rehigh(alg_menu.mandelbrot, coordinateX_exit, coordinateY_exit, width_exit, height_exit);
		SDL_RenderCopy(renderer, alg_menu.mandelbrot.arrows.texture_highlighting, NULL, &alg_menu.mandelbrot.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			numbermenu = 4;
			alg_menu.init_flag = true;
			alg_menu.mandelbrot.iterations = 100;
			SDL_Delay(200);

		}


	}
	return change;
}
//интерфейс и перерисовка 
void mandelbrotmenu(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu) {
	show_interface_mandelbrot(renderer, alg_menu);

	if (events_in_mandelbrot(renderer, alg_menu, event, numbermenu)) {
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
		SDL_RenderClear(renderer);
		if (alg_menu.mandelbrot.iterations >= 7) {
			//func_inskription("Фрактал рисуется");
			SDL_RenderPresent(renderer);
		}
		
		

		drawMandelbrot(renderer, alg_menu.mandelbrot.iterations);
		show_interface_mandelbrot(renderer, alg_menu);
	}

}





int init_start_zhulia(SDL_Renderer* renderer, algMenuType& alg_menu) {
	char path_left_arrow[] = "left_arrow.bmp", path_right_arrow[] = "right_arrow.bmp", path_exit[] = "exit.bmp", path_insk_2[] = "razmernost.bmp", highlighting[] = "high_2.bmp";

	alg_menu.zhulia.arrows.texture_left_change_1 = create_texture(renderer, path_left_arrow);
	if (alg_menu.zhulia.arrows.texture_left_change_1 == NULL) {
		cout << "error" << endl;
		return 1;
	}
	init_rect(alg_menu.zhulia.arrows.left_change_1, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);

	alg_menu.zhulia.arrows.texture_right_change_1 = create_texture(renderer, path_right_arrow);
	if (alg_menu.zhulia.arrows.texture_right_change_1 == NULL) {
		cout << "error_2" << endl;
		return 1;
	}
	init_rect(alg_menu.zhulia.arrows.right_change_1, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);

	alg_menu.zhulia.arrows.texture_inskription_1 = create_texture(renderer, path_insk_2);
	if (alg_menu.zhulia.arrows.texture_inskription_1 == NULL) {
		cout << "error_3" << endl;
		return 1;
	}
	init_rect(alg_menu.zhulia.arrows.inskription_1, arrows_text_1_x, arrows_text_1_y, arrows_text_width, arrows_text_height);

	alg_menu.zhulia.arrows.texture_highlighting = create_texture(renderer, highlighting);
	if (alg_menu.zhulia.arrows.texture_highlighting == NULL) {
		cout << "error_4" << endl;
		return 1;
	}


	alg_menu.zhulia.arrows.texture_exit = create_texture(renderer, path_exit);
	if (alg_menu.texture_exit == NULL) {
		cout << "error" << endl;
		return 1;
	}

	return 0;
}
//рисует все стрелки и надписи
void show_interface_zhulia(SDL_Renderer* renderer, algMenuType alg_menu) {
	SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_left_change_1, NULL, &alg_menu.zhulia.arrows.left_change_1);
	SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_right_change_1, NULL, &alg_menu.zhulia.arrows.right_change_1);
	SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_inskription_1, NULL, &alg_menu.zhulia.arrows.inskription_1);
	SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_exit, NULL, &alg_menu.zhulia.arrows.exit);
	SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_highlighting, NULL, &alg_menu.zhulia.arrows.highilighting_rect);
}
//изменяет координаты прямоугольника, который выделяет текст или меню
void rehigh(zhuliaType& zhulia, int x_pic, int y_pic, int w_pic, int h_pic) {
	zhulia.arrows.highilighting_rect.x = x_pic;
	zhulia.arrows.highilighting_rect.y = y_pic;
	zhulia.arrows.highilighting_rect.w = w_pic;
	zhulia.arrows.highilighting_rect.h = h_pic;

}

bool events_in_zhulia(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu) {

	bool change = false;
	if ((event.button.x >= arrows_left_1_x) && (event.button.x <= arrows_left_1_x + arrows_width) && (event.button.y >= arrows_left_1_y) && (event.button.y <= arrows_left_1_y + arrows_height)) {

		rehigh(alg_menu.zhulia, arrows_left_1_x, arrows_left_1_y, arrows_width, arrows_height);
		//SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_highlighting, NULL, &alg_menu.zhulia.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (alg_menu.zhulia.iteration > 25) {
				alg_menu.zhulia.iteration -= 20;

				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= arrows_right_1_x) && (event.button.x <= arrows_right_1_x + arrows_width) && (event.button.y >= arrows_right_1_y) && (event.button.y <= arrows_right_1_y + arrows_height)) {

		rehigh(alg_menu.zhulia, arrows_right_1_x, arrows_right_1_y, arrows_width, arrows_height);
		//SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_highlighting, NULL, &alg_menu.zhulia.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (alg_menu.zhulia.iteration < max_iteration_zhulia) {
				alg_menu.zhulia.iteration += 20;
				change = true;
				SDL_Delay(200);
			}
		}
	}

	else if ((event.button.x >= coordinateX_exit) && (event.button.x <= coordinateX_exit + width_exit) && (event.button.y >= coordinateY_exit) && (event.button.y <= coordinateY_exit + height_exit)) {

		rehigh(alg_menu.zhulia, coordinateX_exit, coordinateY_exit, width_exit, height_exit);
		//SDL_RenderCopy(renderer, alg_menu.zhulia.arrows.texture_highlighting, NULL, &alg_menu.zhulia.arrows.highilighting_rect);
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			numbermenu = 4;
			alg_menu.init_flag = true;
			alg_menu.zhulia.iteration = 20;
			SDL_Delay(200);

		}

		else
			rehigh(alg_menu.zhulia, 0, 0, 0, 0);
	}
	return change;
}

void zhuliamenu(SDL_Renderer* renderer, algMenuType& alg_menu, SDL_Event event, int& numbermenu) {
	show_interface_zhulia(renderer, alg_menu);

	if (events_in_zhulia(renderer, alg_menu, event, numbermenu)) {
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
		SDL_RenderClear(renderer);
		


		drawzhulia(renderer, alg_menu.zhulia.iteration);
		show_interface_zhulia(renderer, alg_menu);
	}

}