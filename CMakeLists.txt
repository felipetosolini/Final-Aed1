cmake_minimum_required(VERSION 3.10)
project(SistemaGestionColecciones VERSION 1.0)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir directorios
include_directories(include)

# Agregar todos los archivos fuente
file(GLOB SOURCES "src/*.cpp")

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Configurar el nombre del ejecutable
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "sistema"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Mensaje de configuración
message(STATUS "Configurando ${PROJECT_NAME} versión ${PROJECT_VERSION}") 