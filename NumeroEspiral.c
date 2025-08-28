#include <stdio.h>

int main() {
    printf("Hola mundo!\n");
    
    int t;
    scanf("%d", &t);  // número de casos de prueba

    while(t--) {
        long long Y, X;
        scanf("%lld %lld", &Y, &X);

        long long L = (Y > X) ? Y : X;        // fila o columna más grande
        long long base = (L - 1) * (L - 1);   // área del cuadrado interior
        long long result;

        if(Y >= X) {
            // estamos en la fila L
            result = (Y % 2 == 1) ? (base + X) : (L * L - X + 1);
        } else {
            // estamos en la columna L
            result = (X % 2 == 0) ? (base + Y) : (L * L - Y + 1);
        }

        printf("%lld\n", result);
    }

    return 0;
}
