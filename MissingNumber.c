
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int n;
    
    
    if (scanf("%d", &n) != 1) {
    // Manejo de error, por ejemplo:
    fprintf(stderr, "Error al leer el número\n");
    return 1;
}
// Cast a long long antes de multiplicar
    long long sumatoria = ((long long)n * (n + 1)) / 2;
 long long suma=0;
 int  num;   

    
    for(int i =0; i<n-1; i++){
        if(scanf("%d", &num)!=1){
            return 1;
        }
        suma += num;
    }
   

printf("%lld", sumatoria-suma);
    

return 0;
}

