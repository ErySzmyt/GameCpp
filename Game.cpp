#include<allegro5/allegro.h>													
#include<allegro5/allegro_font.h>	
#include <allegro5/allegro_primitives.h>
#include <Windows.h>
#include <iostream>
#include <cstdlib>

#include <chrono>
#include <thread>

#include<math.h>
#include "Game.h";


bool detectCollisionVertically(int x1, int y1, int x2, int y2)
{
	if (y1 < 0 || y2 > DISP_HEIGHT)
		return true;
	return false;
}

bool detectCollisionHorisontally(int x1, int y1, int x2, int y2)
{
	if (x1 < 0 || x2 > DISP_WIDTH)
		return true;
	return false;
}

double randDouble(const int min, const int max)
{
	// funkcja losuje  wartosci
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

void reverseDirX(Vector& v1) {
	v1.dir_x = -(v1.dir_x + randDouble(0, 2));
}

void reverseDirY(Vector& v1) {
	v1.dir_y = -(v1.dir_y + randDouble(0, 2));
}

Circle generateCircle() { 
	Circle circle = Circle();
	circle.pos_x = losujPozycjeKola();
	circle.pos_y = losujPozycjeKola();
	circle.vector = randVector();

	return circle;
}

Vector randVector() {
	Vector temp = Vector();
	temp.dir_x = 20;
	temp.dir_y = 20;

	return temp;
}

void drawCircle(Circle circle) {
	//al_draw_filled_rectangle(circle.pos_x, circle.pos_y, circle.pos_x + 30, circle.pos_y + 30, al_map_rgb(0, 0, 255));
	al_draw_filled_circle(circle.pos_x + 15, circle.pos_y + 15, 15, al_map_rgb(0, 0, 255));
}

// </funkcje>
int main() {
	/* initialize random seed: */
	srand(time(NULL));

	al_init();
	al_init_primitives_addon();
	al_install_keyboard();

	ALLEGRO_DISPLAY* disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_create_builtin_font();


	al_register_event_source(event_queue, al_get_keyboard_event_source());


	bool running = true;

	Circle circle = generateCircle();

	// Main loop
	while (running) {
		//ALLEGRO_EVENT ev;
		//std::cout << "ddd";
		//al_wait_for_event(event_queue, &ev);

		circle.pos_x += circle.vector.dir_x;
		circle.pos_y += circle.vector.dir_y;

		if (detectCollisionVertically(circle.pos_x-15, circle.pos_y - 15, circle.pos_x + 30, circle.pos_y + 30)) {
			reverseDirY(circle.vector);
		}


		if (detectCollisionHorisontally(circle.pos_x - 15, circle.pos_y - 15, circle.pos_x + 30, circle.pos_y + 30)) {
			reverseDirX(circle.vector);
		}
		


		//drawCircle(circle);
		drawCircle(circle);

		al_flip_display();

		al_clear_to_color(al_map_rgb(0, 0, 0));

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

	}
	al_destroy_display(disp);

	
}
