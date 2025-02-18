#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"

class DataManager {
private:
    const std::string DATA_DIR = "data/";
    const std::string BACKUP_DIR = "backup/";
    const std::string PACIENTES_FILE = "pacientes.txt";
    const std::string MEDICOS_FILE = "medicos.txt";
    const std::string CITAS_FILE = "citas.txt";

    void createDirectoryIfNotExists(const std::string& path);
    std::string getDataPath(const std::string& filename) const { return DATA_DIR + filename; }
    std::string getBackupPath(const std::string& filename) const { return BACKUP_DIR + filename; }

public:
    DataManager();

    void guardarPacientes(const std::vector<std::shared_ptr<Paciente>>& pacientes);
    void guardarMedicos(const std::vector<std::shared_ptr<Medico>>& medicos);
    void guardarCitas(const std::vector<CitaMedica>& citas);
    void realizarBackup();
    void restaurarBackup();

    std::vector<std::shared_ptr<Paciente>> cargarPacientes();
    std::vector<std::shared_ptr<Medico>> cargarMedicos();
    std::vector<CitaMedica> cargarCitas(
        const std::vector<std::shared_ptr<Paciente>>& pacientes,
        const std::vector<std::shared_ptr<Medico>>& medicos);
};