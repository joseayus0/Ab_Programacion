#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"

// Vectores para almacenar dinámicamente los datos
std::vector<std::shared_ptr<Paciente>> pacientes;
std::vector<std::shared_ptr<Medico>> medicos;
std::vector<CitaMedica> citas;

// Declaraciones de funciones
void crearPaciente();
void mostrarPacientes();
void crearMedico();
void mostrarMedicos();
void modificarMedico();
void crearCita();
void mostrarCitas();
void modificarCita();

// Función para inicializar datos automáticos
void inicializarDatos() {
    auto paciente1 = std::make_shared<Paciente>(1, "Juan Perez", "Calle Falsa 123");
    auto paciente2 = std::make_shared<Paciente>(2, "Maria Gomez", "Avenida Siempre Viva 456");

    auto medico1 = std::make_shared<Medico>(1, "Dr. Lopez", "Cardiologia");
    auto medico2 = std::make_shared<Medico>(2, "Dra. Martinez", "Pediatria");

    pacientes.push_back(paciente1);
    pacientes.push_back(paciente2);
    medicos.push_back(medico1);
    medicos.push_back(medico2);

    citas.emplace_back(1, paciente1, medico1, "2024-12-01", "Alta");
    citas.emplace_back(2, paciente2, medico2, "2024-12-02", "Media");

    std::cout << "Datos iniciales cargados.\n";
}

// Función para crear un nuevo paciente
void crearPaciente() {
    std::string nombre, direccion;

    int id = static_cast<int>(pacientes.size() + 1);

    std::cout << "Ingrese nombre del paciente: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese direccion del paciente: ";
    std::getline(std::cin, direccion);

    pacientes.push_back(std::make_shared<Paciente>(id, nombre, direccion));
    std::cout << "Paciente creado con exito. ID asignado: " << id << "\n";
}

// Función para mostrar la lista de pacientes
void mostrarPacientes() {
    if (pacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
        return;
    }
    std::cout << "\nLista de Pacientes:\n";
    for (const auto& paciente : pacientes) {
        std::cout << "ID: " << paciente->getId()
            << " | Nombre: " << paciente->getNombre()
            << " | Direccion: " << paciente->getDireccion() << "\n";
    }
}

// Función para crear un nuevo médico
void crearMedico() {
    std::string nombre, especialidad;

    int id = static_cast<int>(medicos.size() + 1);

    std::cout << "Ingrese nombre del medico: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese especialidad del medico: ";
    std::getline(std::cin, especialidad);

    medicos.push_back(std::make_shared<Medico>(id, nombre, especialidad));
    std::cout << "Medico creado con exito. ID asignado: " << id << "\n";
}

// Función para mostrar la lista de médicos
void mostrarMedicos() {
    if (medicos.empty()) {
        std::cout << "No hay medicos registrados.\n";
        return;
    }
    std::cout << "\nLista de Medicos:\n";
    for (const auto& medico : medicos) {
        std::cout << "ID: " << medico->getId()
            << " | Nombre: " << medico->getNombre()
            << " | Especialidad: " << medico->getEspecialidad() << "\n";
    }
}

// Función para modificar un médico
void modificarMedico() {
    mostrarMedicos();

    int idMedico;
    std::cout << "Ingrese el ID del medico a modificar: ";
    std::cin >> idMedico;

    auto medicoIt = std::find_if(medicos.begin(), medicos.end(),
        [idMedico](const std::shared_ptr<Medico>& m) { return m->getId() == idMedico; });

    if (medicoIt == medicos.end()) {
        std::cout << "Medico no encontrado. Intente de nuevo.\n";
        return;
    }

    std::string nuevoNombre, nuevaEspecialidad;

    std::cout << "Modificar nombre actual (" << (*medicoIt)->getNombre() << "): ";
    std::cin.ignore();
    std::getline(std::cin, nuevoNombre);

    std::cout << "Modificar especialidad actual (" << (*medicoIt)->getEspecialidad() << "): ";
    std::getline(std::cin, nuevaEspecialidad);

    (*medicoIt)->setNombre(nuevoNombre);
    (*medicoIt)->setEspecialidad(nuevaEspecialidad);

    std::cout << "Medico modificado con exito.\n";
}
void crearCita() {
    int idPaciente, idMedico;
    std::string fecha, prioridad;

    // Mostrar lista de pacientes
    mostrarPacientes();
    std::cout << "Ingrese el ID del paciente para la cita: ";
    std::cin >> idPaciente;

    // Buscar paciente
    auto pacienteIt = std::find_if(pacientes.begin(), pacientes.end(),
        [idPaciente](const std::shared_ptr<Paciente>& p) { return p->getId() == idPaciente; });

    if (pacienteIt == pacientes.end()) {
        std::cout << "Paciente no encontrado. Intente de nuevo.\n";
        return;
    }

    // Mostrar lista de médicos
    mostrarMedicos();
    std::cout << "Ingrese el ID del medico para la cita: ";
    std::cin >> idMedico;

    // Buscar médico
    auto medicoIt = std::find_if(medicos.begin(), medicos.end(),
        [idMedico](const std::shared_ptr<Medico>& m) { return m->getId() == idMedico; });

    if (medicoIt == medicos.end()) {
        std::cout << "Medico no encontrado. Intente de nuevo.\n";
        return;
    }

    // Pedir fecha y prioridad
    std::cin.ignore();
    std::cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
    std::getline(std::cin, fecha);
    std::cout << "Ingrese la prioridad (Alta, Media, Baja): ";
    std::getline(std::cin, prioridad);

    // Crear y guardar la cita
    int idCita = static_cast<int>(citas.size() + 1);
    citas.emplace_back(idCita, *pacienteIt, *medicoIt, fecha, prioridad);
    std::cout << "Cita creada con exito. ID asignado: " << idCita << "\n";
}

