#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"
#include <iostream>


int main() {
    // Crear pacientes.
    std::cout << "Creando pacientes...\n";
    Paciente paciente1(1, "Juan Pérez", "Calle Falsa 123");
    Paciente paciente2(2, "María Gómez", "Avenida Siempre Viva 456");