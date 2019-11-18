#pragma once
#include "Enemigo.h"
class Gamma3 : public Enemigo {
public:
	Gamma3(int px, int py);
	~Gamma3();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover();
	void Animar(BufferedGraphics^ buffer, Bitmap^ bmp);
	Rectangle getgamma3();
	void setvisible(bool v);
	bool getvisible();
};

Gamma3::Gamma3(int px, int py)
{
	x = px;
	y = py;
	dx = 10;
	dy = 10;
	indicex = 0;
	indicey = 0;
	ancho = 50;
	alto = 39;
	visible = true;
}

Gamma3::~Gamma3()
{
}

void Gamma3::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);

	Mover();
}

void Gamma3::Mover() {
	if (x + dx < 0 || x + dx + ancho >= 1079) {
		dx *= -1;
	}
	if (y + dy < 370 || y + dy + alto >= 550) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Gamma3::Animar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	if (indicex >= 0 && indicex < 2)
		indicex++;
	if (indicex == 2) {
		while (indicex != 0)
			indicex--;
	}
	Dibujar(buffer, bmp);
}

Rectangle Gamma3::getgamma3() { return Rectangle(x, y, ancho * 2, alto * 2); }

void Gamma3::setvisible(bool v) { visible = v; }

bool Gamma3::getvisible() { return visible; }
