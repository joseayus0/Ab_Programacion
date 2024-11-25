#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <vector>

// Clase para representar el historial clínico del paciente.
class HistorialClinico {
public:
    std::string descripcion;
    std::string fecha;

    // Constructor para inicializar un registro del historial clínico.
    HistorialClinico(const std::string& desc, const std::string& date);
};

// Clase para manejar la información del paciente.
class Paciente {
private:
    int id;
    std::string nombre;
    std::string direccion;
    std::vector<HistorialClinico> historial; // Lista de registros médicos.

public:
    // Constructor para inicializar un paciente.
    Paciente(int id, const std::string& nombre, const std::string& direccion);

    // Métodos para gestionar los datos del paciente.
    void actualizarDatos(const std::string& nuevaDireccion);
    void agregarHistorial(const std::string& descripcion, const std::string& fecha);
    void mostrarHistorial() const;

    // Métodos para obtener información básica.
    std::string getNombre() const;
    int getId() const;
};

#endif // PACIENTE_HPP
