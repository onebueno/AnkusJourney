#pragma once
#include "Heroe.h"
#include "Bala.h"
#include "Alfa.h"
#include <vector>

using namespace System::Drawing;
using namespace std;

class CControladora {
private:
	vector<Bala*>arr_balas;
	vector<Alfa*>arr_alfa;
	int num_a;
public:
	CControladora() {
		num_a = 7 + rand() % 3;
	}
	~CControladora() {}

	void agregarbala(Heroe* heroe) {
		Bala* aux = new Bala(heroe->getx() + 90, heroe->gety() + 30);
		arr_balas.push_back(aux);
	}

	void movertodo(BufferedGraphics^ buffer, Bitmap^ bmp, Bitmap^ izq, Bitmap^ der) {
		for (int i = 0; i < arr_balas.size(); i++)
			arr_balas.at(i)->Mover(buffer, bmp);
		for (int j = 0; j < arr_alfa.size(); j++)
			arr_alfa.at(j)->Mover(buffer, izq, der);
	}

	void agregaralfa() {
		for (int i = 0; i < num_a; i++) {
			Alfa* aux = new Alfa(300 + rand() % 600, 390 + rand() % 40);
			arr_alfa.push_back(aux);
		}
	}

	void colision(Graphics^ g) {
		for (int i = 0; i < arr_balas.size(); i++) {
			for (int j = 0; j < arr_alfa.size(); j++) {
				if (arr_balas.at(i)->getBala().IntersectsWith(arr_alfa.at(j)->getalfa())) {
					arr_balas.at(i)->setvisible(false);
					arr_alfa.at(j)->setvisible(false);
				}
			}
		}

		for (int i = 0; i < arr_balas.size(); i++) {
			if (arr_balas.at(i)->getX() <= 0 || arr_balas.at(i)->getX() >= g->VisibleClipBounds.Width ||
				arr_balas.at(i)->gety() <= 0 || arr_balas.at(i)->gety() >= g->VisibleClipBounds.Height)
			{
				arr_balas.at(i)->setvisible(false);
			}
		}

		for (int i = 0; i < arr_balas.size(); i++)
		{
			if (!arr_balas.at(i)->getvisible())
			{
				arr_balas.erase(arr_balas.begin() + i);
			}
		}

		for (int i = 0; i < arr_alfa.size(); i++)
		{
			if (!arr_alfa.at(i)->getvisible())
			{
				arr_alfa.erase(arr_alfa.begin() + i);
			}
		}

	}

};
