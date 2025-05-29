/* 
 * Servidor.h
 * 
 * Este archivo define la clase base Servidor que servirá como interfaz
 * comun para los diferentes tipos de servidores del sistema.
 * 
 * Aplica:
 * - Herencia y polimorfismo: Clase base para la jerarquía de servidores
 * - Encapsulamiento: Atributos protegidos
 * - Constructores y destructores: Implementación de ambos
 * - Manejo de excepciones: Uso de excepciones para errores
 */

#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include <memory>
#include "RecursoDigital.h"
using namespace std;

class Servidor {
protected:
    string id;
    bool activo;
    vector<shared_ptr<RecursoDigital>> recursos;

public:
    Servidor(const string& id);
    virtual ~Servidor() = default;

    // Getters
    string getId() const { return id; }
    bool estaActivo() const { return activo; }
    const vector<shared_ptr<RecursoDigital>>& getRecursos() const { return recursos; }

    // Setters
    void setActivo(bool estado) { activo = estado; }

    // Métodos virtuales puros
    virtual bool puedeAlmacenar(const RecursoDigital& recurso) const = 0;
    virtual string getTipo() const = 0;

    // Métodos comunes
    void agregarRecurso(shared_ptr<RecursoDigital> recurso);
    void eliminarRecurso(const string& id);
    shared_ptr<RecursoDigital> buscarRecurso(const string& id) const;
    vector<shared_ptr<RecursoDigital>> buscarPorAutor(const string& autor) const;
    vector<shared_ptr<RecursoDigital>> buscarPorAnio(int anio) const;
};

#endif 