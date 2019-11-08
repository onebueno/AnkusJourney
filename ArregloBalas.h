#pragma once
#include "Heroe.h"
#include "Bala.h"	
#include <vector>

using namespace System::Drawing;
using namespace std;

class ArregloBalas {
private:
	vector<Bala*>arr_balas;
public:
	ArregloBalas() {}
	~ArregloBalas() {}

	void agregarbala(Heroe * heroe) {
		Bala *aux = new Bala(heroe->getx()+90, heroe->gety()+30);
		arr_balas.push_back(aux);
	}

	void moverbalas(BufferedGraphics^ buffer,Bitmap ^bmp ,Heroe * heroe) {
		for (int i = 0; i < arr_balas.size(); i++)
			arr_balas.at(i)->Mover(buffer, bmp,heroe);
	}
};
