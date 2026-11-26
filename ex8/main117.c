#include <stdio.h>

int add_Func(int a, int b) {
    return a + b;
}

int main() {
    int (*func_ptr)(int, int);
    func_ptr = &add_Func;
    printf("%d\n", func_ptr(1, 2));
    return 0;
}