// Función para modificar una cita médica
void modificarCita() {
    mostrarCitas();

    int idCita;
    std::cout << "Ingrese el ID de la cita a modificar: ";
    std::cin >> idCita;

    auto citaIt = std::find_if(citas.begin(), citas.end(),
        [idCita](const CitaMedica& cita) { return cita.getId() == idCita; });

    if (citaIt == citas.end()) {
        std::cout << "Cita no encontrada. Intente de nuevo.\n";
        return;
    }

    std::string nuevaFecha, nuevaPrioridad;
    int nuevoIdMedico, nuevoIdPaciente;

    std::cout << "Modificar fecha actual (" << citaIt->getFecha() << "): ";
    std::cin.ignore();
    std::getline(std::cin, nuevaFecha);

    std::cout << "Modificar prioridad actual (" << citaIt->getPrioridad() << "): ";
    std::getline(std::cin, nuevaPrioridad);

    mostrarPacientes();
    std::cout << "Seleccione un nuevo ID de paciente (actual: " << citaIt->getPaciente()->getId() << "): ";
    std::cin >> nuevoIdPaciente;

    auto nuevoPacienteIt = std::find_if(pacientes.begin(), pacientes.end(),
        [nuevoIdPaciente](const std::shared_ptr<Paciente>& p) { return p->getId() == nuevoIdPaciente; });

    if (nuevoPacienteIt == pacientes.end()) {
        std::cout << "Paciente no encontrado. Intente de nuevo.\n";
        return;
    }

    mostrarMedicos();
    std::cout << "Seleccione un nuevo ID de medico (actual: " << citaIt->getMedico()->getId() << "): ";
    std::cin >> nuevoIdMedico;

    auto nuevoMedicoIt = std::find_if(medicos.begin(), medicos.end(),
        [nuevoIdMedico](const std::shared_ptr<Medico>& m) { return m->getId() == nuevoIdMedico; });

    if (nuevoMedicoIt == medicos.end()) {
        std::cout << "Medico no encontrado. Intente de nuevo.\n";
        return;
    }

    citaIt->setFecha(nuevaFecha);
    citaIt->setPrioridad(nuevaPrioridad);
    citaIt->setPaciente(*nuevoPacienteIt);
    citaIt->setMedico(*nuevoMedicoIt);

    std::cout << "Cita modificada con exito.\n";
}

// Función para mostrar todas las citas
void mostrarCitas() {
    if (citas.empty()) {
        std::cout << "No hay citas programadas.\n";
        return;
    }
    std::cout << "\nLista de Citas Programadas:\n";
    for (const auto& cita : citas) {
        cita.mostrarCita();
    }
}

// Menú principal
int main() {
    inicializarDatos();

    int opcion;
    do {
        std::cout << "\nSistema de Gestion Hospitalaria:\n";
        std::cout << "1. Crear paciente\n";
        std::cout << "2. Mostrar pacientes\n";
        std::cout << "3. Crear cita medica\n";
        std::cout << "4. Mostrar citas\n";
        std::cout << "5. Modificar cita\n";
        std::cout << "6. Crear medico\n";
        std::cout << "7. Mostrar medicos\n";
        std::cout << "8. Modificar medico\n";
        std::cout << "9. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            crearPaciente();
            break;
        case 2:
            mostrarPacientes();
            break;
        case 3:
            crearCita();
            break;
        case 4:
            mostrarCitas();
            break;
        case 5:
            modificarCita();
            break;
        case 6:
            crearMedico();
            break;
        case 7:
            mostrarMedicos();
            break;
        case 8:
            modificarMedico();
            break;
        case 9:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 9);

    return 0;
}
