#include <stdio.h>

int fact (int n);
int g (int t, int x);

int main (void) {
    printf("%d", fact(4));
    return 0;
}

int fact (int n) { // "fact" is "h" in the definition
    if (n == 0)
        return 1;
    return n * fact(n - 1); // this statement is "g" in the definition. Unlike "sum.c", this function does care about the current value of "t"
    // return g(n - 1, fact(n - 1));
}

int g (int t, int x) { // If we want to abide to the definition
    ++t;
    return t * x;
}
