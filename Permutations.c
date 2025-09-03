
/*
A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example 1
Input:
5

Output:
4 2 5 3 1
Example 2
Input:
3

Output:
NO SOLUTION
*/
# include<stdio.h>
int main(){

    int n;
    

    if(scanf("%d", &n)!=1){
        printf("Error al leer numero\n ");
        return 1;
    }

    //contraint mayor o igual a uno menor o igual a 1000000
    if(n<1 || n > 1000000){
        printf("Fuera de rango\n ");
        return 1;
    }
    /**So the suggestion:

If 
n=1
n=1, print 1.

If 
n=2‘or‘3
n=2‘or‘3, print "No solution".

Otherwise, print evens then odds. */

if(n==1){
    printf("1\n");
}else if (n==2 || n==3){
    printf("NO SOLUTION");

}else{
    //primeros los numeros pares
    for(int i =2; i<=n; i= i+2){
        printf("%d ",i);
    }
    //ahora impares
    for(int i=1; i<=n; i = i+2){
        printf("%d ",i);
    }
    printf("\n");
}
return 0;
}
