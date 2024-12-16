#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>

// Clase para manejar la informaci�n del m�dico.
class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;

public:
    // Constructor para inicializar un m�dico.
    Medico(int id, const std::string& nombre, const std::string& especialidad);

    // M�todos para obtener informaci�n b�sica.
    std::string getNombre() const;
    std::string getEspecialidad() const;
    int getId() const;
};

#endif // MEDICO_HPP
