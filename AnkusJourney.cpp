#include "AnkusJourney.h"

using namespace System;
using namespace Windows::Forms;

void main(array <String^>^ arg) {
	Application::EnableVisualStyles();
	Application::Run(gcnew AnkusJourney::AnkusJourney);
}

