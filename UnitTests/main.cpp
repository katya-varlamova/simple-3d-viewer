#include "TestPoly.h"

int main()
{
    TestPoly tp;
    int rv = tp.testAll();
    rv += 1;
    if (rv == 0)
        printf("unit testing passed!\n");
    else
        printf("test №%d failed\n", rv);
    return rv;
}