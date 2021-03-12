﻿#define _USE_MATH_DEFINES

#include<allegro5/allegro.h>													
#include<allegro5/allegro_font.h>	
#include <allegro5/allegro_primitives.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include "Game.h";




bool detectColision(int x1, int y1, int x2, int y2)
{
	if (x1 < 0 || x2 > DISP_WIDTH)
		return true;
	if (y1 < 0 || y2 > DISP_HEIGHT)
		return true;

	return false;
}

double losujKierunek()
{
	// funkcja losuje  wartosci kierunku double 0-360
	const int min = 0;
	const int max = 360;
	double los = (double)rand() / RAND_MAX;
	return min + los * (max - min);
}

int losujPozycjeKola()
{
	// losuje pozycje kola wartosc pozycji int z przedzialu 1-599
	const int min = 1;
	const int max = 599;
	int wynik;
	return wynik = (rand() % max) + min;
}

double przeliczCosNaKat()
{
	return 0.0;
}

//double x1, double x2, double y1, double y2

double wyliczCosinus(Vector v1,Vector v2)
{
	double upper = ((v1.dir_x * v2.dir_x) + (v1.dir_y * v2.dir_y));
	double lower = sqrt(pow(v1.dir_x,2)+ pow(v1.dir_y, 2))* sqrt(pow(v2.dir_x, 2) + pow(v2.dir_y, 2));

	return std::cos(upper / lower)* M_PI;
}


Vector randVector() {
	Vector temp = Vector();
	temp.dir_x = losujKierunek();
	temp.dir_y = losujKierunek();

	return temp;
}

// </funkcje>
void main(void) {
	Vector top = Vector();
	top.dir_x = 180;
	top.dir_y = 0;


	Vector customV = Vector();
	customV.dir_x = 90;
	customV.dir_y = 90;

	std::cout << wyliczCosinus(top, customV);


	/*
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();

	ALLEGRO_DISPLAY* disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_create_builtin_font();


	al_register_event_source(event_queue, al_get_keyboard_event_source());


	int pos_x = DISP_WIDTH / 2;
	int pos_y = DISP_HEIGHT / 2;	



	bool running = true;

	// Main loop
	while (running) {
		ALLEGRO_EVENT ev;
		//std::cout << "ddd";
		//al_wait_for_event(event_queue, &ev);

		


		al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(0,0,255));

		al_flip_display();

		al_clear_to_color(al_map_rgb(0, 0, 0));

		_sleep(40);

	}
	al_destroy_display(disp);

	*/
}
