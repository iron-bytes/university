#ifndef EDIT_LIBRARY
#define EDIT_LIBRARY

void test (int result, int expected, char* name);
void test(int result, int expected, char* name) {
  if (result == expected) {
        printf("%s test PASSED \n", name);
    }
    else {
        printf("%s test FAILED (Expected: %d, Received: %d) \n", name, expected, result);
    }
}
#endif
