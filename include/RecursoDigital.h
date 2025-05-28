/* 
 * RecursoDigital.h
 * 
 * Este archivo define la clase base abstracta RecursoDigital que sirve como interfaz
 * común para todos los tipos de recursos digitales (libros, audios y videos).
 * 
 * Aplica:
 * - Herencia y polimorfismo: Clase base para la jerarquía de recursos
 * - Encapsulamiento: Atributos protegidos con getters/setters
 * - Constructores y destructores: Implementación de ambos
 */

#ifndef RECURSO_DIGITAL_H
#define RECURSO_DIGITAL_H

#include <string>
using namespace std;

class RecursoDigital {
protected:
    string id;
    string titulo;
    string autor;
    int anioPublicacion;

public:
    RecursoDigital(const string& id, const string& titulo, const string& autor, int anioPublicacion);
    virtual ~RecursoDigital() = default;

    // Getters
    string getId() const { return id; }
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getAnioPublicacion() const { return anioPublicacion; }

    // Setters
    void setTitulo(const string& titulo) { this->titulo = titulo; }
    void setAutor(const string& autor) { this->autor = autor; }
    void setAnioPublicacion(int anio) { this->anioPublicacion = anio; }

    // Método virtual puro para obtener el tipo de recurso
    virtual string getTipo() const = 0;
};

#endif 