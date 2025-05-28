/* 
 * Audio.h
 * 
 * Este archivo define la clase Audio que hereda de RecursoDigital.
 * Representa un recurso digital de tipo audio con su atributo específico (duración).
 * 
 * Aplica:
 * - Herencia: Hereda de RecursoDigital
 * - Polimorfismo: Implementa getTipo()
 * - Encapsulamiento: Atributos protegidos con getters/setters
 */

#ifndef AUDIO_H
#define AUDIO_H

#include "RecursoDigital.h"

class Audio : public RecursoDigital {
private:
    int duracion; // duración en segundos

public:
    Audio(const string& id, const string& titulo, const string& autor, 
          int anioPublicacion, int duracion);
    
    // Getters y setters específicos
    int getDuracion() const { return duracion; }
    void setDuracion(int duracion) { this->duracion = duracion; }
    
    // Implementación del método virtual
    string getTipo() const override { return "Audio"; }
};

#endif 