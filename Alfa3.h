#pragma once
#include "Enemigo.h"

class Alfa3 : public Enemigo
{
public:
	Alfa3(int px, int py);
	~Alfa3();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, Bitmap^ der);
	void Mover(BufferedGraphics^ buffer, Bitmap^ izq, Bitmap^ der);
	Rectangle getalfa3();
	void setvisible(bool v);
	bool getvisible();
};

Alfa3::Alfa3(int px, int py)
{
	x = px;
	y = py;
	dx = -10;
	dy = 0;
	indicex = 0;
	indicey = 0;
	ancho = 38;
	alto = 32;
	visible = true;
}

Alfa3::~Alfa3()
{
}

void Alfa3::Dibujar(BufferedGraphics^ buffer, Bitmap^ izq, Bitmap^ der) {
	izq->MakeTransparent(izq->GetPixel(0, 0));
	der->MakeTransparent(der->GetPixel(0, 0));
	if (dx < 0) {
		Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);
		buffer->Graphics->DrawImage(izq, aumento, porcion, GraphicsUnit::Pixel);
	}

	if (x + dx < 0 || x + dx + ancho >= 1079) {
		dx *= -1;
	}

	if (dx > 0) {
		Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);
		buffer->Graphics->DrawImage(der, aumento, porcion, GraphicsUnit::Pixel);
	}

	x += dx;

}

void Alfa3::Mover(BufferedGraphics^ buffer, Bitmap^ izq, Bitmap^ der) {
	if (dx < 0) {
		if (indicex < 2)
			indicex++;
		else
			indicex = 0;
	}
	if (dx > 0) {
		indicex == 2;
		if (indicex <= 2 && indicex > 0)
			indicex--;
		else
			indicex = 2;
	}
	Dibujar(buffer, izq, der);
}

Rectangle Alfa3::getalfa3() { return Rectangle(x, y, ancho * 2.5, alto * 2.5); }

void Alfa3::setvisible(bool v) { visible = v; }

bool Alfa3::getvisible() { return visible; }