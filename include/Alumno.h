/* 
 * Alumno.h
 * 
 * Este archivo define la clase Alumno que hereda de Usuario.
 * Representa un usuario con permisos limitados (solo consulta).
 * 
 * Aplica:
 * - Herencia: Hereda de Usuario
 * - Polimorfismo: Implementa los métodos virtuales puros
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Usuario.h"

class Alumno : public Usuario {
public:
    Alumno(const string& id, const string& nombre, const string& password);
    
    // Implementación de métodos virtuales
    bool puedeInsertar() const override { return false; }
    bool puedeEliminar() const override { return false; }
    bool puedeModificar() const override { return false; }
    bool puedeConsultar() const override { return true; }
};

#endif 