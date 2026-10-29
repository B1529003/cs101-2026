#include <stdio.h>
int f(int n){
    if(n==1) return 1;
    return n*f(n-1);
}

int main()
{
    int n=5;
    int m=f(n);
    printf("f %d = %d\n",n,m);
    return 0;
}
