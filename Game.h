#pragma once
// <structy>
struct Vector {
	double dir_x;
	double dir_y;
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
bool checkClickAndPos();
Vector randVector();
// </deklaracje funkcji> 

