#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <vector>

// Clase que representa un registro en el historial clínico de un paciente.
class HistorialClinico {
public:
    std::string descripcion; // Descripción del registro clínico.
    std::string fecha; // Fecha del registro.

    // Constructor que inicializa un registro del historial clínico.
    HistorialClinico(const std::string& desc, const std::string& date);
};

// Clase que representa a un paciente.
class Paciente {
private:
    int id; // Identificador único del paciente.
    std::string nombre; // Nombre completo del paciente.
    std::string direccion; // Dirección del paciente.
    std::vector<HistorialClinico> historial; // Lista de registros clínicos.

public:
    // Constructor que inicializa un paciente con su ID, nombre y dirección.
    Paciente(int id, const std::string& nombre, const std::string& direccion);

    // Permite actualizar la dirección del paciente.
    void actualizarDireccion(const std::string& nuevaDireccion);

    // Agrega un registro al historial clínico del paciente.
    void agregarHistorial(const std::string& descripcion, const std::string& fecha);

    // Muestra el historial clínico completo del paciente.
    void mostrarHistorial() const;

    // Devuelve el nombre del paciente.
    std::string getNombre() const;

    // Devuelve el identificador único del paciente.
    int getId() const;

    // Devuelve la dirección del paciente.
    std::string getDireccion() const;
};

#endif // PACIENTE_HPP
