/* 
 * Libro.h
 * 
 * Este archivo define la clase Libro que hereda de RecursoDigital.
 * Representa un recurso digital de tipo libro con su atributo específico (editorial).
 * 
 * Aplica:
 * - Herencia: Hereda de RecursoDigital
 * - Polimorfismo: Implementa getTipo()
 * - Encapsulamiento: Atributos protegidos con getters/setters
 */

#ifndef LIBRO_H
#define LIBRO_H

#include "RecursoDigital.h"

class Libro : public RecursoDigital {
private:
    string editorial;

public:
    Libro(const string& id, const string& titulo, const string& autor, 
          int anioPublicacion, const string& editorial);
    
    // Getters y setters específicos
    string getEditorial() const { return editorial; }
    void setEditorial(const string& editorial) { this->editorial = editorial; }
    
    // Implementación del método virtual
    string getTipo() const override { return "Libro"; }
};

#endif 