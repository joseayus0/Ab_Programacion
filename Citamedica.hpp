#ifndef CITAMEDICA_HPP
#define CITAMEDICA_HPP

#include "Paciente.hpp"
#include "Medico.hpp"
#include <string>

// Clase para manejar citas m�dicas.
class CitaMedica {
private:
    int idCita;
    Paciente* paciente; // Relaci�n con un paciente.
    Medico* medico;     // Relaci�n con un m�dico.
    std::string fecha;
    std::string prioridad;

public:
    // Constructor para inicializar una cita m�dica.
    CitaMedica(int id, Paciente* pac, Medico* med, const std::string& fecha, const std::string& prioridad);

    // M�todo para mostrar la informaci�n de la cita.
    void mostrarCita() const;
};

#endif // CITAMEDICA_HPP
