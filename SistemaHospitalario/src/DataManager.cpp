#include "DataManager.hpp"
#include <filesystem>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

DataManager::DataManager() {
    createDirectoryIfNotExists(DATA_DIR);
    createDirectoryIfNotExists(BACKUP_DIR);
}

void DataManager::createDirectoryIfNotExists(const std::string& path) {
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directories(path);
    }
}

void DataManager::guardarPacientes(const std::vector<std::shared_ptr<Paciente>>& pacientes) {
    std::ofstream file(getDataPath(PACIENTES_FILE));
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo de pacientes para escritura");
    }

    for (const auto& paciente : pacientes) {
        file << paciente->getId() << "|"
            << paciente->getNombre() << "|"
            << paciente->getDireccion() << "\n";
    }
}

void DataManager::guardarMedicos(const std::vector<std::shared_ptr<Medico>>& medicos) {
    std::ofstream file(getDataPath(MEDICOS_FILE));
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo de médicos para escritura");
    }

    for (const auto& medico : medicos) {
        file << medico->getId() << "|"
            << medico->getNombre() << "|"
            << medico->getEspecialidad() << "\n";
    }
}

void DataManager::guardarCitas(const std::vector<CitaMedica>& citas) {
    std::ofstream file(getDataPath(CITAS_FILE));
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo de citas para escritura");
    }

    for (const auto& cita : citas) {
        file << cita.getId() << "|"
            << cita.getPaciente()->getId() << "|"
            << cita.getMedico()->getId() << "|"
            << cita.getFecha() << "|"
            << cita.getPrioridad() << "\n";
    }
}

std::vector<std::shared_ptr<Paciente>> DataManager::cargarPacientes() {
    std::vector<std::shared_ptr<Paciente>> pacientes;
    std::ifstream file(getDataPath(PACIENTES_FILE));
    if (!file) {
        return pacientes;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id_str, nombre, direccion;

        std::getline(ss, id_str, '|');
        std::getline(ss, nombre, '|');
        std::getline(ss, direccion);

        try {
            int id = std::stoi(id_str);
            pacientes.push_back(std::make_shared<Paciente>(id, nombre, direccion));
        }
        catch (const std::exception& e) {
            std::cout << "Error al cargar paciente: " << e.what() << std::endl;
        }
    }

    return pacientes;
}

std::vector<std::shared_ptr<Medico>> DataManager::cargarMedicos() {
    std::vector<std::shared_ptr<Medico>> medicos;
    std::ifstream file(getDataPath(MEDICOS_FILE));
    if (!file) {
        return medicos;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id_str, nombre, especialidad;

        std::getline(ss, id_str, '|');
        std::getline(ss, nombre, '|');
        std::getline(ss, especialidad);

        try {
            int id = std::stoi(id_str);
            medicos.push_back(std::make_shared<Medico>(id, nombre, especialidad));
        }
        catch (const std::exception& e) {
            std::cout << "Error al cargar médico: " << e.what() << std::endl;
        }
    }

    return medicos;
}

std::vector<CitaMedica> DataManager::cargarCitas(
    const std::vector<std::shared_ptr<Paciente>>& pacientes,
    const std::vector<std::shared_ptr<Medico>>& medicos) {

    std::vector<CitaMedica> citas;
    std::ifstream file(getDataPath(CITAS_FILE));
    if (!file) {
        return citas;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id_str, paciente_id_str, medico_id_str, fecha, prioridad;

        std::getline(ss, id_str, '|');
        std::getline(ss, paciente_id_str, '|');
        std::getline(ss, medico_id_str, '|');
        std::getline(ss, fecha, '|');
        std::getline(ss, prioridad);

        try {
            int id = std::stoi(id_str);
            int paciente_id = std::stoi(paciente_id_str);
            int medico_id = std::stoi(medico_id_str);

            auto paciente = std::find_if(pacientes.begin(), pacientes.end(),
                [paciente_id](const std::shared_ptr<Paciente>& p) {
                    return p->getId() == paciente_id;
                });

            auto medico = std::find_if(medicos.begin(), medicos.end(),
                [medico_id](const std::shared_ptr<Medico>& m) {
                    return m->getId() == medico_id;
                });

            if (paciente != pacientes.end() && medico != medicos.end()) {
                citas.emplace_back(id, *paciente, *medico, fecha, prioridad);
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error al cargar cita: " << e.what() << std::endl;
        }
    }

    return citas;
}
void DataManager::realizarBackup() {
    try {
        std::filesystem::copy(getDataPath(PACIENTES_FILE), getBackupPath(PACIENTES_FILE),
            std::filesystem::copy_options::overwrite_existing);
        std::filesystem::copy(getDataPath(MEDICOS_FILE), getBackupPath(MEDICOS_FILE),
            std::filesystem::copy_options::overwrite_existing);
        std::filesystem::copy(getDataPath(CITAS_FILE), getBackupPath(CITAS_FILE),
            std::filesystem::copy_options::overwrite_existing);
    }
    catch (const std::exception& e) {
        std::cout << "Error al realizar backup: " << e.what() << std::endl;
    }
}

void DataManager::restaurarBackup() {
    try {
        std::filesystem::copy(getBackupPath(PACIENTES_FILE), getDataPath(PACIENTES_FILE),
            std::filesystem::copy_options::overwrite_existing);
        std::filesystem::copy(getBackupPath(MEDICOS_FILE), getDataPath(MEDICOS_FILE),
            std::filesystem::copy_options::overwrite_existing);
        std::filesystem::copy(getBackupPath(CITAS_FILE), getDataPath(CITAS_FILE),
            std::filesystem::copy_options::overwrite_existing);
    }
    catch (const std::exception& e) {
        std::cout << "Error al restaurar backup: " << e.what() << std::endl;
    }
}