#include "Medico.hpp"

// Constructor de Medico.
Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

// Métodos para obtener la información básica del médico.
std::string Medico::getNombre() const { return nombre; }
std::string Medico::getEspecialidad() const { return especialidad; }
int Medico::getId() const { return id; }
