/**
 * 동적 메모리 할당과 해제
 * 문자열을 입력받아 동적으로 메모리를 할당하고, 해당 문자열을 역순으로 출력하는 프로그램을 작성하세요.
 */

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_LENGTH (10)

int main(void)
{
    char *p = malloc(INITIAL_LENGTH * sizeof(char));
    char ch;

    int size = INITIAL_LENGTH;
    int i = 0;

    printf("Enter string: ");

    while ((ch = getchar()) != '\n')
    {
        p[i] = ch;
        i++;

        if (i == size)
        {
            size *= 2;
            p = realloc(p, size * sizeof(char));

            if (p == NULL)
            {
                printf("Realloc error\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    for (i = i - 1; i >= 0; i--)
    {
        printf("%c", p[i]);
    }

    printf("\n");

    return 0;
}