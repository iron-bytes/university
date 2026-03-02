/*
 *  Assignment:
 *  Write a S-Program (here implemented, for simplicity, by a program in the C language)
 *  that computes f(x) = 3x.
 *  Do not alter x (although we are in a C program where variables are passed by value,
 *  we have to suppose we are in a S-program).
 *  Note: You may use the multiplicative, additive, identity macros. You may NOT use
 *  other kind of macros.
 */

 #include <stdio.h>

 void test (int result, int expected, char* name);

/// Use the multiplicative macro
int f_1(int x);

/// Additive macro only
int f_2(int x);

/// No macros
int f_3(int x);

int main () {
    int x = 5;
    int y = 0;

    y = f_1(x);
    test(y, 3*x, "f_1");

    y = f_2(x);
    test(y, 3*x, "f_2");

    y = f_3(x);
    test(y, 3*x, "f_3");

    return 0;
 }

void test(int result, int expected, char* name) {
  if (result == expected) {
        printf("%s test PASSED \n", name);
    }
    else {
        printf("%s test FAILED (Expected: %d, Received: %d) \n", name, expected, result);
    }
}

/// Use the multiplicative macro
int f_1 (int x) {
    int y; // We want to use the y variable, according to the S-program specification
    y = 3 * x; // Multiplicative macro
    return y;
}

/// Additive macro only
int f_2 (int x) {
    int z1 = 0;
    int z2 = 0;
    int y = 0;

    z1 = 3; // Identity macro
    B:
        if (z1 != 0)
            goto A;
        goto EXIT;

    A:
        z2 = y + x; // Additive macro
        y = z2;
        z1 = z1 - 1;
        goto B;

    EXIT:
        return y;
}

/// No macros
int f_3 (int x) {
    int three = 0; // This is an illegal name for a variable in an S-program but allow me to do that
    int z2 = 0;
    int y = 0;

    three = three + 1;
    three = three + 1;
    three = three + 1;

    F:
        if (three != 0)
            goto A;
        goto EXIT;

    // === BEGIN Sum Y with X ===
    A:
        if (x != 0)
            goto B;
        goto C;

    B:
        x--;
        y++;
        z2++;
        goto A;
    // === END Sum Y with X ===

    // === BEGIN Recover the value of X ===
    C:
        if (z2 != 0)
            goto D;
        goto E;

    D:
        z2--;
        x++;
        goto C;
    // === END Recover the value of X ===

    E:
        three--;
        goto F;

    EXIT:
        return y;

}

