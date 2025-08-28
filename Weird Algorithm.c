/*
Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
$$ 3 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1$$
Your task is to simulate the execution of the algorithm for a given value of n.
Input
The only input line contains an integer n.
Output
Print a line that contains all values of n during the algorithm.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
3 10 5 16 8 4 2 1

INICIAR programa

DECLARAR entero n
DECLARAR entero p = 0              // contador de elementos en la secuencia
DECLARAR puntero a entero misNumeros = NULL  // array dinámico

// ───── PEDIR UN NÚMERO AL USUARIO ─────
REPETIR
    MOSTRAR "Mete un numerico entero entre 1 y 1.000.000: "
    LEER valor en n

    SI n < 1 O n > 1000000 ENTONCES
        MOSTRAR "No está dentro del rango correcto"
FIN REPETIR MIENTRAS (n < 1 O n > 1000000)

// ───── INICIAR SECUENCIA DE COLLATZ ─────
MOSTRAR "Generando secuencia para n..."

MIENTRAS n ≠ 1 HACER
    INCREMENTAR p
    INTENTAR reasignar memoria a misNumeros para p elementos (cada uno del tamaño de un entero)

    SI la reasignación falla ENTONCES
        MOSTRAR "No se pudo asignar memoria para la secuencia."
        SI p > 0 ENTONCES
            LIBERAR memoria de misNumeros
        TERMINAR programa con error

    GUARDAR n en misNumeros[p - 1]

    SI n es par ENTONCES
        n = n / 2
    SINO
        n = (n * 3) + 1
FIN MIENTRAS

// ───── AGREGAR EL ÚLTIMO NÚMERO (1) ─────
INCREMENTAR p
REASIGNAR memoria a misNumeros para p elementos

SI la reasignación falla ENTONCES
    MOSTRAR "No se pudo asignar memoria"
    TERMINAR programa con error

GUARDAR 1 en misNumeros[p - 1]

// ───── MOSTRAR LA SECUENCIA ─────
MOSTRAR "Lista de secuencia"
PARA i desde 0 hasta p - 1 HACER
    MOSTRAR misNumeros[i]
    SI i < p - 1 ENTONCES
        MOSTRAR " -> "
FIN PARA
MOSTRAR salto de línea

// ───── LIMPIAR MEMORIA ─────
LIBERAR memoria de misNumeros
ASIGNAR NULL a misNumeros

TERMINAR programa





 */
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
     int p = 0;//contador de elementos
    int  *misNumeros= NULL;
   
    do{
        printf("Mete un numerico entero entre 1 y 1.000.000: ");
        scanf("%d",&n);

        if(n<1 || n > 1000000){
            printf("No esta dentro del rango correcto");
        }


    }while(n<1||n>1000000);
    //printf("Tu valor: %d\n", n);
    printf("Generando secuencia para %d...\n",n);

    //continuar mientras no sea 1

    while(n !=1){
        /*
        misNumeros = (int *)realloc(misNumeros, p * sizeof(int));

Esta línea hace realocación de memoria dinámica, es decir:

    Si p = 1, se reserva memoria para 1 entero.

    Si p = 2, se expande el array a 2 enteros, y así sucesivamente.

👉 realloc toma el puntero original (misNumeros) y:

    Intenta expandir la memoria existente si hay espacio.

    O la mueve a una nueva posición con más espacio si no puede expandir.
        */ 
        p++;
        //reasignar memoria para elemento extra en array
        //realloc intenta expandir la memo existente o moverla si no hay espacio
        misNumeros = (int *)realloc(misNumeros,p*sizeof(int));
        //Verificar si asignacion de memoria fue exitosa
        if(misNumeros == NULL){
            printf("No se pudo asignar memoria para la secuencia.\n");
            //libera cualquier memoria ya asignada
            if(p>0) free(misNumeros);
            return 1;
        }
        //Guardar el numero actual en la nueva posicion
        misNumeros[p-1]=n;

        //aplicar logica
        if(n%2==0){
            n = n/2;
        }else{
            n = (n*3)+1;
        }
    }
    //agregar el ultimo 1 a la secuencia
    p++;
    misNumeros = (int *)realloc(misNumeros,p * sizeof(int));
    if(misNumeros == NULL){
        printf("no se pudo asignar memoria");
        return 1;

    }
    misNumeros[p-1]=1;

    //imprimir listas
    printf("Lista de secuencia\n");
    for(int i =0; i< p; i++){
        printf("%d",misNumeros[i]);
        if(i<p-1){
            printf(" ->");
        }
    }
    printf("\n");

    //liberar memoria asignada
    free(misNumeros);
    misNumeros = NULL;
// misNumeros[p]=n;
  
//    for(int i=0; i<p; i++){

//     if(n%2==0){
        
//         n = n/2;
//         misNumeros[p]=n;

//     }else{
//         n = (n*3)+1;
//         misNumeros[p]=n;

//     }
//     printf("Lista de numeros:  %d\n",i, misNumeros[i]);
//    }
   

    return 0;
}
