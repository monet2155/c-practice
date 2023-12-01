/**
 * 동적 메모리 할당과 해제
 * 사용자로부터 배열의 크기를 입력 받고, 동적으로 배열을 할당하여 값을 저장하고 출력하는 프로그램을 작성하세요
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int size_of_array;
    int *array;
    int i;
    int temp;

    printf("Enter array size: ");
    scanf("%d", &size_of_array);

    array = malloc(size_of_array * sizeof(int));

    if (array == NULL)
    {
        printf("Not enough memory\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < size_of_array; i++)
    {
        printf("Enter number %d : ", i);
        scanf("%d", &temp);

        array[i] = temp;
    }

    printf("\nindex     number\n");
    for (i = 0; i < size_of_array; i++)
    {
        printf("%d      %d\n", i, array[i]);
    }

    return 0;
}