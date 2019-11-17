#pragma once
#include "Enemigo.h"
class Gamma : public Enemigo{
public:
	Gamma(int px, int py);
	~Gamma();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover();
	void Animar(BufferedGraphics^ buffer, Bitmap^ bmp);
	Rectangle getgamma();
	void setvisible(bool v);
	bool getvisible();

};

Gamma::Gamma(int px, int py)
{
	x = px;
	y = py;
	dx = 10;
	dy = 10;
	indicex = 0;
	indicey = 0;
	ancho = 40;
	alto = 40;
	visible = true;
}

Gamma::~Gamma()
{
}

void Gamma::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 1.2, alto * 1.2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
	Mover();
}

void Gamma::Mover() {
	if (x + dx < 0 || x + dx + ancho >= 1079) {
		dx *= -1;
	}
	if (y + dy < 370 || y + dy + alto >= 550) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Gamma::Animar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	if (indicex < 2)
		indicex++;
	else
		indicex = 0;
	Dibujar(buffer, bmp);
}

Rectangle Gamma::getgamma() { return Rectangle(x, y, ancho * 1.2, alto * 1.2); }

void Gamma::setvisible(bool v) { visible = v; }

bool Gamma::getvisible() { return visible; }
