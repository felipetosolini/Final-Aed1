#include "../include/Libro.h"

Libro::Libro(const string& id, const string& titulo, const string& autor, 
             int anioPublicacion, const string& editorial)
    : RecursoDigital(id, titulo, autor, anioPublicacion), editorial(editorial) {} 