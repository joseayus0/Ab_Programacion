#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <vector>

// Clase para representar el historial cl�nico del paciente.
class HistorialClinico {
public:
    std::string descripcion;
    std::string fecha;

    // Constructor para inicializar un registro del historial cl�nico.
    HistorialClinico(const std::string& desc, const std::string& date);
};

// Clase para manejar la informaci�n del paciente.
class Paciente {
private:
    int id;
    std::string nombre;
    std::string direccion;
    std::vector<HistorialClinico> historial; // Lista de registros m�dicos.

public:
    // Constructor para inicializar un paciente.
    Paciente(int id, const std::string& nombre, const std::string& direccion);

    // M�todos para gestionar los datos del paciente.
    void actualizarDatos(const std::string& nuevaDireccion);
    void agregarHistorial(const std::string& descripcion, const std::string& fecha);
    void mostrarHistorial() const;

    // M�todos para obtener informaci�n b�sica.
    std::string getNombre() const;
    int getId() const;
};

#endif // PACIENTE_HPP
