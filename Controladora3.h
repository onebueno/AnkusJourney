#pragma once
#include "Heroe.h"
#include "Bala.h"
#include "Beta3.h"
#include "Gamma3.h"
#include "Alfa3.h"
#include <vector>

using namespace System::Drawing;
using namespace std;

class CControladora3 {
private:
	vector<Bala*>arr_balas;

	vector<Beta3*>arr_beta;
	vector<Gamma3*>arr_gamma;
	vector<Alfa3*>arr_alfa;
	Heroe* obj;
	int num_a;
	int num_b;
	int num_g;
public:
	CControladora3() {
		num_a = 3 + rand() % 7;
		num_b = 3 + rand() % 7;
		num_g = 4 + rand() % 6;
	}
	~CControladora3() {}

	void agregarbala(Heroe* heroe) {
		Bala* aux = new Bala(heroe->getx() + 90, heroe->gety() + 30);
		arr_balas.push_back(aux);
	}

	void movertodo(BufferedGraphics^ buffer, Bitmap^ bmp, Bitmap^ izq, Bitmap^ der,
		Bitmap^ dinero, Bitmap^ ojo) {
		for (int i = 0; i < arr_balas.size(); i++)
			arr_balas.at(i)->Mover(buffer, bmp);
		for (int j = 0; j < arr_alfa.size(); j++)
			arr_alfa.at(j)->Mover(buffer, izq, der);
		for (int k = 0; k < arr_beta.size(); k++)
			arr_beta.at(k)->Mover(buffer, dinero);
		for (int m = 0; m < arr_gamma.size(); m++)
			arr_gamma.at(m)->Mover(buffer, ojo);
	}

	void agregarenemigo() {
		for (int i = 0; i < num_a; i++) {
			Alfa3* aux = new Alfa3(100 + rand() % 800, 400 + rand() % 30);
			arr_alfa.push_back(aux);
		}

		for (int j = 0; j < num_b; j++) {
			Beta3* aux = new Beta3(100 + rand() % 800, 410 + rand() % 50);
			arr_beta.push_back(aux);
		}

		for (int k = 0; k < num_b; k++) {
			Gamma3* aux = new Gamma3(rand() % 600, 410 + rand() % 50);
			arr_gamma.push_back(aux);
		}
	}

	int GetAlfasize() {
		return arr_alfa.size();
	}

	int GetBetasize() {
		return arr_beta.size();
	}

	int GetGammasize() {
		return arr_gamma.size();
	}

	void colision(Graphics^ g) {
		for (int i = 0; i < arr_balas.size(); i++) {
			for (int j = 0; j < arr_alfa.size(); j++) {
				if (arr_balas.at(i)->getBala().IntersectsWith(arr_alfa.at(j)->getalfa3())) {
					arr_balas.at(i)->setvisible(false);
					arr_alfa.at(j)->setvisible(false);
				}
			}
		}

		for (int i = 0; i < arr_balas.size(); i++) {
			for (int j = 0; j < arr_beta.size(); j++) {
				if (arr_balas.at(i)->getBala().IntersectsWith(arr_beta.at(j)->getbeta3())) {
					arr_balas.at(i)->setvisible(false);
					arr_beta.at(j)->setvisible(false);
				}
			}
		}

		for (int i = 0; i < arr_balas.size(); i++) {
			for (int j = 0; j < arr_gamma.size(); j++) {
				if (arr_balas.at(i)->getBala().IntersectsWith(arr_gamma.at(j)->getgamma3())) {
					arr_balas.at(i)->setvisible(false);
					arr_gamma.at(j)->setvisible(false);
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

		for (int i = 0; i < arr_beta.size(); i++)
		{
			if (!arr_beta.at(i)->getvisible())
			{
				arr_beta.erase(arr_beta.begin() + i);
			}
		}

		for (int i = 0; i < arr_gamma.size(); i++)
		{
			if (!arr_gamma.at(i)->getvisible())
			{
				arr_gamma.erase(arr_gamma.begin() + i);
			}
		}

	}

};
