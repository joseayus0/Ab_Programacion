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

// Actualiza la direcci�n del paciente.
void Paciente::actualizarDireccion(const std::string& nuevaDireccion) {
    direccion = nuevaDireccion;
}

// Agrega un registro al historial cl�nico del paciente.
void Paciente::agregarHistorial(const std::string& descripcion, const std::string& fecha) {
    historial.emplace_back(descripcion, fecha);
}

// Muestra el historial cl�nico completo del paciente.
void Paciente::mostrarHistorial() const {
    std::cout << "Historial cl�nico de " << nombre << ":\n";
    for (const auto& registro : historial) {
        std::cout << "Fecha: " << registro.fecha
            << " - Descripci�n: " << registro.descripcion << std::endl;
    }
}

// Devuelve el nombre del paciente.
std::string Paciente::getNombre() const {
    return nombre;
}

// Devuelve el identificador �nico del paciente.
int Paciente::getId() const {
    return id;
}

// Devuelve la direcci�n del paciente.
std::string Paciente::getDireccion() const {
    return direccion;
}
