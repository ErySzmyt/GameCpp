#include<allegro5/allegro.h>													
#include<allegro5/allegro_font.h>	
#include <allegro5/allegro_primitives.h>
#include<cstdio>
#include<iostream>

const float DISP_WIDTH = 600;
const float DISP_HEIGHT = 600;

double losujKierunek();
int losujPozycjeKola();

struct Circle
{
	Vector vector;

	int pos_x;
	int pos_y;
};



	void inwersja(int *tablica)
	{ 
		tablica = new int[] { 4, 2, 7, 3, 9, 1, 8, 5 };
		int i = 0;

		int dlugosc = sizeof(tablica) / sizeof(int);

		int j = dlugosc - 1;
		int pomoc;

		while (i < j) 
		{
			pomoc = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = pomoc;
			i++;
			j--;
		}
	}

	
		
	


struct Vector {
	double dir_x;
	double dir_y;
};

Vector randVector() {
	Vector temp = Vector();

}

bool detectColision(int x1, int y1, int x2, int y2) {
	if (x1 < 0 || x2 > DISP_WIDTH)
		return true;
	if (y1 < 0 || y2 > DISP_HEIGHT)
		return true;

	return false;
}

double losujKierunek() {
	// funkcja losuje  wartosci kierunku double 0-360
	const int min = 0;
	const int max = 360;
	double los = (double)rand() / RAND_MAX;
	return min + los * (max - min);
}

int losujPozycjeKola() {
	// losuje pozycje kola wartosc pozycji int z przedzialu 1-599
	const int min = 1;
	const int max = 599;
	int wynik;
	return wynik = (rand() % max) + min;
}
void main(void) {
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();

	ALLEGRO_DISPLAY* disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_create_builtin_font();


	al_register_event_source(event_queue, al_get_keyboard_event_source());


	int pos_x = DISP_WIDTH / 2;
	int pos_y = DISP_HEIGHT / 2;



	Vector direction = Vector();

	



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
}
