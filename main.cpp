#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"
#include <iostream>


int main() {
    // Crear pacientes.
    std::cout << "Creando pacientes...\n";
    Paciente paciente1(1, "Juan P�rez", "Calle Falsa 123");
    Paciente paciente2(2, "Mar�a G�mez", "Avenida Siempre Viva 456");