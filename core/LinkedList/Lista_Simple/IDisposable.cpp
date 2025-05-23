//
// Created by 72358 on 23/05/2025.
//

/**
 * Interfaz IDisposable que define el método dispose para liberar recursos.
 */
struct IDisposable {
    virtual void dispose() = 0; // Método para liberar recursos
    virtual ~IDisposable() = default; // Destructor virtual por defecto
};