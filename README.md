# Sistema de Gestión de Recursos Digitales

## Descripción
Este proyecto implementa un sistema de gestión de recursos digitales que permite administrar diferentes tipos de recursos como libros y archivos de audio. El sistema está diseñado para manejar usuarios, recursos y sus interacciones de manera eficiente.

## Características Principales
- Gestión de usuarios (registro, login, logout)
- Administración de recursos digitales:
  - Libros (título, autor, año, editorial)
  - Archivos de audio (título, artista, duración, formato)
- Sistema de préstamos y devoluciones
- Búsqueda de recursos por diferentes criterios
- Gestión de disponibilidad de recursos
- Sistema de logging para seguimiento de operaciones

## Requisitos del Sistema
- Compilador C++ compatible con C++17 o superior
- CMake 3.10 o superior
- Sistema operativo: Windows/Linux/MacOS

## Instrucciones de Compilación

### Windows
1. **Compilación manual con MSYS2 (recomendado si tienes problemas con CMake):**
   - Abre la terminal `MSYS2 MinGW 64-bit`.
   - Navega a la carpeta del proyecto.
   - Ejecuta el siguiente comando:
     ```sh
     g++ -std=c++17 -Iinclude src/*.cpp -o sistema.exe
     ```
   - Esto generará el ejecutable `sistema.exe` en la carpeta del proyecto.

2. **Compilación con CMake (requiere tener MinGW o Visual Studio):**
   - Asegúrate de tener instalado un compilador C++ (como MinGW o Visual Studio Build Tools)
   - Abre una terminal en el directorio del proyecto
   - Ejecuta los siguientes comandos:
     ```sh
     mkdir build
     cd build
     cmake .. -G "MinGW Makefiles"
     mingw32-make
     ```
   - Si usas Visual Studio, abre la "Developer Command Prompt" y ejecuta:
     ```sh
     mkdir build
     cd build
     cmake ..
     cmake --build .
     ```

### Linux/MacOS
1. Abre una terminal en el directorio del proyecto
2. Ejecuta los siguientes comandos:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

## Estructura del Proyecto
```
.
├── include/             # Archivos de cabecera
│   ├── Audio.h         # Clase para recursos de audio
│   ├── Libro.h         # Clase para recursos de libros
│   ├── RecursoDigital.h # Clase base para recursos
│   ├── Servidor.h      # Clase para gestión del servidor
│   └── aed.h           # Definiciones generales
├── src/                # Archivos fuente
│   ├── Servidor.cpp    # Implementación del servidor
│   ├── SistemaCentral.cpp # Implementación del sistema central
│   └── main.cpp        # Punto de entrada del programa
├── build/              # Directorio de compilación
└── README.md           # Este archivo
```

## Uso del Sistema
1. Ejecuta el programa compilado:
   - Windows: `sistema.exe` o `build/sistema.exe`
   - Linux/MacOS: `./build/sistema`

2. El sistema mostrará un menú con las siguientes opciones:
   - Registro de usuario
   - Inicio de sesión
   - Gestión de recursos
   - Búsqueda de recursos
   - Préstamos y devoluciones
   - Salir del sistema

## Archivos de Datos
El sistema utiliza los siguientes archivos para almacenar datos:
- `usuarios.txt`: Almacena la información de los usuarios registrados
- `recursos.txt`: Contiene el catálogo de recursos digitales
- `sistema.log`: Registra las operaciones del sistema

## Notas Adicionales
- El sistema mantiene un registro de todas las operaciones en el archivo `sistema.log`
- Los recursos pueden ser marcados como disponibles o no disponibles
- El sistema verifica la disponibilidad antes de permitir préstamos
- Se pueden realizar búsquedas por diferentes criterios (título, autor, etc.)

## Contribución
Si deseas contribuir al proyecto:
1. Haz un fork del repositorio
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

## Licencia
Este proyecto está bajo la Licencia MIT. Ver el archivo `LICENSE` para más detalles. 