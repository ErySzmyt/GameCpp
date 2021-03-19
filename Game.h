
#pragma once
#include<allegro5/allegro.h>
// <structy>
struct Vector {
	double dir_x;
	double dir_y;

public: 
	void multiply(float mult);
};

struct Circle
{
	Vector vector;

	int pos_x;
	int pos_y;

	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

	void setRandomColor();

};

// <deklaracej stalych>
const float DISP_WIDTH = 600;
const float DISP_HEIGHT = 600;
// </deklaracej stalych>

// <deklaracje funkcji> 
Circle generateCircle();
double randDouble(const int min, const int max);
int losujPozycjeKola();
Vector randVector();
// </deklaracje funkcji>

int cl_hits = 0;
int cl_misses = 0;


