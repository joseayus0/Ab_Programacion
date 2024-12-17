#include "Medico.hpp"

// Constructor de Medico.
Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

// M�todos para obtener la informaci�n b�sica del m�dico.
std::string Medico::getNombre() const { return nombre; }
std::string Medico::getEspecialidad() const { return especialidad; }
int Medico::getId() const { return id; }
