/* 
 * Video.h
 * 
 * Este archivo define la clase Video que hereda de RecursoDigital.
 * Representa un recurso digital de tipo video con su atributo específico (formato).
 * 
 * Aplica:
 * - Herencia: Hereda de RecursoDigital
 * - Polimorfismo: Implementa getTipo()
 * - Encapsulamiento: Atributos protegidos con getters/setters
 */

#ifndef VIDEO_H
#define VIDEO_H

#include "RecursoDigital.h"

class Video : public RecursoDigital {
private:
    string formato;

public:
    Video(const string& id, const string& titulo, const string& autor, 
          int anioPublicacion, const string& formato);
    
    // Getters y setters específicos
    string getFormato() const { return formato; }
    void setFormato(const string& formato) { this->formato = formato; }
    
    // Implementación del método virtual
    string getTipo() const override { return "Video"; }
};

#endif 