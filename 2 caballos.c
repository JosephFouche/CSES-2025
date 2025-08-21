
#include <stdio.h>
int main(){
    long long n;
    scanf("%lld", &n);

    printf("0\n");

    for (long long i = 2; i <= n; i++) {
        long long result = (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1));
        printf("%lld\n", result);}

        return 0;
}