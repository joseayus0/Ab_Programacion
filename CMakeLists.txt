# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SistemaHospitalario LANGUAGES CXX)

# Configurar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Especificar las carpetas de encabezados
include_directories(SistemaHospitalario/include)

# Agregar archivos fuente al ejecutable
add_executable(SistemaHospitalario
    SistemaHospitalario/main.cpp
    SistemaHospitalario/src/Citamedica.cpp
    SistemaHospitalario/src/Medico.cpp
    SistemaHospitalario/src/Paciente.cpp
)
