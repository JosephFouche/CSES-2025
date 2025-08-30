/*
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the minimum number of moves.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5
3 2 5 1 7

Output:
5

*/
#include <stdio.h>

int main() {
    int n;

    // Leer cantidad de elementos
    if (scanf("%d", &n) != 1) {
        printf("Error al leer n\n");
        return 1;
    }

    if (n < 1 || n > 200000) {
        printf("Fuera de rango\n");
        return 1;
    }

    int vector[n];
    long long totalCambios = 0;  // usar long long porque la suma puede ser grande

    // Leer elementos
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &vector[i]) != 1) {
            printf("Error al leer vector[%d]\n", i);
            return 1;
        }
    }

    // Transformar a secuencia no decreciente
    for (int i = 1; i < n; i++) {
        if (vector[i] < vector[i - 1]) {
            totalCambios += (long long)(vector[i - 1] - vector[i]);
            vector[i] = vector[i - 1];
        }
    }

    // Mostrar el total de cambios
    printf("%lld\n", totalCambios);

    return 0;
}
