#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"
#include <iostream>


int main() {
    // Crear pacientes.
    std::cout << "Creando pacientes...\n";
    Paciente paciente1(1, "Juan Pérez", "Calle Falsa 123");
    Paciente paciente2(2, "María Gómez", "Avenida Siempre Viva 456");

    // Crear médicos.
    std::cout << "Creando médicos...\n";
    Medico medico1(1, "Dr. López", "Cardiología");
    Medico medico2(2, "Dra. Martínez", "Pediatría");

    // Agregar historial clínico al primer paciente.
    std::cout << "Agregando historial clínico al paciente Juan Pérez...\n";
    paciente1.agregarHistorial("Consulta inicial", "2024-11-10");
    paciente1.agregarHistorial("Revisión anual", "2024-12-15");

    // Crear citas médicas.
    std::cout << "Programando citas médicas...\n";
    CitaMedica cita1(1, &paciente1, &medico1, "2024-12-01", "Alta");
    CitaMedica cita2(2, &paciente2, &medico2, "2024-12-02", "Media");

    // Mostrar información del historial clínico del paciente 1.
    std::cout << "\nInformación del paciente Juan Pérez:\n";
    paciente1.mostrarHistorial();

    // Mostrar información de las citas programadas.
    std::cout << "\nCitas programadas:\n";
    cita1.mostrarCita();
    cita2.mostrarCita();



    // Actualizar la dirección del paciente 2.
    std::cout << "\nsctualizando la dirección del paciente María Gómez...\n";
    paciente2.actualizarDatos("Nueva Dirección 789");
    std::cout << "La nueva dirección de " << paciente2.getNombre() << " es actualizada con éxito.\n";

    // Fin del programa.
    std::cout << "\nFin del programa. ¡Gracias por usar el sistema de gestión hospitalaria!\n";

    return 0;
}

