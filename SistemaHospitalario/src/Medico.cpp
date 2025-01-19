#include "Medico.hpp"

// Constructor de Medico que inicializa los atributos.
Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {
}

// Devuelve el nombre del m�dico.
std::string Medico::getNombre() const {
    return nombre;
}

// Devuelve la especialidad del m�dico.
std::string Medico::getEspecialidad() const {
    return especialidad;
}

// Devuelve el identificador �nico del m�dico.
int Medico::getId() const {
    return id;
}

// Modifica el nombre del m�dico.
void Medico::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}

// Modifica la especialidad del m�dico.
void Medico::setEspecialidad(const std::string& nuevaEspecialidad) {
    especialidad = nuevaEspecialidad;
}
