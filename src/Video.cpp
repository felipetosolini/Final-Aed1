#include "../include/Video.h"

Video::Video(const string& id, const string& titulo, const string& autor, 
             int anioPublicacion, const string& formato)
    : RecursoDigital(id, titulo, autor, anioPublicacion), formato(formato) {} 