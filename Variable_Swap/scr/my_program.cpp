#include <iostream>
using namespace std;

// Función que intercambia valores usando punteros
void swapCorrecto(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Función que intenta intercambiar (pero falla, pasa por valor)
void swapIncorrecto(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;

    cout << "Valores iniciales:\n";
    cout << "a = " << a << " (direccion: " << &a << ")\n";
    cout << "b = " << b << " (direccion: " << &b << ")\n\n";

    // Incorrecto (no funciona)
    cout << ">>> Intento de swapIncorrecto(a, b)\n";
    swapIncorrecto(a, b);
    cout << "a = " << a << ", b = " << b << " (sin cambios)\n\n";

    // Correcto (funciona con punteros)
    cout << ">>> Llamando a swapCorrecto(&a, &b)\n";
    swapCorrecto(&a, &b);
    cout << "a = " << a << ", b = " << b << " valores finales\n\n";

    cout << "Direcciones finales:\n";
    cout << "a -> " << &a << "\n";
    cout << "b -> " << &b << "\n";

    return 0;
}
