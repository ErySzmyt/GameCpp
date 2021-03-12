#include<allegro5/allegro.h>													
#include<allegro5/allegro_font.h>	
#include <allegro5/allegro_primitives.h>
#include<cstdio>
#include<iostream>

const float DISP_WIDTH = 600;
const float DISP_HEIGHT = 600;


struct Circle
{
	Vector vector;

};

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
