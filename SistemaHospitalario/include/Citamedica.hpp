#ifndef CITAMEDICA_HPP
#define CITAMEDICA_HPP

#include "Paciente.hpp"
#include "Medico.hpp"
#include <string>

// Clase para manejar citas médicas.
class CitaMedica {
private:
    int idCita;
    Paciente* paciente; // Relación con un paciente.
    Medico* medico;     // Relación con un médico.
    std::string fecha;
    std::string prioridad;

public:
    // Constructor para inicializar una cita médica.
    CitaMedica(int id, Paciente* pac, Medico* med, const std::string& fecha, const std::string& prioridad);

    // Método para mostrar la información de la cita.
    void mostrarCita() const;
};

#endif // CITAMEDICA_HPP
