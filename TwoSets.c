/*
Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
Constraints

1 \le n \le 10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO
*/
#include<stdio.h>
#include<stdlib.h>

int main(){

    long long n;
    scanf("%lld",&n);

    //calcular suma total: n*(n+1)2

    long long total_sum =n*(n+1)2;

    //si suma es impar, particion imposible
    if(total_sum % 2 != 0){
        pritf("NO\n");
        return 0;
    }

    long long target = total_sum/2;
    long long *set1 =(long long *)malloc(n * sizeof(long long));
    int set1_size = 0;//numeros mas grandes
    long long suma_actual =0;

    //seleccion avara: agarra los mas numeros mas grandes
    //que no superen el objetivo

    for(long long i=n;i>=1;i--){//agregar numero que no excedan S/2
        if(suma_actual + i <= target){

            suma_actual += i;
            set1[set1_size]=i;

        }
    }

    //si no se puede alcanzar la suma objetivo, particion imposible
    if(suma_actual!=target){
        printf("No\n");
        free(set1);
        return 0;

    }
    //crear set2 (numeros que sobran)

    long long *set2 = (long long *)malloc(n * sizeof(long long));
    int set2_size =0;
    char *used = (char *)calloc(n+1,sizeof(char));

    for(int i=0; i<set1_size;i++)
    {
        used[set1[i]]=1;

    }
    for(long long i=1; i<=n;i++){
        if(!used[i]){
            set2[set2_size]=i;
        }
    }

    //resultado de salida
    printf("YES\n");
    printf("%d\n", set1_size);
    for (int i = set1_size - 1; i >= 0; i--) {
        printf("%lld ", set1[i]);
    }
    printf("\n");
    printf("%d\n", set2_size);
    for (int i = 0; i < set2_size; i++) {
        printf("%lld ", set2[i]);
    }
    printf("\n");

    //liberar memoria
    free(set1);
    free(set2);
    free(used);
    
    return 0;
}
