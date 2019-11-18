#pragma once
#include "Enemigo.h"
class Beta : public Enemigo {
public:
	Beta(int px, int py);
	~Beta();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp);
	Rectangle getbeta();
	void setvisible(bool v);
	bool getvisible();

};

Beta::Beta(int px, int py)
{
	x = px;
	y = py;
	dx = 10;
	dy = 10;
	indicex = 0;
	indicey = 0;
	ancho = 139/6;
	alto = 29;
	visible = true;
}

Beta::~Beta()
{
}

void Beta::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);

	if (y + dy < 370 || y + dy + alto >= 550) {
		dy *= -1;
	}
	y += dy;

}

void Beta::Mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
	if (indicex < 5)
		indicex++;
	else
		indicex = 0;
	Dibujar(buffer, bmp);
}

Rectangle Beta::getbeta() { return Rectangle(x, y, ancho * 2, alto * 2); }

void Beta::setvisible(bool v) { visible = v; }

bool Beta::getvisible() { return visible; }