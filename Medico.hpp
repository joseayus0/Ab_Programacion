#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>

// Clase para manejar la información del médico.
class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;

public:
    // Constructor para inicializar un médico.
    Medico(int id, const std::string& nombre, const std::string& especialidad);

    // Métodos para obtener información básica.
    std::string getNombre() const;
    std::string getEspecialidad() const;
    int getId() const;
};

#endif // MEDICO_HPP
