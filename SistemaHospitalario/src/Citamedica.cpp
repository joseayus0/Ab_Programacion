#include "CitaMedica.hpp"
#include <iostream>

// Constructor de CitaMedica.
CitaMedica::CitaMedica(int id, Paciente* pac, Medico* med, const std::string& fecha, const std::string& prioridad)
    : idCita(id), paciente(pac), medico(med), fecha(fecha), prioridad(prioridad) {}

// M�todo para mostrar la informaci�n de la cita.
void CitaMedica::mostrarCita() const {
    std::cout << "Cita ID: " << idCita
        << " | Paciente: " << paciente->getNombre()
        << " | M�dico: " << medico->getNombre()
        << " | Fecha: " << fecha
        << " | Prioridad: " << prioridad << std::endl;
}
