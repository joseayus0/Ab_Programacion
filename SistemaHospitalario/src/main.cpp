#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <limits>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"
#include "DataManager.hpp"

// Variables globales para almacenar los datos en memoria
std::vector<std::shared_ptr<Paciente>> pacientes;
std::vector<std::shared_ptr<Medico>> medicos;
std::vector<CitaMedica> citas;
DataManager dataManager;

// Declaraciones de funciones
void crearPaciente();
void mostrarPacientes();
void eliminarPaciente();
void crearMedico();
void mostrarMedicos();
void modificarMedico();
void eliminarMedico();
void crearCita();
void mostrarCitas();
void modificarCita();
void eliminarCita();
void guardarCambios();
void cargarDatos();

// Funci�n para manejar errores
void manejarError(const std::string& mensaje, const std::exception& e) {
    std::cerr << "Error - " << mensaje << ": " << e.what() << std::endl;
}

// Funci�n para cargar datos iniciales
void cargarDatos() {
    try {
        pacientes = dataManager.cargarPacientes();
        medicos = dataManager.cargarMedicos();
        citas = dataManager.cargarCitas(pacientes, medicos);  // Pasamos los vectores como argumentos
        std::cout << "Datos cargados exitosamente.\n";
    }
    catch (const std::exception& e) {
        manejarError("al cargar datos", e);
        std::cout << "Iniciando con base de datos vac�a.\n";
    }
}

// Funci�n para guardar todos los cambios
void guardarCambios() {
    try {
        dataManager.guardarPacientes(pacientes);
        dataManager.guardarMedicos(medicos);
        dataManager.guardarCitas(citas);
        dataManager.realizarBackup();
        std::cout << "Datos guardados exitosamente.\n";
    }
    catch (const std::exception& e) {
        manejarError("al guardar datos", e);
    }
}

// Funci�n para mostrar pacientes
void mostrarPacientes() {
    if (pacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
        return;
    }
    std::cout << "\nLista de Pacientes:\n";
    for (const auto& paciente : pacientes) {
        std::cout << "ID: " << paciente->getId()
            << " | Nombre: " << paciente->getNombre()
            << " | Direcci�n: " << paciente->getDireccion() << "\n";
    }
}

// Funci�n para crear un nuevo paciente
void crearPaciente() {
    try {
        std::string nombre, direccion;
        int id = pacientes.empty() ? 1 : pacientes.back()->getId() + 1;

        std::cout << "Ingrese nombre del paciente: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Ingrese direccion del paciente: ";
        std::getline(std::cin, direccion);

        auto nuevoPaciente = std::make_shared<Paciente>(id, nombre, direccion);
        pacientes.push_back(nuevoPaciente);

        guardarCambios();
        std::cout << "Paciente creado con �xito. ID asignado: " << id << "\n";
    }
    catch (const std::exception& e) {
        manejarError("al crear paciente", e);
    }
}

// Funci�n para eliminar un paciente
void eliminarPaciente() {
    try {
        mostrarPacientes();
        if (pacientes.empty()) return;

        int id;
        std::cout << "Ingrese el ID del paciente a eliminar: ";
        std::cin >> id;

        auto it = std::find_if(pacientes.begin(), pacientes.end(),
            [id](const std::shared_ptr<Paciente>& p) { return p->getId() == id; });

        if (it != pacientes.end()) {
            // Verificar si tiene citas pendientes
            auto tieneCitas = std::any_of(citas.begin(), citas.end(),
                [id](const CitaMedica& c) { return c.getPaciente()->getId() == id; });

            if (tieneCitas) {
                std::cout << "No se puede eliminar el paciente porque tiene citas pendientes.\n";
                return;
            }

            pacientes.erase(it);
            guardarCambios();
            std::cout << "Paciente eliminado con �xito.\n";
        }
        else {
            std::cout << "Paciente no encontrado.\n";
        }
    }
    catch (const std::exception& e) {
        manejarError("al eliminar paciente", e);
    }
}

// Funci�n para mostrar m�dicos
void mostrarMedicos() {
    if (medicos.empty()) {
        std::cout << "No hay m�dicos registrados.\n";
        return;
    }
    std::cout << "\nLista de M�dicos:\n";
    for (const auto& medico : medicos) {
        std::cout << "ID: " << medico->getId()
            << " | Nombre: " << medico->getNombre()
            << " | Especialidad: " << medico->getEspecialidad() << "\n";
    }
}
// Funci�n para crear un nuevo m�dico
void crearMedico() {
    try {
        std::string nombre, especialidad;
        int id = medicos.empty() ? 1 : medicos.back()->getId() + 1;

        std::cout << "Ingrese nombre del m�dico: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Ingrese especialidad del m�dico: ";
        std::getline(std::cin, especialidad);

        auto nuevoMedico = std::make_shared<Medico>(id, nombre, especialidad);
        medicos.push_back(nuevoMedico);

        guardarCambios();
        std::cout << "M�dico creado con �xito. ID asignado: " << id << "\n";
    }
    catch (const std::exception& e) {
        manejarError("al crear m�dico", e);
    }
}

