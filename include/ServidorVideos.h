/* 
 * ServidorVideos.h
 * 
 * Este archivo define la clase ServidorVideos que hereda de Servidor.
 * Representa un servidor especializado en almacenar recursos de tipo video.
 * 
 * Aplica:
 * - Herencia: Hereda de Servidor
 * - Polimorfismo: Implementa los métodos virtuales puros
 */

#ifndef SERVIDOR_VIDEOS_H
#define SERVIDOR_VIDEOS_H

#include "Servidor.h"
#include "Video.h"

class ServidorVideos : public Servidor {
public:
    ServidorVideos(const string& id);
    
    // Implementación de métodos virtuales
    bool puedeAlmacenar(const RecursoDigital& recurso) const override {
        return dynamic_cast<const Video*>(&recurso) != nullptr;
    }
    
    string getTipo() const override { return "Videos"; }
};

#endif 