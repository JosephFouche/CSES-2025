/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints

1 \le n \le 10^6

Example
Input:
ATTCGGGA

Output:
3
*/ 
#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_len = 1000000;

    char *vector = malloc((max_len + 1) * sizeof(char)); // +1 para '\0'
    int repe = 1;
    int mayor = 1;

    if (vector == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        return 1;
    }

    // Leer cadena de hasta 1 millón de caracteres
    if (scanf("%1000000s", vector) != 1) {
        fprintf(stderr, "Error al leer la cadena\n");
        free(vector);
        return 1;
    }

    for (int i = 1; vector[i] != '\0'; i++) {
        if (vector[i] == vector[i - 1]) {
            repe++;
            if (repe > mayor) {
                mayor = repe;
            }
        } else {
            repe = 1;
        }
    }

    printf("%d\n", mayor);
    free(vector);
    return 0;
}

