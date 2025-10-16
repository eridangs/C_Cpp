#include <stdio.h>
#include <stdlib.h>

int prod(int *, int);

int main(){
    int n = 11, i, *v;

    v = (int *) malloc(n * sizeof(int));

    for (i=0;i<n;i++){
        v[i] = i+1;
    }

    n = prod(v, n);
    printf("O valor do produto de um vetor de 1 a 11 elementos é %d\n", n);

    free(v);
    return 0;
}

int prod(int *v, int n){
    if (n == 1) return n;
    else{
        return prod(v,n-1) * v[n-1];
    }
}