/* 
 * Usuario.h
 * 
 * Este archivo define la clase base abstracta Usuario que servirá como interfaz
 * común para los diferentes tipos de usuarios del sistema.
 * 
 * Aplica:
 * - Herencia y polimorfismo: Clase base para la jerarquía de usuarios
 * - Encapsulamiento: Atributos protegidos con getters/setters
 * - Constructores y destructores: Implementación de ambos
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string id;
    string nombre;
    string password;

public:
    Usuario(const string& id, const string& nombre, const string& password);
    virtual ~Usuario() = default;

    // Getters
    string getId() const { return id; }
    string getNombre() const { return nombre; }
    string getPassword() const { return password; }

    // Setters
    void setNombre(const string& nombre) { this->nombre = nombre; }
    void setPassword(const string& password) { this->password = password; }

    // Métodos virtuales puros
    virtual bool puedeInsertar() const = 0;
    virtual bool puedeEliminar() const = 0;
    virtual bool puedeModificar() const = 0;
    virtual bool puedeConsultar() const = 0;
};

#endif 