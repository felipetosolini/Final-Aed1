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
// ... existing code ... 