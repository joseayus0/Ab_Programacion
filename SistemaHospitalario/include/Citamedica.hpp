#ifndef CITAMEDICA_HPP
#define CITAMEDICA_HPP

#include <string>
#include <memory>
#include "Paciente.hpp"
#include "Medico.hpp"

// Clase para manejar citas médicas
class CitaMedica {
private:
    int idCita; // Identificador único de la cita
    std::shared_ptr<Paciente> paciente; // Paciente relacionado con la cita
    std::shared_ptr<Medico> medico;     // Médico relacionado con la cita
    std::string fecha;                  // Fecha de la cita
    std::string prioridad;              // Prioridad de la cita (Alta, Media, Baja)

public:
    // Constructor
    CitaMedica(int idCita, std::shared_ptr<Paciente> paciente, std::shared_ptr<Medico> medico, const std::string& fecha, const std::string& prioridad);

    // Métodos para mostrar y acceder a la cita
    void mostrarCita() const;
    int getId() const;

    // Métodos para modificar la cita
    void setFecha(const std::string& nuevaFecha);
    void setPrioridad(const std::string& nuevaPrioridad);
    void setPaciente(const std::shared_ptr<Paciente>& nuevoPaciente);
    void setMedico(const std::shared_ptr<Medico>& nuevoMedico);

    // Métodos para obtener atributos
    std::shared_ptr<Paciente> getPaciente() const;
    std::shared_ptr<Medico> getMedico() const;
    std::string getFecha() const;
    std::string getPrioridad() const;
};

#endif // CITAMEDICA_HPP
