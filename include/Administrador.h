/* 
 * Administrador.h
 * 
 * Este archivo define la clase Administrador que hereda de Usuario.
 * Representa un usuario con permisos completos sobre el sistema.
 * 
 * Aplica:
 * - Herencia: Hereda de Usuario
 * - Polimorfismo: Implementa los métodos virtuales puros
 */

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"

class Administrador : public Usuario {
public:
    Administrador(const string& id, const string& nombre, const string& password);
    
    // Implementación de métodos virtuales
    bool puedeInsertar() const override { return true; }
    bool puedeEliminar() const override { return true; }
    bool puedeModificar() const override { return true; }
    bool puedeConsultar() const override { return true; }
};

#endif 