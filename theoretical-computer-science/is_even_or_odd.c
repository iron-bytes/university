/**
 *  Assignment:
 *  Write a S-Program (here implemented, for simplicity, by a program in the C language)
 *  that computes f(x) = 0 if x odd, f(x) = 1 if x is even.
 *  Do not alter x (although we are in a C program where variables are passed by value,
 *  we have to suppose we are in a S-program).
 *  Note: You may use the multiplicative, additive, identity macros. You may NOT use
 *  other kind of macros.
 */

#include <stdio.h>
#include "test-suite.c"

/// Uses the identity macro
int is_even (int x);

/// Does not use any macro
int is_even_no_macro (int x);

int main () {
    int x = 0;
    int y = 0;

    x = 2;
    y = is_even(x);
    test(y, x%2 == 1? 0 : 1, "is_even");

    x = 3;
    y = is_even(x);
    test(y, x%2 == 1? 0 : 1, "is_even");

    x = 1;
    y = is_even(x);
    test(y, x%2 == 1? 0 : 1, "is_even");

    x = 0;
    y = is_even(x);
    test(y, x%2 == 1? 0 : 1, "is_even");
    return 0;
}

/// Uses the identity macro
/// The idea is to subtract 2 until either 0 or 1 is
/// reached
int is_even (int x) { // This program alters x, but since we are allowing the identity macro to be used here, it is trivial to add another Z variable to assign the value of X to.
    int y = 0;
    int z1 = 0;

    C:
        if (x != 0)
            goto A;
        goto EVEN;

    A:
        // We have to check if it's odd
        z1 = x; // Identity macro
        z1--;
        if (z1 != 0)
            goto B;
        goto ODD;

    B:
        x--;
        x--;
        goto C;

    EVEN:
        y = 1; // Identity macro
        return y; // return should be translated into a "GOTO EXIT" statement in a S-program

    ODD:
        y = 0;
        return y; // return should be translated into a "GOTO EXIT" statement in a S-program
}

/// Does not use any macro
int is_even_no_macro (int x) {
    int y = 0;
    int z1 = 0;

    // === BEGIN COPY X INTO Z1 ===

    A:
        if (x != 0)
            goto B;
        goto C;

    // Copy x into z1 and z2, destroying x
    B:
        x--;
        z1++;
        z2++; // It is used to restore the value of x
        goto A;

    // restore the value of x
    C:
        if (z2 != 0)
            goto D;
        goto E;

    D:
        z2--;
        x++;
        goto C;

    // === END COPY X INTO Z1 ===

    E:
        if (z2 != 0)
            goto F;
        goto EVEN;

    F:

}
