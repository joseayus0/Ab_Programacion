#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"
#include <iostream>


int main() {
    // Crear pacientes.
    std::cout << "Creando pacientes...\n";
    Paciente paciente1(1, "Juan P�rez", "Calle Falsa 123");
    Paciente paciente2(2, "Mar�a G�mez", "Avenida Siempre Viva 456");

    // Crear m�dicos.
    std::cout << "Creando m�dicos...\n";
    Medico medico1(1, "Dr. L�pez", "Cardiolog�a");
    Medico medico2(2, "Dra. Mart�nez", "Pediatr�a");

    // Agregar historial cl�nico al primer paciente.
    std::cout << "Agregando historial cl�nico al paciente Juan P�rez...\n";
    paciente1.agregarHistorial("Consulta inicial", "2024-11-10");
    paciente1.agregarHistorial("Revisi�n anual", "2024-12-15");

    // Crear citas m�dicas.
    std::cout << "Programando citas m�dicas...\n";
    CitaMedica cita1(1, &paciente1, &medico1, "2024-12-01", "Alta");
    CitaMedica cita2(2, &paciente2, &medico2, "2024-12-02", "Media");

    // Mostrar informaci�n del historial cl�nico del paciente 1.
    std::cout << "\nInformaci�n del paciente Juan P�rez:\n";
    paciente1.mostrarHistorial();

    // Mostrar informaci�n de las citas programadas.
    std::cout << "\nCitas programadas:\n";
    cita1.mostrarCita();
    cita2.mostrarCita();



    // Actualizar la direcci�n del paciente 2.
    std::cout << "\nsctualizando la direcci�n del paciente Mar�a G�mez...\n";
    paciente2.actualizarDatos("Nueva Direcci�n 789");
    std::cout << "La nueva direcci�n de " << paciente2.getNombre() << " es actualizada con �xito.\n";

    // Fin del programa.
    std::cout << "\nFin del programa. �Gracias por usar el sistema de gesti�n hospitalaria!\n";

    return 0;
}

