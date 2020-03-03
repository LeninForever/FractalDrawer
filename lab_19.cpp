
#include<iostream>
#include"SDL.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960
int QuitFromSDL()
{
	
	SDL_Quit();
	return 0;
}
int main(int argc, char** argv)//??
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) { //инициализируем подсистему SDL (видео) Init возвращает -1 при неудаче и 0 при успехе 
		std::cout << "Не удалось инициализировать SDL";
		QuitFromSDL();
	}// функция выхода при неудачном запуске 
	else {

		SDL_Window* window = NULL; // создаём указатель на окно
			// создаём само окно:
	window = SDL_CreateWindow(u8"Копелиович", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
							//Заголовок окна	позиция окна по х		позиция окна по у		высота окна		ширина окна		флаг
	if (window == NULL) {
		std::cout << "Не удалось создать окно";
		QuitFromSDL();
	}
	else {
		SDL_Surface * screenSurface = NULL; // создаём указатель на поверхность
	//	std::cout << screenSurface;
		screenSurface = SDL_GetWindowSurface(window);// создаём поверхность
		//Заполняем ее цветом
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 142, 128, 168)); 
		//Обновляем поверхность
		SDL_UpdateWindowSurface(window);
		SDL_Surface* Image = SDL_LoadBMP("Lab.bmp");
		if (Image == NULL) {
			std::cout <<"Не удалось открыть изображение";
			SDL_DestroyWindow(window);
			QuitFromSDL();
			}
		else {
			SDL_Rect dest;
			dest.x = SCREEN_WIDTH-285;
			dest.y = SCREEN_HEIGHT-225;
			
			//SDL_UpdateWindowSurface(window);
			SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255, 251, 240));
			SDL_BlitSurface(Image, NULL, screenSurface, &dest);//Копирует изображение на поверхность
			SDL_UpdateWindowSurface(window);
			//Ждем 2 секунды
			SDL_Delay(5000);
		}
		//Удаляем из памяти окно
		SDL_DestroyWindow(window);

		SDL_FreeSurface(screenSurface);//удаляем поверхность
		SDL_FreeSurface(Image);// Удаляем изображение

	}
	} 
	//Выход из SDL
	SDL_Quit();
	return 1;
}

