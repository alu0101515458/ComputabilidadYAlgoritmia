#include <iostream>
#include "point_types.h"  // Asegúrate de incluir tu archivo de definiciones
#include "point_set.h"

int main() {
    CyA::point_vector points;

    // Leer puntos desde la entrada estándar
    std::cin >> points;

    // Crear un point_set con los puntos leídos
    point_set ps(points);

    // Calcular el árbol de expansión mínima y emitir el resultado
    ps.write_tree(std::cout);

    return 0;
}