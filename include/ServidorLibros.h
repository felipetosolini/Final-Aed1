/* 
 * ServidorLibros.h
 * 
 * Este archivo define la clase ServidorLibros que hereda de Servidor.
 * Representa un servidor especializado en almacenar recursos de tipo libro.
 * 
 * Aplica:
 * - Herencia: Hereda de Servidor
 * - Polimorfismo: Implementa los métodos virtuales puros
 */

#ifndef SERVIDOR_LIBROS_H
#define SERVIDOR_LIBROS_H

#include "Servidor.h"
#include "Libro.h"

class ServidorLibros : public Servidor {
public:
    ServidorLibros(const string& id);
    
    // Implementación de métodos virtuales
    bool puedeAlmacenar(const RecursoDigital& recurso) const override {
        return dynamic_cast<const Libro*>(&recurso) != nullptr;
    }
    
    string getTipo() const override { return "Libros"; }
};

#endif 