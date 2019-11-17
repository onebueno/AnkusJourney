#pragma once
#include "Enemigo.h"
class Beta3 : public Enemigo {
public:
	Beta3(int px, int py);
	~Beta3();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp);
	Rectangle getbeta3();
	void setvisible(bool v);
	bool getvisible();

};

Beta3::Beta3(int px, int py)
{
	x = px;
	y = py;
	dx = 10;
	dy = 10;
	indicex = 0;
	indicey = 0;
	ancho = 33;
	alto = 44;
	visible = true;
}

Beta3::~Beta3()
{
}

void Beta3::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);

	if (y + dy < 370 || y + dy + alto >= 550) {
		dy *= -1;
	}
	y += dy;

}

void Beta3::Mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
	if (indicex < 11)
		indicex++;
	else
		indicex = 0;
	Dibujar(buffer, bmp);
}

Rectangle Beta3::getbeta3() { return Rectangle(x, y, ancho * 2, alto * 2); }

void Beta3::setvisible(bool v) { visible = v; }

bool Beta3::getvisible() { return visible; }
