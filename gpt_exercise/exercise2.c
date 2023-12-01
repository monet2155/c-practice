/**
 * 기본 포인터 활용
 * 정수 배열을 선언하고 해당 배열의 요소에 접근하여 값을 변경하는 프로그램을 작성하세요.
 */

#include <stdio.h>

#define LIST_LENGTH (10)

int main(void)
{
    int list[LIST_LENGTH] = {0};

    int i;
    int new_number;

    for (;;)
    {
        printf("Enter target index (0-%d, -1 to terminate): ", LIST_LENGTH);
        scanf("%d", &i);

        if (i == -1)
        {
            break;
        }

        if (i < 0 || i >= LIST_LENGTH)
        {
            printf("Wrong target index\n");
            return 0;
        }

        printf("Enter new number: ");
        scanf("%d", &new_number);

        list[i] = new_number;
    }

    printf("\nindex     number\n");
    for (i = 0; i < LIST_LENGTH; i++)
    {
        printf("%d      %d\n", i, list[i]);
    }

    return 0;
}