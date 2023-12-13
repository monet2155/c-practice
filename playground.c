#include <stdio.h>
#include "includetest.h"

int main(void)
{
    printf("%5.3d\n", 40);
    printf("%10.3f\n", 839.21f);
    printf("%10.3e\n", 839.21f);
    printf("%-10g\n", 839.21f);
    return 0;
}