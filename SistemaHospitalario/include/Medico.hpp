#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>

// Clase que representa un m�dico.
class Medico {
private:
    int id; // Identificador �nico del m�dico.
    std::string nombre; // Nombre completo del m�dico.
    std::string especialidad; // Especialidad m�dica.

public:
    // Constructor que inicializa un m�dico con su ID, nombre y especialidad.
    Medico(int id, const std::string& nombre, const std::string& especialidad);

    // Devuelve el nombre del m�dico.
    std::string getNombre() const;

    // Devuelve la especialidad del m�dico.
    std::string getEspecialidad() const;

    // Devuelve el identificador �nico del m�dico.
    int getId() const;

    // Permite actualizar el nombre del m�dico.
    void setNombre(const std::string& nuevoNombre);

    // Permite actualizar la especialidad del m�dico.
    void setEspecialidad(const std::string& nuevaEspecialidad);
};

#endif // MEDICO_HPP
