#include "../include/SistemaCentral.h"
#include <stdexcept>
#include <ctime>

SistemaCentral::SistemaCentral() {
    logFile.open("sistema.log", ios::app);
    inicializarServidores();
    cargarEstado();
}

SistemaCentral::~SistemaCentral() {
    guardarEstado();
    if (logFile.is_open()) {
        logFile.close();
    }
}

void SistemaCentral::inicializarServidores() {
    servidores.push_back(make_shared<ServidorLibros>("S1"));
    servidores.push_back(make_shared<ServidorAudios>("S2"));
    servidores.push_back(make_shared<ServidorVideos>("S3"));
}

bool SistemaCentral::registrarUsuario(shared_ptr<Usuario> usuario) {
    if (usuarios.existe(usuario->getId())) {
        return false;
    }
    usuarios.insertar(usuario->getId(), usuario);
    registrarOperacion("Registro de usuario: " + usuario->getId());
    return true;
}

bool SistemaCentral::autenticarUsuario(const string& id, const string& password) {
    try {
        auto usuario = usuarios.obtener(id);
        if (usuario->getPassword() == password) {
            registrarOperacion("Autenticación exitosa: " + id);
            return true;
        }
    } catch (const invalid_argument&) {
        // Usuario no encontrado
    }
    registrarOperacion("Autenticación fallida: " + id);
    return false;
}

shared_ptr<Usuario> SistemaCentral::obtenerUsuario(const string& id) {
    try {
        return usuarios.obtener(id);
    } catch (const invalid_argument&) {
        return nullptr;
    }
}

vector<shared_ptr<Servidor>> SistemaCentral::obtenerServidoresActivos() const {
    vector<shared_ptr<Servidor>> activos;
    copy_if(servidores.begin(), servidores.end(), back_inserter(activos),
        [](const shared_ptr<Servidor>& s) { return s->estaActivo(); });
    return activos;
}

void SistemaCentral::activarServidor(const string& id) {
    auto it = find_if(servidores.begin(), servidores.end(),
        [&id](const shared_ptr<Servidor>& s) { return s->getId() == id; });
    
    if (it != servidores.end()) {
        (*it)->setActivo(true);
        registrarOperacion("Servidor activado: " + id);
    }
}

void SistemaCentral::desactivarServidor(const string& id) {
    auto it = find_if(servidores.begin(), servidores.end(),
        [&id](const shared_ptr<Servidor>& s) { return s->getId() == id; });
    
    if (it != servidores.end()) {
        (*it)->setActivo(false);
        registrarOperacion("Servidor desactivado: " + id);
    }
}

bool SistemaCentral::insertarRecurso(shared_ptr<RecursoDigital> recurso, const string& idUsuario) {
    auto usuario = obtenerUsuario(idUsuario);
    if (!usuario || !usuario->puedeInsertar()) {
        return false;
    }

    for (auto& servidor : servidores) {
        if (servidor->estaActivo() && servidor->puedeAlmacenar(*recurso)) {
            servidor->agregarRecurso(recurso);
            registrarOperacion("Recurso insertado: " + recurso->getId() + " por " + idUsuario);
            return true;
        }
    }
    return false;
}

bool SistemaCentral::eliminarRecurso(const string& idRecurso, const string& idUsuario) {
    auto usuario = obtenerUsuario(idUsuario);
    if (!usuario || !usuario->puedeEliminar()) {
        return false;
    }

    for (auto& servidor : servidores) {
        if (servidor->estaActivo()) {
            try {
                servidor->eliminarRecurso(idRecurso);
                registrarOperacion("Recurso eliminado: " + idRecurso + " por " + idUsuario);
                return true;
            } catch (const runtime_error&) {
                // Recurso no encontrado en este servidor
            }
        }
    }
    return false;
}

bool SistemaCentral::modificarRecurso(const string& idRecurso, const string& idUsuario) {
    auto usuario = obtenerUsuario(idUsuario);
    if (!usuario || !usuario->puedeModificar()) {
        return false;
    }

    for (auto& servidor : servidores) {
        if (servidor->estaActivo()) {
            auto recurso = servidor->buscarRecurso(idRecurso);
            if (recurso) {
                registrarOperacion("Recurso modificado: " + idRecurso + " por " + idUsuario);
                return true;
            }
        }
    }
    return false;
}

vector<shared_ptr<RecursoDigital>> SistemaCentral::buscarPorAutor(const string& autor) {
    vector<shared_ptr<RecursoDigital>> resultados;
    for (auto& servidor : servidores) {
        if (servidor->estaActivo()) {
            auto recursos = servidor->buscarPorAutor(autor);
            resultados.insert(resultados.end(), recursos.begin(), recursos.end());
        }
    }
    registrarOperacion("Búsqueda por autor: " + autor);
    return resultados;
}

vector<shared_ptr<RecursoDigital>> SistemaCentral::buscarPorAnio(int anio) {
    vector<shared_ptr<RecursoDigital>> resultados;
    for (auto& servidor : servidores) {
        if (servidor->estaActivo()) {
            auto recursos = servidor->buscarPorAnio(anio);
            resultados.insert(resultados.end(), recursos.begin(), recursos.end());
        }
    }
    registrarOperacion("Búsqueda por año: " + to_string(anio));
    return resultados;
}

void SistemaCentral::registrarOperacion(const string& operacion) {
    if (logFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt)-1] = '\0'; // Eliminar el salto de línea
        logFile << "[" << dt << "] " << operacion << endl;
    }
}

void SistemaCentral::guardarEstado() {
    guardarUsuarios();
    guardarRecursos();
}

void SistemaCentral::cargarEstado() {
    cargarUsuarios();
    cargarRecursos();
}

void SistemaCentral::guardarUsuarios() {
    ofstream archivo("usuarios.txt");
    if (archivo.is_open()) {
        // Implementar guardado de usuarios
        archivo.close();
    }
}

void SistemaCentral::cargarUsuarios() {
    ifstream archivo("usuarios.txt");
    if (archivo.is_open()) {
        // Implementar carga de usuarios
        archivo.close();
    }
}

void SistemaCentral::guardarRecursos() {
    ofstream archivo("recursos.txt");
    if (archivo.is_open()) {
        // Implementar guardado de recursos
        archivo.close();
    }
}

void SistemaCentral::cargarRecursos() {
    ifstream archivo("recursos.txt");
    if (archivo.is_open()) {
        // Implementar carga de recursos
        archivo.close();
    }
} 