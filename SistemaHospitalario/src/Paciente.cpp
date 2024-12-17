#include "Paciente.hpp"
#include <iostream>

// Constructor de HistorialClinico.
HistorialClinico::HistorialClinico(const std::string& desc, const std::string& date)
    : descripcion(desc), fecha(date) {}

// Constructor de Paciente.
Paciente::Paciente(int id, const std::string& nombre, const std::string& direccion)
    : id(id), nombre(nombre), direccion(direccion) {}

// M�todo para actualizar la direcci�n del paciente.
void Paciente::actualizarDatos(const std::string& nuevaDireccion) {
    direccion = nuevaDireccion;
}

// M�todo para agregar un registro al historial cl�nico del paciente.
void Paciente::agregarHistorial(const std::string& descripcion, const std::string& fecha) {
    historial.emplace_back(descripcion, fecha);
}

// M�todo para mostrar el historial cl�nico del paciente.
void Paciente::mostrarHistorial() const { 
    std::cout << "Historial cl�nico de " << nombre << ":\n";
    for (const auto& registro : historial) {
        std::cout << "Fecha: " << registro.fecha
            << " - Descripci�n: " << registro.descripcion << std::endl;
    }
}

// M�todos para obtener informaci�n b�sica.
std::string Paciente::getNombre() const { return nombre; }
int Paciente::getId() const { return id; }
