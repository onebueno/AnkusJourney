#pragma once
using namespace System::Drawing;

enum Direcciones {Ninguna, Izquierda, Derecha,Ataque};

class Heroe {
private:
	int x;
	int y;
	int dx;
	int dy;
	double ancho;
	int alto;
	int indicex;
	int indicey;
	Direcciones ultimatecla;
	bool flag;
public:
	Heroe();
	~Heroe();
	Heroe(int x, int y);
	void imprimir(BufferedGraphics^buffer, Bitmap^bmp);
	void mover(BufferedGraphics^buffer, Bitmap^ bmpizquierda, Bitmap^ bmpderecha, Bitmap^ bmpparado, Bitmap^ bmpparadoizq,Bitmap^ ataque, Graphics^ g);
	void parado(BufferedGraphics^ buffer, Bitmap^ bmp);
	int getx();
	int gety();
	Rectangle GetHeroe();
	Direcciones direccion;
};

Heroe::Heroe() {}

Heroe::~Heroe() {}

Heroe::Heroe(int x, int y) {
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	ultimatecla = Direcciones::Derecha;
	direccion = Direcciones::Ninguna;
	ancho = 50;
	alto = 75;
	indicex = 0;
	indicey = 0;
	flag = false;
}

int Heroe::getx() {
	return x;
}

int Heroe::gety() {
	return y;
}

void Heroe::imprimir(BufferedGraphics^ buffer, Bitmap^ bmp) {
	Rectangle porcion = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 2, alto * 2 );
	buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
}

void Heroe::mover(BufferedGraphics^ buffer, Bitmap^ bmpizquierda, Bitmap^ bmpderecha, Bitmap^ bmpparado, Bitmap^ bmpparadoizq,Bitmap^ ataque,Graphics^g) {
	ancho = 79;
	ataque->MakeTransparent(ataque->GetPixel(0, 0));
	switch (direccion) {
	case Direcciones::Derecha:

		imprimir(buffer, bmpderecha);
		indicex++;

		if (indicex > 5)
			indicex = 0;
		if (x + ancho * 2 < g->VisibleClipBounds.Width) {
			dx = 50;
			dy = 0;
			x += dx;
		}
		ultimatecla = Derecha;
		break;

	case Direcciones::Izquierda:

		imprimir(buffer, bmpizquierda);
		indicex++;

		if (indicex > 5)
			indicex = 0;
		if (x > 0)
		{
			dx = -50;
			dy = 0;
			x += dx;
		}
		ultimatecla = Izquierda;
		break;

	case Direcciones::Ninguna:
		dx = 0;
		dy = 0;
		switch (ultimatecla) {
			case Direcciones::Derecha:
				parado(buffer, bmpparado);
				break;
			case Direcciones::Izquierda:
				parado(buffer, bmpparadoizq);
				break;
			}
		break;
		
	case Direcciones::Ataque:
		//indicex = 3;
		ancho = 90;
		dx = 0;
		dy = 0;
		imprimir(buffer, ataque);
		indicex++;
		if (indicex > 4)
			indicex = 0;

	}
}

void Heroe::parado(BufferedGraphics ^ buffer, Bitmap ^ bmp) {
	ancho = 50;
	indicex++;
	if (indicex > 4)
		indicex = 0;
	imprimir(buffer, bmp);
}

Rectangle Heroe::GetHeroe() {
	return Rectangle(x, y, ancho * 2, alto * 2);
}
