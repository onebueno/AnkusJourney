#pragma once
#include "Heroe.h"
#include "Fondo.h"
#include "Controladora.h"
#include "Controladora2.h"
#include "Controladora3.h"
#include <ctime>

namespace AJ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de AnkusJourney
	/// </summary>
	public ref class AnkusJourney : public System::Windows::Forms::Form
	{
	private:
		Heroe* objheroe;
		fondo* tren;
		Bitmap^ bmpcoin;
		Bitmap^ bmpcoinder;
		Bitmap^ bmpparado;
		Bitmap^ bmpderecha;
		Bitmap^ bmpizquierda;
		Bitmap^ bmpparadoizq;
		Bitmap^ corrupcion;
		Bitmap^ contaminacion;
		Bitmap^ trashcan;
		Bitmap^ ataque;
		Bitmap^ train;
		Bitmap^ hacha;
		Bitmap^ suelo;
		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		CControladora* arreglo;
		Bitmap^ der;
		Bitmap^ humo;
		Bitmap^ reciclaje;
		Bitmap^ fuego;
		Bitmap^ dinero;
		Bitmap^ ojo;
		CControladora2* arreglo2;
		CControladora3* arreglo3;
		Bitmap^ ladronizq;
		Bitmap^ ladronder;
		Bitmap^ pandillero;
		Bitmap^ terrorista;
		Bitmap^ bala;
		Bitmap^ ganaste;
		//BalaEn* bullet;
		int vidas;
		int nivel;
	private: System::Windows::Forms::Label^  labelpuntos;


			 int cont;
	public:
		AnkusJourney(void)
		{
			//TODO: agregar código de constructor aquí
			InitializeComponent();

			objheroe = new Heroe(50, 420);
			tren = new fondo(0, 0);
			bmpparado = gcnew Bitmap("parado.png");
			bmpderecha = gcnew Bitmap("movederecha.png");
			bmpizquierda = gcnew Bitmap("moveizquierda.png");
			bmpparadoizq = gcnew Bitmap("paradoizquierda.png");
			corrupcion = gcnew Bitmap("corrupted.jpg");
			contaminacion = gcnew Bitmap("pollution.png");
			trashcan = gcnew Bitmap("trashcanleft.png");
			ataque = gcnew Bitmap("atacar.png");
			train = gcnew Bitmap("tren.png");
			arreglo = new CControladora();
			hacha = gcnew Bitmap("hacha.png");
			suelo = gcnew Bitmap("road.png");
			der = gcnew Bitmap("trashcanright.png");
			humo = gcnew Bitmap("humo.png");
			reciclaje = gcnew Bitmap("recycling.png");
			fuego = gcnew Bitmap("fuego.png");
			dinero = gcnew Bitmap("dinero.png");
			ojo = gcnew Bitmap("eye.png");
			arreglo2 = new CControladora2();
			arreglo3 = new CControladora3();
			bmpcoin = gcnew Bitmap("coin.png");
			bmpcoinder = gcnew Bitmap("coinder.png");
			ladronizq = gcnew Bitmap("ladron.png");
			ladronder = gcnew Bitmap("ladronder.png");
			pandillero = gcnew Bitmap("pandillero.png");
			terrorista = gcnew Bitmap("terrorista.png");
			bala = gcnew Bitmap("circle.jpg");
			ganaste = gcnew Bitmap("win.jpg");
			arreglo2 = new CControladora2();
			//bullet = new BalaEn(300,300);
			nivel = 1;
			arreglo->agregarenemigo();
			arreglo2->agregarenemigo();
			arreglo3->agregarenemigo();
			cont = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AnkusJourney()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelpuntos = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &AnkusJourney::timer1_Tick);
			// 
			// labelpuntos
			// 
			this->labelpuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelpuntos->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->labelpuntos->Location = System::Drawing::Point(1175, 36);
			this->labelpuntos->Name = L"labelpuntos";
			this->labelpuntos->Size = System::Drawing::Size(127, 38);
			this->labelpuntos->TabIndex = 0;
			// 
			// AnkusJourney
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1439, 678);
			this->Controls->Add(this->labelpuntos);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AnkusJourney";
			this->Text = L"AnkusJourney";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AnkusJourney::presionartecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &AnkusJourney::soltartecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		g = this->CreateGraphics();
		espacio = BufferedGraphicsManager::Current;
		buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		if (nivel == 1) {
			buffer->Graphics->DrawImage(contaminacion, 0, -50, contaminacion->Width * 1.55, contaminacion->Height * 1.3);
			buffer->Graphics->DrawImage(suelo, 0, 440, suelo->Width * 0.8, suelo->Height* 0.8);
			//arreglo->agregarbalaalfa(objheroe);
			//bullet->Dibujar(buffer, bala);
			arreglo->movertodo(buffer, hacha, trashcan, der, humo,fuego,objheroe,bala);
			
			if (cont >= 0 && cont < 100) {
				arreglo->movergamma(buffer, humo);
			}
			else
				arreglo->invisiblegamma();
			if (cont == 150)
				cont = 0;
			arreglo->colision(g,objheroe);
			int puntos  = arreglo->getpuntos();
			labelpuntos->Text = Convert::ToString(puntos);
			if (arreglo->GetAlfasize() == 0 && arreglo->GetBetasize() == 0 && arreglo->GetGammasize() == 0)
				nivel++;
		}
		if (nivel == 2) {
			buffer->Graphics->DrawImage(corrupcion, 0, 0, corrupcion->Width * 0.60, corrupcion->Height * 0.50);
			arreglo2->movertodo(buffer, hacha, bmpcoin, bmpcoinder,dinero,objheroe);
			if (cont >= 0 && cont < 100) {
				arreglo2->movergamma(buffer, ojo);
			}
			else
				arreglo2->invisiblegamma();
			if (cont == 150)
				cont = 0;
			arreglo2->colision(g);
			int puntos = arreglo2->getpuntos();
			labelpuntos->Text = Convert::ToString(puntos);
			if (arreglo2->GetBetasize() == 0 && arreglo2->GetAlfasize() == 0 && arreglo2->GetGammasize() == 0)
				nivel++;
		}
		if (nivel == 3) {
			tren->mover(buffer, train);
			arreglo3->movertodo(buffer, hacha, ladronizq, ladronder, terrorista,objheroe);
			if (cont >= 0 && cont < 100) {
				arreglo3->movergamma(buffer, pandillero);
			}
			else
				arreglo3->invisiblegamma();
			if (cont == 150)
				cont = 0;
			arreglo3->colision(g);
			if (arreglo3->GetAlfasize() == 0 && arreglo3->GetBetasize() == 0 && arreglo3->GetGammasize() == 0)
				nivel++;
		}
		if (nivel == 4)
			buffer->Graphics->DrawImage(ganaste, 0, 0, ganaste->Width *3.5, ganaste->Height*3);
		cont++;
		objheroe->mover(buffer, bmpizquierda, bmpderecha, bmpparado, bmpparadoizq, ataque, g);
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void soltartecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objheroe->direccion = Direcciones::Ninguna;
	}
	private: System::Void presionartecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::A:
			objheroe->direccion = Direcciones::Izquierda;
			break;
		case Keys::D:
			objheroe->direccion = Direcciones::Derecha;
			break;
		case Keys::P:
			objheroe->direccion = Direcciones::Ataque;
			if (nivel == 1)
				arreglo->agregarbala(objheroe);
			if (nivel == 2)
				arreglo2->agregarbala(objheroe);
			if (nivel == 3)
				arreglo3->agregarbala(objheroe);
			break;
		case Keys::W:
			objheroe->direccion = Direcciones::Subir;
			break;
		case Keys::S:
			objheroe->direccion = Direcciones::Bajar;
			break;
		}
	}
};
}
