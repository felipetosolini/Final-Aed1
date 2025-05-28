#include "../include/Servidor.h"
#include <stdexcept>

Servidor::Servidor(const string& id) : id(id), activo(true) {}

void Servidor::agregarRecurso(shared_ptr<RecursoDigital> recurso) {
    if (!puedeAlmacenar(*recurso)) {
        throw runtime_error("Este servidor no puede almacenar este tipo de recurso");
    }
    recursos.push_back(recurso);
}

void Servidor::eliminarRecurso(const string& id) {
    auto it = find_if(recursos.begin(), recursos.end(),
        [&id](const shared_ptr<RecursoDigital>& r) { return r->getId() == id; });
    
    if (it != recursos.end()) {
        recursos.erase(it);
    } else {
        throw runtime_error("Recurso no encontrado");
    }
}

shared_ptr<RecursoDigital> Servidor::buscarRecurso(const string& id) const {
    auto it = find_if(recursos.begin(), recursos.end(),
        [&id](const shared_ptr<RecursoDigital>& r) { return r->getId() == id; });
    
    return (it != recursos.end()) ? *it : nullptr;
}

vector<shared_ptr<RecursoDigital>> Servidor::buscarPorAutor(const string& autor) const {
    vector<shared_ptr<RecursoDigital>> resultado;
    copy_if(recursos.begin(), recursos.end(), back_inserter(resultado),
        [&autor](const shared_ptr<RecursoDigital>& r) { return r->getAutor() == autor; });
    return resultado;
}

vector<shared_ptr<RecursoDigital>> Servidor::buscarPorAnio(int anio) const {
    vector<shared_ptr<RecursoDigital>> resultado;
    copy_if(recursos.begin(), recursos.end(), back_inserter(resultado),
        [&anio](const shared_ptr<RecursoDigital>& r) { return r->getAnioPublicacion() == anio; });
    return resultado;
} 