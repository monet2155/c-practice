/**
 * 기본 포인터 활용
 * 두 개의 정수를 입력받아 포인터를 사용하여 그 합을 계산하고 출력하는 프로그램을 작성하세요
 */

#include <stdio.h>

int sum(int *number1, int *number2);

int main(void)
{
    int number1;
    int number2;

    printf("Enter number 1: ");
    scanf("%d", &number1);

    printf("Enter number 2: ");
    scanf("%d", &number2);

    printf("The sum is %d\n", sum(&number1, &number2));

    return 0;
}

int sum(int *number1, int *number2)
{
    return *number1 + *number2;
}