#include "CitaMedica.hpp"
#include <iostream>

// Constructor
CitaMedica::CitaMedica(int idCita, std::shared_ptr<Paciente> paciente, std::shared_ptr<Medico> medico, const std::string& fecha, const std::string& prioridad)
    : idCita(idCita), paciente(paciente), medico(medico), fecha(fecha), prioridad(prioridad) {
}

// Mostrar información de la cita
void CitaMedica::mostrarCita() const {
    std::cout << "Cita ID: " << idCita
        << " | Paciente: " << paciente->getNombre()
        << " | Medico: " << medico->getNombre()
        << " | Fecha: " << fecha
        << " | Prioridad: " << prioridad << "\n";
}

// Obtener ID de la cita
int CitaMedica::getId() const {
    return idCita;
}

// Modificar fecha de la cita
void CitaMedica::setFecha(const std::string& nuevaFecha) {
    fecha = nuevaFecha;
}

// Modificar prioridad de la cita
void CitaMedica::setPrioridad(const std::string& nuevaPrioridad) {
    prioridad = nuevaPrioridad;
}

// Modificar paciente de la cita
void CitaMedica::setPaciente(const std::shared_ptr<Paciente>& nuevoPaciente) {
    paciente = nuevoPaciente;
}

// Modificar médico de la cita
void CitaMedica::setMedico(const std::shared_ptr<Medico>& nuevoMedico) {
    medico = nuevoMedico;
}

// Obtener paciente
std::shared_ptr<Paciente> CitaMedica::getPaciente() const {
    return paciente;
}

// Obtener médico
std::shared_ptr<Medico> CitaMedica::getMedico() const {
    return medico;
}

// Obtener fecha
std::string CitaMedica::getFecha() const {
    return fecha;
}

// Obtener prioridad
std::string CitaMedica::getPrioridad() const {
    return prioridad;
}
