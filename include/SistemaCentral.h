/* 
 * SistemaCentral.h
 * 
 * Este archivo define la clase SistemaCentral que coordina todo el sistema.
 * Gestiona usuarios, servidores y operaciones del sistema.
 * 
 * Aplica:
 * - Encapsulamiento: Atributos privados con métodos públicos
 * - Manejo de excepciones: Uso de excepciones para errores
 * - Persistencia: Guardado y carga de datos
 * - Tabla Hash: Para gestión de usuarios
 */

#ifndef SISTEMA_CENTRAL_H
#define SISTEMA_CENTRAL_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "../include/aed.h"
#include "Usuario.h"
#include "Servidor.h"
#include "ServidorLibros.h"
#include "ServidorAudios.h"
#include "ServidorVideos.h"
using namespace std;

class SistemaCentral {
private:
    TablaHash<string, shared_ptr<Usuario>> usuarios;
    vector<shared_ptr<Servidor>> servidores;
    ofstream logFile;
    
    // Métodos privados
    void inicializarServidores();
    void cargarUsuarios();
    void guardarUsuarios();
    void cargarRecursos();
    void guardarRecursos();
    void registrarOperacion(const string& operacion);

public:
    SistemaCentral();
    ~SistemaCentral();

    // Gestión de usuarios
    bool registrarUsuario(shared_ptr<Usuario> usuario);
    bool autenticarUsuario(const string& id, const string& password);
    shared_ptr<Usuario> obtenerUsuario(const string& id);

    // Gestión de servidores
    vector<shared_ptr<Servidor>> obtenerServidoresActivos() const;
    void activarServidor(const string& id);
    void desactivarServidor(const string& id);

    // Operaciones con recursos
    bool insertarRecurso(shared_ptr<RecursoDigital> recurso, const string& idUsuario);
    bool eliminarRecurso(const string& idRecurso, const string& idUsuario);
    bool modificarRecurso(const string& idRecurso, const string& idUsuario);
    vector<shared_ptr<RecursoDigital>> buscarPorAutor(const string& autor);
    vector<shared_ptr<RecursoDigital>> buscarPorAnio(int anio);

    // Persistencia
    void guardarEstado();
    void cargarEstado();
};

#endif 