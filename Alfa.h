#pragma once
#include "Enemigo.h"

class Alfa : public Enemigo
{
public:
	Alfa(int px, int py);
	~Alfa();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, Bitmap^ der);
	void Mover(BufferedGraphics^ buffer, Bitmap^ izq, Bitmap^ der);
	Rectangle getalfa();
	void setvisible(bool v);
	bool getvisible();
};

Alfa::Alfa(int px, int py)
{
	x = px;
	y = py;
	dx = -10;
	dy = 0;
	indicex = 0;
	indicey = 0;
	ancho = 349 / 16;
	alto = 18;
	visible = true;
}

Alfa::~Alfa()
{
}

void Alfa::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, Bitmap^ der) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	der->MakeTransparent(der->GetPixel(0, 0));
	if (dx < 0) {
		ancho = 349 / 16;
		Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);
		buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
	}

	if (x + dx < 0 || x + dx + ancho >= 1079) {
		dx *= -1;
	}

	if (dx > 0) {
		ancho = 22;
		Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);
		buffer->Graphics->DrawImage(der, aumento, porcion, GraphicsUnit::Pixel);
	}

	x += dx;

}

void Alfa::Mover(BufferedGraphics^ buffer, Bitmap^ izq, Bitmap^ der) {
	if (dx < 0) {
		if (indicex >= 0 && indicex < 8)
			indicex++;
		else
			indicex = 0;
	}
	if (dx > 0) {
		indicex == 15;
		if (indicex <= 15 && indicex > 6)
			indicex--;
		else
			indicex = 15;
	}
	Dibujar(buffer, izq, der);
}

Rectangle Alfa::getalfa() { return Rectangle(x, y, ancho * 2.5, alto * 2.5); }

void Alfa::setvisible(bool v) { visible = v; }

bool Alfa::getvisible() { return visible; }
