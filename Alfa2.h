#pragma once
#include "Enemigo.h"

class Alfa2 {
private:
	int x;
	int y;
	int dx;
	int dy;
	int indicex;
	int indicey;
	int ancho;
	int alto;
	bool visible;
public:
	Alfa2(int px, int py);
	~Alfa2();
	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmpizq, Bitmap^ bmpder);
	void mover(BufferedGraphics^ buffer, Bitmap^ bpmizq, Bitmap^ bmpder);
	Rectangle getAlfa2();
	void setvisible(bool v);
	bool getvisible();
};

Alfa2::Alfa2(int px, int py) {
	x = px;
	y = py;
	dx = -10;
	dy = 0;
	indicex = 0;
	indicey = 0;
	ancho = 70;
	alto = 30;
	visible = true;
}

Alfa2::~Alfa2() {}

void Alfa2::dibujar(BufferedGraphics^ buffer, Bitmap^ bmpizq, Bitmap^ bmpder) {
	bmpizq->MakeTransparent(bmpizq->GetPixel(0,0));
	bmpder->MakeTransparent(bmpder->GetPixel(0, 0));

	if (dx < 0) {
		Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2);
		buffer->Graphics->DrawImage(bmpizq, aumento, porcion, GraphicsUnit::Pixel);
	}


	if (x + dx < 0 || x + dx + ancho >= 1079) {
		dx *= -1;
	}



	if (dx > 0) {
		Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2);
		buffer->Graphics->DrawImage(bmpder, aumento, porcion, GraphicsUnit::Pixel);
	}

	x += dx;
}

void Alfa2::mover(BufferedGraphics^ buffer, Bitmap^ bmpizq, Bitmap^ bmpder) {
	indicex++;

	if (indicex < 3)
		indicex = 0;
	

	dibujar(buffer, bmpizq, bmpder);
}

Rectangle Alfa2::getAlfa2() { return Rectangle(x, y, ancho * 2, alto * 2); }

void Alfa2::setvisible(bool v) { visible = v; }

bool Alfa2::getvisible() { return visible; }
