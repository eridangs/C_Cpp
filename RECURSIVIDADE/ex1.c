#include <stdio.h>

void desc(int n);


int main(){
    int n = 10;

    desc(n);

    return 0;
}

void desc(int n){

    if (n == 0){
        return;
    }
    else {
        printf("%d\n",n);
        desc(n -1);
    }
}
