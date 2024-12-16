#include "Paciente.hpp"
#include <iostream>

// Constructor de HistorialClinico.
HistorialClinico::HistorialClinico(const std::string& desc, const std::string& date)
    : descripcion(desc), fecha(date) {}

// Constructor de Paciente.
Paciente::Paciente(int id, const std::string& nombre, const std::string& direccion)
    : id(id), nombre(nombre), direccion(direccion) {}

// Método para actualizar la dirección del paciente.
void Paciente::actualizarDatos(const std::string& nuevaDireccion) {
    direccion = nuevaDireccion;
}

// Método para agregar un registro al historial clínico del paciente.
void Paciente::agregarHistorial(const std::string& descripcion, const std::string& fecha) {
    historial.emplace_back(descripcion, fecha);
}

// Método para mostrar el historial clínico del paciente.
void Paciente::mostrarHistorial() const { 
    std::cout << "Historial clínico de " << nombre << ":\n";
    for (const auto& registro : historial) {
        std::cout << "Fecha: " << registro.fecha
            << " - Descripción: " << registro.descripcion << std::endl;
    }
}

// Métodos para obtener información básica.
std::string Paciente::getNombre() const { return nombre; }
int Paciente::getId() const { return id; }
