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
double losujKierunek();
int losujPozycjeKola();
double wyliczCosinus();
double przeliczCosNaKat();
Vector randVector();
// </deklaracje funkcji> 

