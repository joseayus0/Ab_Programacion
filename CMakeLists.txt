# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SistemaHospitalario VERSION 1.0)

# Configurar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Configurar directorios de salida
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Incluir directorios de cabeceras
include_directories(
    ${PROJECT_SOURCE_DIR}/SistemaHospitalario/include
)

# Listar todos los archivos fuente
set(SOURCES
    ${PROJECT_SOURCE_DIR}/SistemaHospitalario/src/main.cpp
    ${PROJECT_SOURCE_DIR}/SistemaHospitalario/src/Paciente.cpp
    ${PROJECT_SOURCE_DIR}/SistemaHospitalario/src/Medico.cpp
    ${PROJECT_SOURCE_DIR}/SistemaHospitalario/src/Citamedica.cpp
    ${PROJECT_SOURCE_DIR}/SistemaHospitalario/src/DataManager.cpp
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Configurar instalación
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)