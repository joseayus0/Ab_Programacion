#include "Paciente.hpp"
#include <iostream>

// Constructor de HistorialClinico que inicializa un registro del historial.
HistorialClinico::HistorialClinico(const std::string& desc, const std::string& date)
    : descripcion(desc), fecha(date) {
}

// Constructor de Paciente que inicializa los atributos principales.
Paciente::Paciente(int id, const std::string& nombre, const std::string& direccion)
    : id(id), nombre(nombre), direccion(direccion) {
}

// Actualiza la dirección del paciente.
void Paciente::actualizarDireccion(const std::string& nuevaDireccion) {
    direccion = nuevaDireccion;
}

// Agrega un registro al historial clínico del paciente.
void Paciente::agregarHistorial(const std::string& descripcion, const std::string& fecha) {
    historial.emplace_back(descripcion, fecha);
}

// Muestra el historial clínico completo del paciente.
void Paciente::mostrarHistorial() const {
    std::cout << "Historial clínico de " << nombre << ":\n";
    for (const auto& registro : historial) {
        std::cout << "Fecha: " << registro.fecha
            << " - Descripción: " << registro.descripcion << std::endl;
    }
}

// Devuelve el nombre del paciente.
std::string Paciente::getNombre() const {
    return nombre;
}

// Devuelve el identificador único del paciente.
int Paciente::getId() const {
    return id;
}

// Devuelve la dirección del paciente.
std::string Paciente::getDireccion() const {
    return direccion;
}
