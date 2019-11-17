#pragma once
#include "Enemigo.h"
class Gamma2 : public Enemigo {
public:
	Gamma2(int px, int py);
	~Gamma2();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover();
	void Animar(BufferedGraphics^ buffer, Bitmap^ bmp);
	Rectangle getgamma2();
	void setvisible(bool v);
	bool getvisible();

};

Gamma2::Gamma2(int px, int py)
{
	x = px;
	y = py;
	dx = 10;
	dy = 10;
	indicex = 0;
	indicey = 0;
	ancho = 72;
	alto = 65;
	visible = true;
}

Gamma2::~Gamma2()
{
}

void Gamma2::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	bmp->MakeTransparent(bmp->GetPixel(0, 0));
	Rectangle porcion = Rectangle(ancho * indicex, indicey * alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 0.7, alto * 0.7);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
	Mover();
}

void Gamma2::Mover() {
	if (x + dx < 0 || x + dx + ancho >= 1079) {
		dx *= -1;
	}
	if (y + dy < 370 || y + dy + alto >= 550) {
		dy *= -1;
	}
	x += dx;
	y += dy;

}

void Gamma2::Animar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	if (indicex >= 0 && indicex < 2)
		indicex++;
	if (indicex == 2) {
		while (indicex != 0)
			indicex--;
	}
	Dibujar(buffer, bmp);
}

Rectangle Gamma2::getgamma2() { return Rectangle(x, y, ancho * 0.7, alto * 0.7); }

void Gamma2::setvisible(bool v) { visible = v; }

bool Gamma2::getvisible() { return visible; }
