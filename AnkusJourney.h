#pragma once
#include "Heroe.h"
#include "Alfa.h"

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
		Alfa* objAlfa;
		Bitmap^ bmpparado;
		Bitmap^ bmpderecha;
		Bitmap^ bmpizquierda;
		Bitmap^ bmpparadoizq;
		Bitmap^ corrupcion;
		Bitmap^ contaminacion;
		Bitmap^ criminal;
		Bitmap^ criminal2;
		Bitmap^ trashcan;
		Bitmap^ ataque;
		Graphics ^g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		int nivel;
	public:
		AnkusJourney(void)
		{
			//TODO: agregar código de constructor aquí
			InitializeComponent();
			objheroe = new Heroe(50, 400);
			objAlfa = new Alfa(800, 500);
			bmpparado = gcnew Bitmap("parado.png");
			bmpderecha = gcnew Bitmap("movederecha.png");
			bmpizquierda = gcnew Bitmap("moveizquierda.png");
			bmpparadoizq = gcnew Bitmap("paradoizquierda.png");
			corrupcion = gcnew Bitmap("corrupted.jpg");
			contaminacion = gcnew Bitmap("pollution.png");
			criminal = gcnew Bitmap("criminal.png");
			criminal2 = gcnew Bitmap("criminal2.png");
			trashcan = gcnew Bitmap("trashcanleft.png");
			ataque = gcnew Bitmap("atacar.png");
			//g = this->CreateGraphics();
			//espacio = BufferedGraphicsManager::Current;
			//buffer = espacio->Allocate(g, this->ClientRectangle);
			nivel = 1;
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
	private: System::Windows::Forms::Timer^  timer1;

	private: System::ComponentModel::IContainer^  components;

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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &AnkusJourney::timer1_Tick);
			// 
			// AnkusJourney
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1079, 551);
			this->Name = L"AnkusJourney";
			this->Text = L"AnkusJourney";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AnkusJourney::presionartecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &AnkusJourney::soltartecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		//Graphics ^
		g = this->CreateGraphics();
		//BufferedGraphicsContext^ 
		espacio = BufferedGraphicsManager::Current;
		//BufferedGraphics^ 
		buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		if (nivel == 1) {
			buffer->Graphics->DrawImage(contaminacion, 0, -50, contaminacion->Width*1.55, contaminacion->Height*1.3);
			objAlfa->Mover(buffer, trashcan);
		}
		if (nivel == 2) {
			buffer->Graphics->DrawImage(criminal, -45, -85, criminal->Width, criminal->Height);
		}
		if (nivel == 3) {
			buffer->Graphics->DrawImage(corrupcion, 0, 0, corrupcion->Width*0.60, corrupcion->Height*0.50);
		}
		objheroe->mover(buffer, bmpizquierda, bmpderecha, bmpparado, bmpparadoizq, ataque, g);
		buffer->Render(g);

		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void soltartecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::P)
		{
			objheroe->direccion = Direcciones::Ataque;
		}
		objheroe->direccion = Direcciones::Ninguna;
	}
	private: System::Void presionartecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::A:
			objheroe->direccion = Direcciones::Izquierda;
			break;
		case Keys::D:
			objheroe->direccion = Direcciones::Derecha;
			break;
		case Keys::P:
			objheroe->direccion = Direcciones::Ataque;

		}
	}
	};
}

