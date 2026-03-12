/**
 *  For each n,m >= 0, let q(m,n) be the smallest prime number p
 *  such that m <= p <= n if it exists. Otherwise it diverges.
 */

#include <stdio.h>
#include "test-suite.c"

int less_equal (int a, int b);

int main (void) {

    return 0;
}

/// Returns 1 if a <= b
int less_equal (int a, int b) {

    int z1, z2;
    z1 = 0;
    z2 = 0;

    // === BEGIN COPY A INTO Z1 ===

    C:
        if (a != 0)
            goto A;
        goto B;

    A:
        a--;
        z1++;
        z2++; // z2 is used to recover the value of z2 later
        goto C;

    // Restore the value of a
    B:
        if (z2 != 0)
            goto D;
        goto E;

    D:
        z2--;
        a++;
        goto B;

    E:

    // === END COPY A INTO Z1 ===

    /// Now we won't copy b into z3 to keep the
    /// program short and readable. Furthermore,
    /// we'll operate on 'a' and 'b' for the purpose,
    /// again, of making the program readable

    // Now we will not compute "if(a <= b)" because
    // (at least with this technique) it'd have been impossible
    // to determine the correct value.
    // We shall instead compute NOT( a > b)

        if (b != 0)
            goto G;
        goto H;

    G:
        b--;

        if(a >= 1){ // This instruction must not be translated in S, since B <-- B - 1 never goes below 0
            a--;
        }

        goto E;


    H:
        if (a != 0)
            return 0;
        return 1;
}

