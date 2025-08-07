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
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int n;
    int repe = 1;
    int mayor = 1;

    if(scanf("%d",&n)!=1){
        fprintf(stderr, "Error al leer el numero\n");
        return 1;
    }

    char DNA[]={'A','C','G','T'};

    //crear arreglo de caracteres
    char* vector = malloc(n * sizeof(char));
    if(vector == NULL){
        printf("Error");
        return 1;
    }
    //inicializar semilla para nros aleatorios
    srand(time(NULL));
    //llenar vector con caracteres aleatorios
    for(int i=0; i<n;i++){
        int indice = rand() % 4;//nro aleatorio entre 0 y 3
        vector[i]= DNA[indice];
    }
   
    //mostrar vector
    printf("Vector generado: ");
    for(int i=0; i<n; i++){
        printf("%c ",vector[i]);
        if(vector[i]==vector[i-1]){//si vector actual es identico al anterior repe +1
            repe++;

            if(repe > mayor){//si repe es mayor a 1, tenes un consecutivo
                mayor = repe;
            }
        
        }else{//si caracter no es consecutivo, repe vuelve a valor inicial
                repe = 1;
            }
        
    }
    printf("\n");
    printf("Mayor cantidad de repeticiones: %d\n", mayor);
    //liberar memoria
    free(vector);

    return 0;



}