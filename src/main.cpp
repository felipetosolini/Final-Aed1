/* 
 * main.cpp
 * 
 * Este archivo contiene la función main y el menú principal del sistema.
 * Implementa la interfaz de usuario y la lógica de ejecución del programa.
 * 
 * Aplica:
 * - Manejo de excepciones: Try-catch para errores
 * - Persistencia: Carga y guardado de datos
 * - Interfaz de usuario: Menú interactivo
 */

#include <iostream>
#include <string>
#include <memory>
#include "../include/SistemaCentral.h"
#include "../include/Administrador.h"
#include "../include/Alumno.h"
#include "../include/Libro.h"
#include "../include/Audio.h"
#include "../include/Video.h"
using namespace std;

void mostrarMenuPrincipal() {
    cout << "\n=== SISTEMA DE GESTIÓN DE COLECCIONES DIGITALES ===\n";
    cout << "1. Iniciar sesión\n";
    cout << "2. Registrar nuevo usuario\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuUsuario(shared_ptr<Usuario> usuario) {
    cout << "\n=== MENÚ DE USUARIO ===\n";
    cout << "Usuario: " << usuario->getNombre() << "\n";
    cout << "1. Buscar por autor\n";
    cout << "2. Buscar por año\n";
    
    if (usuario->puedeInsertar()) {
        cout << "3. Insertar recurso\n";
    }
    if (usuario->puedeEliminar()) {
        cout << "4. Eliminar recurso\n";
    }
    if (usuario->puedeModificar()) {
        cout << "5. Modificar recurso\n";
    }
    
    cout << "6. Cerrar sesión\n";
    cout << "Seleccione una opción: ";
}

shared_ptr<RecursoDigital> crearRecurso() {
    string tipo, id, titulo, autor;
    int anio;
    
    cout << "Tipo de recurso (libro/audio/video): ";
    cin >> tipo;
    
    cout << "ID: ";
    cin >> id;
    
    cout << "Título: ";
    cin.ignore();
    getline(cin, titulo);
    
    cout << "Autor: ";
    getline(cin, autor);
    
    cout << "Año: ";
    cin >> anio;
    
    if (tipo == "libro") {
        string editorial;
        cout << "Editorial: ";
        cin.ignore();
        getline(cin, editorial);
        return make_shared<Libro>(id, titulo, autor, anio, editorial);
    }
    else if (tipo == "audio") {
        int duracion;
        cout << "Duración (segundos): ";
        cin >> duracion;
        return make_shared<Audio>(id, titulo, autor, anio, duracion);
    }
    else if (tipo == "video") {
        string formato;
        cout << "Formato: ";
        cin.ignore();
        getline(cin, formato);
        return make_shared<Video>(id, titulo, autor, anio, formato);
    }
    
    return nullptr;
}

int main() {
    SistemaCentral sistema;
    shared_ptr<Usuario> usuarioActual = nullptr;
    
    while (true) {
        if (!usuarioActual) {
            mostrarMenuPrincipal();
            int opcion;
            cin >> opcion;
            
            switch (opcion) {
                case 1: {
                    string id, password;
                    cout << "ID: ";
                    cin >> id;
                    cout << "Password: ";
                    cin >> password;
                    
                    if (sistema.autenticarUsuario(id, password)) {
                        usuarioActual = sistema.obtenerUsuario(id);
                        cout << "Bienvenido, " << usuarioActual->getNombre() << "!\n";
                    } else {
                        cout << "Error de autenticación\n";
                    }
                    break;
                }
                case 2: {
                    string id, nombre, password, tipo;
                    cout << "ID: ";
                    cin >> id;
                    cout << "Nombre: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Password: ";
                    cin >> password;
                    cout << "Tipo (admin/alumno): ";
                    cin >> tipo;
                    
                    shared_ptr<Usuario> nuevoUsuario;
                    if (tipo == "admin") {
                        nuevoUsuario = make_shared<Administrador>(id, nombre, password);
                    } else {
                        nuevoUsuario = make_shared<Alumno>(id, nombre, password);
                    }
                    
                    if (sistema.registrarUsuario(nuevoUsuario)) {
                        cout << "Usuario registrado exitosamente\n";
                    } else {
                        cout << "Error al registrar usuario\n";
                    }
                    break;
                }
                case 3:
                    return 0;
                default:
                    cout << "Opción inválida\n";
            }
        } else {
            mostrarMenuUsuario(usuarioActual);
            int opcion;
            cin >> opcion;
            
            switch (opcion) {
                case 1: {
                    string autor;
                    cout << "Autor: ";
                    cin.ignore();
                    getline(cin, autor);
                    auto resultados = sistema.buscarPorAutor(autor);
                    cout << "Resultados encontrados: " << resultados.size() << "\n";
                    break;
                }
                case 2: {
                    int anio;
                    cout << "Año: ";
                    cin >> anio;
                    auto resultados = sistema.buscarPorAnio(anio);
                    cout << "Resultados encontrados: " << resultados.size() << "\n";
                    break;
                }
                case 3:
                    if (usuarioActual->puedeInsertar()) {
                        auto recurso = crearRecurso();
                        if (recurso && sistema.insertarRecurso(recurso, usuarioActual->getId())) {
                            cout << "Recurso insertado exitosamente\n";
                        } else {
                            cout << "Error al insertar recurso\n";
                        }
                    }
                    break;
                case 4:
                    if (usuarioActual->puedeEliminar()) {
                        string id;
                        cout << "ID del recurso: ";
                        cin >> id;
                        if (sistema.eliminarRecurso(id, usuarioActual->getId())) {
                            cout << "Recurso eliminado exitosamente\n";
                        } else {
                            cout << "Error al eliminar recurso\n";
                        }
                    }
                    break;
                case 5:
                    if (usuarioActual->puedeModificar()) {
                        string id;
                        cout << "ID del recurso: ";
                        cin >> id;
                        if (sistema.modificarRecurso(id, usuarioActual->getId())) {
                            cout << "Recurso modificado exitosamente\n";
                        } else {
                            cout << "Error al modificar recurso\n";
                        }
                    }
                    break;
                case 6:
                    usuarioActual = nullptr;
                    cout << "Sesión cerrada\n";
                    break;
                default:
                    cout << "Opción inválida\n";
            }
        }
    }
    
    return 0;
} 