#pragma once

using namespace System::Drawing;
using namespace std;

class Enemigo {
protected:
	int x, y;
	double alto, ancho;
	int dx, dy;
	int indicex, indicey;
	bool visible;
public:
	Enemigo() {}
	~Enemigo() {}
};
