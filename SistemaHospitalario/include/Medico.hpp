#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>

// Clase que representa un médico.
class Medico {
private:
    int id; // Identificador único del médico.
    std::string nombre; // Nombre completo del médico.
    std::string especialidad; // Especialidad médica.

public:
    // Constructor que inicializa un médico con su ID, nombre y especialidad.
    Medico(int id, const std::string& nombre, const std::string& especialidad);

    // Devuelve el nombre del médico.
    std::string getNombre() const;

    // Devuelve la especialidad del médico.
    std::string getEspecialidad() const;

    // Devuelve el identificador único del médico.
    int getId() const;

    // Permite actualizar el nombre del médico.
    void setNombre(const std::string& nuevoNombre);

    // Permite actualizar la especialidad del médico.
    void setEspecialidad(const std::string& nuevaEspecialidad);
};

#endif // MEDICO_HPP
