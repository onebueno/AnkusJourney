#pragma once
#include "Enemigo.h"
class Beta2 : public Enemigo {
public:
	Beta2(int px, int py);
	~Beta2();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp);
	Rectangle getbeta2();
	void setvisible(bool v);
	bool getvisible();

};

Beta2::Beta2(int px, int py)
{
	x = px;
	y = py;
	dx = 10;
	dy = 10;
	indicex = 0;
	indicey = 0;
	ancho = 23;
	alto = 26;
	visible = true;
}

Beta2::~Beta2()
{
}

void Beta2::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);

	if (y + dy < 370 || y + dy + alto >= 550) {
		dy *= -1;
	}
	y += dy;

}

void Beta2::Mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
	if (indicex < 4)
		indicex++;
	else
		indicex = 0;
	Dibujar(buffer, bmp);
}

Rectangle Beta2::getbeta2() { return Rectangle(x, y, ancho * 2, alto * 2); }

void Beta2::setvisible(bool v) { visible = v; }

bool Beta2::getvisible() { return visible; }
