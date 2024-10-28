#include <string>
#include <vector>
#include "HistorialClinico.h" // Archivo de la clase HistorialClinico

class Paciente {
private:
    std::string nombre;
    std::string identificacion;
    std::string contacto;
    std::string direccion;
    std::vector<HistorialClinico> historialClinico;

public:
    // Constructor
    Paciente(std::string nombre, std::string id, std::string contacto, std::string direccion)
        : nombre(nombre), identificacion(id), contacto(contacto), direccion(direccion) {}

    // Métodos de gestión
    void actualizarDatos(const std::string& nuevoContacto, const std::string& nuevaDireccion);
    void agregarHistorial(const HistorialClinico& nuevoHistorial);

    // Getters y Setters adicionales según necesidad
};


#include <string>

class HistorialClinico {
private:
    std::string fecha;
    std::string diagnostico;
    std::string tratamiento;

public:
    HistorialClinico(std::string fecha, std::string diagnostico, std::string tratamiento)
        : fecha(fecha), diagnostico(diagnostico), tratamiento(tratamiento) {}

    // Métodos para obtener información
    std::string obtenerDiagnostico() const { return diagnostico; }
    std::string obtenerFecha() const { return fecha; }
};


#include <string>
#include <map>

class Medico {
private:
    std::string nombre;
    std::string identificacion;
    std::string especialidad;
    std::map<std::string, bool> disponibilidad; // Disponibilidad por fecha

public:
    // Constructor
    Medico(std::string nombre, std::string id, std::string especialidad)
        : nombre(nombre), identificacion(id), especialidad(especialidad) {}

    // Métodos para gestión del médico
    void actualizarDisponibilidad(const std::string& fecha, bool estaDisponible);
};


#include <string>
#include "Paciente.h"
#include "Medico.h"

class CitaMedica {
private:
    Paciente paciente;
    Medico medico;
    std::string fecha;
    int urgencia;

public:
    // Constructor
    CitaMedica(Paciente paciente, Medico medico, std::string fecha, int urgencia)
        : paciente(paciente), medico(medico), fecha(fecha), urgencia(urgencia) {}

    // Métodos para gestionar citas
    void modificarCita(const std::string& nuevaFecha);
    void cancelarCita();
};


#include <vector>
#include "Paciente.h"
#include "CitaMedica.h"

class ReporteMedico {
private:
    std::vector<Paciente> listaPacientes;
    std::vector<CitaMedica> listaCitas;

public:
    // Métodos para generación de reportes
    void generarReportePorFecha(const std::string& fechaInicio, const std::string& fechaFin);
    void generarReportePorMedico(const Medico& medico);
    void reporteEnfermedadesCronicas();
};


#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"
#include "ReporteMedico.h"

class SistemaDeGestionHospitalaria {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<CitaMedica> citas;

public:
    // Métodos de registro y gestión del sistema
    void registrarPaciente(const Paciente& nuevoPaciente);
    void registrarMedico(const Medico& nuevoMedico);
    void programarCita(const CitaMedica& nuevaCita);
    void generarBackup(); // Función de backup
};
