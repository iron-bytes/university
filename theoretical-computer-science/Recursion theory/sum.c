/**
 * Let k be a given number
 * Let g(x,y) be a computable (total) function
 * in two variables and h(x) a partially computable
 * function
 *
 * Let's have:
 * h(0) = k
 * h (t + 1) = g(t, h(t))
 *
 * Then we say that h is obtained from g by
 * primitive recursion.
 *
 * Unlike usual recursion in a programming language,
 * here we define, more formally, two functions: h and g
 *
 */

#include <stdio.h>
#define K 5

/// Computes K + t
/// We define:
/// h(0) = K
/// h(t+1) = g(t,h(t)) = h(t) + 1
int h (int t) {
    if(t == 0) {
        return K;
    }
    return g(t - 1, h(t - 1));
}

int g (int t, int x) { // g does not care about t.
    return x + 1;
}

int main(void) {
    printf("%d", h(4));
    return 0;
 }
