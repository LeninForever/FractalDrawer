//#include"H"
//SDL_Texture* create_texture(SDL_Renderer* renderer, char* path) {
//	SDL_Texture* texture = NULL;
//	SDL_Surface* surface = IMG_Load(path);
//	if (surface == NULL) {
//		cout << "Произошла ошибка при открытии файла" << endl;
//		return NULL;
//	}
//	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
//	texture = SDL_CreateTextureFromSurface(renderer, surface);
//	SDL_FreeSurface(surface);
//	return texture;
//};
//
//void soundscroll(Mix_Chunk* sound)
//{
//	sound = Mix_LoadWAV("11.wav");
//	if (sound == NULL)
//		cout << "!!!!";
//	Mix_PlayChannel(-1, sound, 0);
//}
//void destroy_all_textures(mainmenuType& menu, secondMenuType& second_menu, fracmenuType& fractals_menu) {
//
//	//first
//	SDL_DestroyTexture(menu.texturebackground);
//	SDL_DestroyTexture(menu.texturehighlighting);
//	//second_menu
//	SDL_DestroyTexture(second_menu.texture_geometricFractals);
//	SDL_DestroyTexture(second_menu.texture_dynamicFractals);
//	SDL_DestroyTexture(second_menu.texture_stohasticFractals);
//	SDL_DestroyTexture(second_menu.texture_fon);
//	SDL_DestroyTexture(second_menu.texture_highlighting_pic);
//	SDL_DestroyTexture(second_menu.texture_highlighting_txt);
//	SDL_DestroyTexture(second_menu.texture_text_geometricFractals);
//	SDL_DestroyTexture(second_menu.texture_text_dynamicFractals);
//	SDL_DestroyTexture(second_menu.texture_text_stohasticFractals);
//	SDL_DestroyTexture(second_menu.texture_exit);
//	//third menu (geometric)
//
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_fon);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_pic_kox);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_pic_tree);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_pic_tringle);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_txt_kox);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_txt_tree);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_highlighting_txt_tringle);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_kox);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_text_kox);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_text_tree);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_text_tringle);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_tree);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_tringle);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.texture_exit);
//
//	//4 menu (динамические)
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_fon);
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_highlighting_pic);
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_highlighting_txt);
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_mandelbrot);
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_zhulia);
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_text_mandelbrot);
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_text_zhulia);
//	SDL_DestroyTexture(fractals_menu.alg_menu.texture_exit);
//	//5 menu (стохастические)
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_fon);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_highlighting_pic);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_highlighting_txt);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_dendrit);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_lace);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_list);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_text_dendrit);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_text_lace);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_text_list);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.texture_exit);
//	//kox
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_left_change_2);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_right_change_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_right_change_2);
//
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_inskription_2);
//
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.kox.arrows.texture_exit);
//	//tringle
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_right_change_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tringle.arrows.texture_exit);
//
//	//tree
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_right_change_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_left_change_2);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_right_change_2);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_inskription_2);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.geometric_menu.tree.arrows.texture_exit);
//
//	//mandelbrot
//	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_exit);
//	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.alg_menu.mandelbrot.arrows.texture_right_change_1);
//
//	//zhulia
//	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_exit);
//	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.alg_menu.zhulia.arrows.texture_right_change_1);
//	//dendrit
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_right_change_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_left_change_2);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_right_change_2);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_inskription_2);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.dendrit.arrows.texture_exit);
//	//lace
//	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_right_change_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.lace.arrows.texture_exit);
//	//list
//	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_left_change_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_right_change_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_inskription_1);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_highlighting);
//	SDL_DestroyTexture(fractals_menu.stoh_menu.list.arrows.texture_exit);
//}
//
