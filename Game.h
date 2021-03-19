#pragma once
// <structy>
struct Vector {
	double dir_x;
	double dir_y;

public: 
	void multiply(float mult) {
		this->dir_x *= mult;
		this->dir_y *= mult;
	}
};

struct Circle
{
	Vector vector;

	int pos_x;
	int pos_y;
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


