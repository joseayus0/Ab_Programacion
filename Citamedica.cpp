#include "CitaMedica.hpp"
#include <iostream>

// Constructor de CitaMedica.
CitaMedica::CitaMedica(int id, Paciente* pac, Medico* med, const std::string& fecha, const std::string& prioridad)
    : idCita(id), paciente(pac), medico(med), fecha(fecha), prioridad(prioridad) {}

// Método para mostrar la información de la cita.
void CitaMedica::mostrarCita() const {
    std::cout << "Cita ID: " << idCita
        << " | Paciente: " << paciente->getNombre()
        << " | Médico: " << medico->getNombre()
        << " | Fecha: " << fecha
        << " | Prioridad: " << prioridad << std::endl;
}