// Funci�n para modificar m�dico
void modificarMedico() {
    try {
        mostrarMedicos();
        if (medicos.empty()) return;

        int id;
        std::cout << "Ingrese el ID del m�dico a modificar: ";
        std::cin >> id;

        auto it = std::find_if(medicos.begin(), medicos.end(),
            [id](const std::shared_ptr<Medico>& m) { return m->getId() == id; });

        if (it != medicos.end()) {
            std::string nuevoNombre, nuevaEspecialidad;

            std::cout << "Ingrese nuevo nombre (" << (*it)->getNombre() << "): ";
            std::cin.ignore();
            std::getline(std::cin, nuevoNombre);

            std::cout << "Ingrese nueva especialidad (" << (*it)->getEspecialidad() << "): ";
            std::getline(std::cin, nuevaEspecialidad);

            (*it)->setNombre(nuevoNombre);
            (*it)->setEspecialidad(nuevaEspecialidad);

            guardarCambios();
            std::cout << "M�dico modificado con �xito.\n";
        }
        else {
            std::cout << "M�dico no encontrado.\n";
        }
    }
    catch (const std::exception& e) {
        manejarError("al modificar m�dico", e);
    }
}

// Funci�n para eliminar m�dico
void eliminarMedico() {
    try {
        mostrarMedicos();
        if (medicos.empty()) return;

        int id;
        std::cout << "Ingrese el ID del m�dico a eliminar: ";
        std::cin >> id;

        auto it = std::find_if(medicos.begin(), medicos.end(),
            [id](const std::shared_ptr<Medico>& m) { return m->getId() == id; });

        if (it != medicos.end()) {
            // Verificar si tiene citas pendientes
            auto tieneCitas = std::any_of(citas.begin(), citas.end(),
                [id](const CitaMedica& c) { return c.getMedico()->getId() == id; });

            if (tieneCitas) {
                std::cout << "No se puede eliminar el m�dico porque tiene citas pendientes.\n";
                return;
            }

            medicos.erase(it);
            guardarCambios();
            std::cout << "M�dico eliminado con �xito.\n";
        }
        else {
            std::cout << "M�dico no encontrado.\n";
        }
    }
    catch (const std::exception& e) {
        manejarError("al eliminar m�dico", e);
    }
}
// Funci�n para mostrar citas
void mostrarCitas() {
    if (citas.empty()) {
        std::cout << "No hay citas programadas.\n";
        return;
    }
    std::cout << "\nLista de Citas:\n";
    for (const auto& cita : citas) {
        cita.mostrarCita();
    }
}

// Funci�n para crear una nueva cita
void crearCita() {
    try {
        if (pacientes.empty() || medicos.empty()) {
            std::cout << "Debe haber al menos un paciente y un m�dico registrados.\n";
            return;
        }

        mostrarPacientes();
        int idPaciente;
        std::cout << "Ingrese el ID del paciente: ";
        std::cin >> idPaciente;

        auto paciente = std::find_if(pacientes.begin(), pacientes.end(),
            [idPaciente](const std::shared_ptr<Paciente>& p) {
                return p->getId() == idPaciente;
            });

        if (paciente == pacientes.end()) {
            std::cout << "Paciente no encontrado.\n";
            return;
        }

        mostrarMedicos();
        int idMedico;
        std::cout << "Ingrese el ID del m�dico: ";
        std::cin >> idMedico;

        auto medico = std::find_if(medicos.begin(), medicos.end(),
            [idMedico](const std::shared_ptr<Medico>& m) {
                return m->getId() == idMedico;
            });

        if (medico == medicos.end()) {
            std::cout << "M�dico no encontrado.\n";
            return;
        }

        std::string fecha, prioridad;
        std::cin.ignore();

        std::cout << "Ingrese fecha (YYYY-MM-DD): ";
        std::getline(std::cin, fecha);

        std::cout << "Ingrese prioridad (Alta/Media/Baja): ";
        std::getline(std::cin, prioridad);

        int idCita = citas.empty() ? 1 : citas.back().getId() + 1;
        citas.emplace_back(idCita, *paciente, *medico, fecha, prioridad);

        guardarCambios();
        std::cout << "Cita creada con �xito. ID: " << idCita << "\n";
    }
    catch (const std::exception& e) {
        manejarError("al crear cita", e);
    }
}

