#pragma once


#define Screen_Width 1200
#define Screen_Height 800

// параметры первого меню
#define size_width_panel Screen_Width / 5
#define size_height_panel Screen_Width / 5

#define size_width_inscription  Screen_Width / 3
#define size_height_inscription Screen_Height / 7

#define coordinateX_geometric Screen_Width / 6- size_width_panel / 2
#define coordinateY_geometric Screen_Height / 8

#define coordinateX_dynamic Screen_Width*4 / 5-size_width_panel / 2
#define coordinateY_dynamic Screen_Height / 8

#define coordinateX_stohastic Screen_Width / 2- size_width_panel / 2-size_width_panel/8
#define coordinateY_stohastic Screen_Height / 5+ size_height_panel*2 / 3

#define  coordinateX_inscription_geometric  coordinateX_geometric- (size_width_inscription- size_width_panel)/2
#define  coordinateY_inscription_geometric coordinateY_geometric+size_height_panel

#define  coordinateX_inscription_dynamic coordinateX_dynamic - (size_width_inscription - size_width_panel) / 2
#define  coordinateY_inscription_dynamic coordinateY_dynamic + size_height_panel

#define  coordinateX_inscription_stohastic coordinateX_stohastic - (size_width_inscription - size_width_panel) / 2
#define  coordinateY_inscription_stohastic coordinateY_stohastic + size_height_panel


// кнопка выхода
#define coordinateX_exit Screen_Width/20
#define coordinateY_exit Screen_Height*17/20
#define width_exit Screen_Width/10
#define height_exit Screen_Height/10

//параметры второго (для геометрических фракталов) меню

#define gcoordinateX_kox Screen_Width / 6- size_width_panel / 2
#define gcoordinateY_kox Screen_Height / 8

#define gcoordinateX_tringle Screen_Width*4 / 5-size_width_panel / 2
#define gcoordinateY_tringle Screen_Height / 8

#define gcoordinateX_tree Screen_Width / 2- size_width_panel / 2-size_width_panel/8
#define gcoordinateY_tree Screen_Height / 5+ size_height_panel*2 / 3

#define  gcoordinateX_inscription_kox gcoordinateX_kox- (size_width_inscription- size_width_panel)/2
#define  gcoordinateY_inscription_kox gcoordinateY_kox+size_height_panel

#define  gcoordinateX_inscription_tringle gcoordinateX_tringle - (size_width_inscription - size_width_panel) / 2
#define  gcoordinateY_inscription_tringle gcoordinateY_tringle + size_height_panel

#define  gcoordinateX_inscription_tree gcoordinateX_tree - (size_width_inscription - size_width_panel) / 2
#define  gcoordinateY_inscription_tree gcoordinateY_tree + size_height_panel

#define gsize_width_panel Screen_Width / 5
#define gsize_height_panel Screen_Width / 5

#define gsize_width_inscription  Screen_Width / 3
#define gsize_height_inscription Screen_Height / 7

//параметры для 3 меню (алгебраические фракталы)

#define asize_width_panel Screen_Width / 5
#define asize_height_panel Screen_Width / 5

#define asize_width_inscription  Screen_Width / 3
#define asize_height_inscription Screen_Height / 7

#define acoordinateX_mandelbrot Screen_Width / 5- asize_width_panel / 2
#define acoordinateY_mandelbrot Screen_Height / 4

#define acoordinateX_zhulia Screen_Width*4 / 5-asize_width_panel / 2
#define acoordinateY_zhulia Screen_Height / 4

#define  acoordinateX_inscription_mandelbrot acoordinateX_mandelbrot- (asize_width_inscription - asize_width_panel)/2
#define  acoordinateY_inscription_mandelbrot acoordinateY_mandelbrot + asize_height_panel

#define  acoordinateX_inscription_zhulia acoordinateX_zhulia - (asize_width_inscription - asize_width_panel) / 2
#define  acoordinateY_inscription_zhulia acoordinateY_inscription_mandelbrot

//параметры для 4 меню (стохастические фракталы)
#define s_size_width_panel Screen_Width / 5
#define s_size_height_panel Screen_Width / 5

#define s_size_width_inscription  Screen_Width / 3
#define s_size_height_inscription Screen_Height / 7

#define scoordinateX_dendrit Screen_Width / 6- s_size_width_panel / 2
#define scoordinateY_dendrit Screen_Height / 8

#define scoordinateX_lace Screen_Width*4 / 5-s_size_width_panel / 2
#define scoordinateY_lace Screen_Height / 8

#define scoordinateX_list Screen_Width / 2- s_size_width_panel / 2-s_size_width_panel/8
#define scoordinateY_list Screen_Height / 5+ s_size_height_panel*2 / 3

#define  scoordinateX_inscription_dendrit scoordinateX_dendrit - (s_size_width_inscription- s_size_width_panel)/2
#define  scoordinateY_inscription_dendrit scoordinateY_dendrit + s_size_height_panel

#define  scoordinateX_inscription_lace scoordinateX_lace - (s_size_width_inscription - s_size_width_panel) / 2
#define  scoordinateY_inscription_lace scoordinateY_lace + s_size_height_panel

#define  scoordinateX_inscription_list scoordinateX_list- (s_size_width_inscription - s_size_width_panel) / 2
#define  scoordinateY_inscription_list scoordinateY_list + s_size_height_panel


//координаты и размеры стрелок для переключателей в рисовальщике

#define arrows_width Screen_Width / 20
#define arrows_height Screen_Height / 20

#define arrows_text_width Screen_Width / 8
#define arrows_text_height Screen_Height / 20

#define arrows_right_1_x Screen_Width * 18 / 19 
#define arrows_right_2_x arrows_right_1_x
#define arrows_right_3_x arrows_right_2_x 

#define arrows_left_1_x arrows_right_1_x -arrows_width * 15 / 9 
#define arrows_left_2_x arrows_right_2_x-arrows_width * 15 / 9
#define arrows_left_3_x arrows_right_3_x-arrows_width * 10 / 9

#define arrows_left_1_y Screen_Height * 17 / 20
#define arrows_left_2_y Screen_Height * 19 / 20
#define arrows_left_3_y Screen_Height * 17 / 10

#define arrows_right_1_y arrows_left_1_y
#define arrows_right_2_y arrows_left_2_y
#define arrows_right_3_y arrows_left_3_y

#define arrows_text_1_x arrows_left_1_x - arrows_text_width * 10 / 9
#define arrows_text_1_y arrows_left_1_y

#define arrows_text_2_x arrows_left_2_x - arrows_text_width * 10 / 9
#define arrows_text_2_y arrows_left_2_y

#define arrows_text_3_x arrows_left_2_x - arrows_text_width * 10 / 9
#define arrows_text_3_y arrows_left_3_y

// максиимальные и минимальные итерации итерации

#define max_iteration_kox  9
#define max_iteration_tringle 10
#define max_iteration_tree 18

#define max_iteration_mandelbrot 800
#define max_iteration_zhulia 150
#define min_iteration_mandelbrot 100

#define min_iteration_zhulia 25

#define max_incline_dendrit 0.5
#define max_distoration 0.25
#define max_iskr_lace 1.5
#define max_kuchnost 1000000