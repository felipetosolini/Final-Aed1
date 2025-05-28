#include "../include/Audio.h"

Audio::Audio(const string& id, const string& titulo, const string& autor, 
             int anioPublicacion, int duracion)
    : RecursoDigital(id, titulo, autor, anioPublicacion), duracion(duracion) {} 