#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <vector>

// Clase que representa un registro en el historial cl�nico de un paciente.
class HistorialClinico {
public:
    std::string descripcion; // Descripci�n del registro cl�nico.
    std::string fecha; // Fecha del registro.

    // Constructor que inicializa un registro del historial cl�nico.
    HistorialClinico(const std::string& desc, const std::string& date);
};

// Clase que representa a un paciente.
class Paciente {
private:
    int id; // Identificador �nico del paciente.
    std::string nombre; // Nombre completo del paciente.
    std::string direccion; // Direcci�n del paciente.
    std::vector<HistorialClinico> historial; // Lista de registros cl�nicos.

public:
    // Constructor que inicializa un paciente con su ID, nombre y direcci�n.
    Paciente(int id, const std::string& nombre, const std::string& direccion);

    // Permite actualizar la direcci�n del paciente.
    void actualizarDireccion(const std::string& nuevaDireccion);

    // Agrega un registro al historial cl�nico del paciente.
    void agregarHistorial(const std::string& descripcion, const std::string& fecha);

    // Muestra el historial cl�nico completo del paciente.
    void mostrarHistorial() const;

    // Devuelve el nombre del paciente.
    std::string getNombre() const;

    // Devuelve el identificador �nico del paciente.
    int getId() const;

    // Devuelve la direcci�n del paciente.
    std::string getDireccion() const;
};

#endif // PACIENTE_HPP