// Funci�n para modificar cita
void modificarCita() {
    try {
        mostrarCitas();
        if (citas.empty()) return;

        int id;
        std::cout << "Ingrese el ID de la cita a modificar: ";
        std::cin >> id;

        auto it = std::find_if(citas.begin(), citas.end(),
            [id](const CitaMedica& c) { return c.getId() == id; });

        if (it != citas.end()) {
            std::string nuevaFecha, nuevaPrioridad;

            std::cout << "Ingrese nueva fecha (" << it->getFecha() << "): ";
            std::cin.ignore();
            std::getline(std::cin, nuevaFecha);

            std::cout << "Ingrese nueva prioridad (" << it->getPrioridad() << "): ";
            std::getline(std::cin, nuevaPrioridad);

            it->setFecha(nuevaFecha);
            it->setPrioridad(nuevaPrioridad);

            guardarCambios();
            std::cout << "Cita modificada con �xito.\n";
        }
        else {
            std::cout << "Cita no encontrada.\n";
        }
    }
    catch (const std::exception& e) {
        manejarError("al modificar cita", e);
    }
}

// Funci�n para eliminar cita
void eliminarCita() {
    try {
        mostrarCitas();
        if (citas.empty()) return;

        int id;
        std::cout << "Ingrese el ID de la cita a eliminar: ";
        std::cin >> id;

        auto it = std::find_if(citas.begin(), citas.end(),
            [id](const CitaMedica& c) { return c.getId() == id; });

        if (it != citas.end()) {
            citas.erase(it);
            guardarCambios();
            std::cout << "Cita eliminada con �xito.\n";
        }
        else {
            std::cout << "Cita no encontrada.\n";
        }
    }
    catch (const std::exception& e) {
        manejarError("al eliminar cita", e);
    }
}
// Funci�n principal
int main() {
    std::cout << "Sistema de Gesti�n Hospitalaria\n";
    std::cout << "Cargando datos...\n";
    cargarDatos();

    int opcion;
    do {
        std::cout << "\n=== Men� Principal ===\n";
        std::cout << "1. Gesti�n de Pacientes\n";
        std::cout << "2. Gesti�n de M�dicos\n";
        std::cout << "3. Gesti�n de Citas\n";
        std::cout << "4. Guardar Cambios\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opci�n: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inv�lida. Por favor, ingrese un n�mero.\n";
            continue;
        }

        switch (opcion) {
        case 1: {
            int subOpcion;
            std::cout << "\n=== Gesti�n de Pacientes ===\n";
            std::cout << "1. Crear Paciente\n";
            std::cout << "2. Mostrar Pacientes\n";
            std::cout << "3. Eliminar Paciente\n";
            std::cout << "4. Volver\n";
            std::cout << "Seleccione una opci�n: ";
            std::cin >> subOpcion;

            switch (subOpcion) {
            case 1: crearPaciente(); break;
            case 2: mostrarPacientes(); break;
            case 3: eliminarPaciente(); break;
            case 4: break;
            default: std::cout << "Opci�n inv�lida\n";
            }
            break;
        }
        case 2: {
            int subOpcion;
            std::cout << "\n=== Gesti�n de M�dicos ===\n";
            std::cout << "1. Crear M�dico\n";
            std::cout << "2. Mostrar M�dicos\n";
            std::cout << "3. Modificar M�dico\n";
            std::cout << "4. Eliminar M�dico\n";
            std::cout << "5. Volver\n";
            std::cout << "Seleccione una opci�n: ";
            std::cin >> subOpcion;

            switch (subOpcion) {
            case 1: crearMedico(); break;
            case 2: mostrarMedicos(); break;
            case 3: modificarMedico(); break;
            case 4: eliminarMedico(); break;
            case 5: break;
            default: std::cout << "Opci�n inv�lida\n";
            }
            break;
        }
        case 3: {
            int subOpcion;
            std::cout << "\n=== Gesti�n de Citas ===\n";
            std::cout << "1. Crear Cita\n";
            std::cout << "2. Mostrar Citas\n";
            std::cout << "3. Modificar Cita\n";
            std::cout << "4. Eliminar Cita\n";
            std::cout << "5. Volver\n";
            std::cout << "Seleccione una opci�n: ";
            std::cin >> subOpcion;

            switch (subOpcion) {
            case 1: crearCita(); break;
            case 2: mostrarCitas(); break;
            case 3: modificarCita(); break;
            case 4: eliminarCita(); break;
            case 5: break;
            default: std::cout << "Opci�n inv�lida\n";
            }
            break;
        }
        case 4: {
            guardarCambios();
            break;
        }
        case 5: {
            std::cout << "Guardando datos antes de salir...\n";
            guardarCambios();
            std::cout << "�Hasta luego!\n";
            break;
        }
        default: {
            std::cout << "Opci�n inv�lida\n";
        }
        }
    } while (opcion != 5);

    return 0;
}