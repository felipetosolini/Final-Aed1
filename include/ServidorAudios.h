/* 
 * ServidorAudios.h
 * 
 * Este archivo define la clase ServidorAudios que hereda de Servidor.
 * Representa un servidor especializado en almacenar recursos de tipo audio.
 * 
 * Aplica:
 * - Herencia: Hereda de Servidor
 * - Polimorfismo: Implementa los métodos virtuales puros
 */

#ifndef SERVIDOR_AUDIOS_H
#define SERVIDOR_AUDIOS_H

#include "Servidor.h"
#include "Audio.h"

class ServidorAudios : public Servidor {
public:
    ServidorAudios(const string& id);
    
    // Implementación de métodos virtuales
    bool puedeAlmacenar(const RecursoDigital& recurso) const override {
        return dynamic_cast<const Audio*>(&recurso) != nullptr;
    }
    
    string getTipo() const override { return "Audios"; }
};

#endif 