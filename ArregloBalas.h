#pragma once
#include "Heroe.h"
#include "Bala.h"	
#include <vector>

using namespace std;

class ArregloBalas {
private:
	vector<Bala*>arr_balas;
public:
	ArregloBalas() {}
	~ArregloBalas() {}

	void agregarbala(Heroe * heroe) {
		Bala *aux = new Bala(heroe->getx(), heroe->gety());
		arr_balas.push_back(aux);
	}

	void moverbalas(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int i = 0; i < arr_balas.size(); i++)
			arr_balas.at(i)->Mover(buffer, bmp);
	}
};
