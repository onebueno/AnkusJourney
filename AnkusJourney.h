#pragma once
#include "Heroe.h"

//por si acaso le cambie el nombre al proyecto a AJ,por eso el namespace se llama así
namespace AJ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AnkusJourney
	/// </summary>
	public ref class AnkusJourney : public System::Windows::Forms::Form
	{
	private:
		Heroe* objheroe = new Heroe(50,400);
		Bitmap^ bmpparado = gcnew Bitmap("parado.png");
		Bitmap^ bmpderecha = gcnew Bitmap("movederecha.png");
		Bitmap^ bmpizquierda = gcnew Bitmap("moveizquierda.png");
		Bitmap^ bmpparadoizq = gcnew Bitmap("paradoizquierda.png");
		Bitmap^ corrupcion = gcnew Bitmap("corrupted.jpg");
		Bitmap^ contaminacion = gcnew Bitmap("pollution.png");
	public:
		AnkusJourney(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
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
	protected:
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
			this->ClientSize = System::Drawing::Size(1081, 554);
			this->Name = L"AnkusJourney";
			this->Text = L"AnkusJourney";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AnkusJourney::presionartecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &AnkusJourney::soltartecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawImage(contaminacion, 0, -50, contaminacion->Width*1.55, contaminacion->Height*1.3);

		objheroe->mover(buffer, bmpizquierda, bmpderecha, bmpparado, bmpparadoizq);
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void soltartecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		objheroe->direccion = Direcciones::Ninguna;
	}
	private: System::Void presionartecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::Left:
			objheroe->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			objheroe->direccion = Direcciones::Derecha;
			break;

		}
	}
	};
}

