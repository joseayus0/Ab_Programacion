#include <iostream>
//#include <string>
//#include "windows.h"

class Persona {
public:
	//Constructor
	Persona(std::string n, int e) : nombre(n), edad(e) {
		std::cout << "Se ha creado una persona." << std::endl;
	}

	void presentarse() {
		std::cout << "Hola, soy" << nombre << "y tengo" << edad << "años." << std::endl;
	}
private:
	std::string nombre;
	int edad;
};
int main() {
	//SetConsoleOutputCP(1252);
	//SetConsoleOutputCP_UTF8);
	Persona Angel("Angel", 18);
	Angel.presentarse();
	return 0;
}


