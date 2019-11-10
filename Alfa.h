#pragma once
#include "Enemigo.h"

class Alfa: public Enemigo
{
public:
	Alfa(int px,int py);
	~Alfa();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover(BufferedGraphics^ buffer, Bitmap^ izq);
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
	ancho = 349/16;
	alto = 18;
	visible = true;
}

Alfa::~Alfa()
{
}

void Alfa::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	Rectangle porcion = Rectangle(ancho*indicex, indicey*alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho*2.5, alto*2.5);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
	x += dx;
}

void Alfa::Mover(BufferedGraphics^ buffer, Bitmap^ izq) {
	if (indicex >= 0 && indicex < 8)
		indicex++;
	else
		indicex = 0;
	Dibujar(buffer, izq);
}

Rectangle Alfa::getalfa(){ return Rectangle(x, y, ancho*2.5, alto*2.5); }

void Alfa::setvisible(bool v) { visible = v; }

bool Alfa::getvisible() { return visible; }
