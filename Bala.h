#pragma once
#include "Heroe.h"
using namespace System::Drawing;
class Bala {
private:
	int x, y;
	int dx;
	double ancho, alto;
	int indicex, indicey;
	bool visible;
public:
	Bala(int px, int py) {
		x = px;
		y = py;
		dx = 45;
		ancho = 86 / 4;
		alto = 18;
		indicex = 0;
		indicey = 0;
		visible = true;
	}
	~Bala() {}

	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		bmp->MakeTransparent(bmp->GetPixel(0, 0));
		Rectangle porcion = Rectangle(ancho*indicex, indicey*alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2);
		buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
		x += dx;
	}

	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (indicex < 3)
			indicex++;
		else
			indicex = 0;
		Dibujar(buffer, bmp);
	}

	Rectangle getBala() {
		return Rectangle(x, y, ancho, alto);
	}

	void setvisible(bool v) { visible = v; }

	bool getvisible() { return visible; }

	int getX() { return x; }
	int gety() { return y; }
};
