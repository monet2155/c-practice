/**
 * 구조체와 포인터
 * 학생 정보를 담는 구조체를 정의하고, 해당 구조체의 포인터를 사용하여 여러 학생의 정보를 입력하고 출력하는 프로그램을 작성하세요.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LENGTH (20)
#define LIST_LENGTH (10)

struct student
{
    char name[NAME_LENGTH + 1];
    int number;
} *list = NULL;

int read_line(char str[]);

int main(void)
{
    int number;
    int i;
    struct student *new_node = NULL;

    list = malloc(sizeof(struct student) * LIST_LENGTH);

    for (;;)
    {
        printf("Enter student number (0 to terminate): ");
        scanf("%d", &number);

        if (number == 0)
        {
            break;
        }

        new_node = malloc(sizeof(struct student));

        if (new_node == NULL)
        {
            printf("Not enough memory;\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter student name: ");

        read_line(new_node->name);
        new_node->number = number;

        if (list == NULL)
        {
            list = new_node;
        }
        else
        {
            *(list + i) = *new_node;
        }
        i++;
    }

    for (new_node = list; new_node < list + i; new_node++)
    {
        printf("number: %d / name: %s\n", new_node->number, new_node->name);
    }

    return 0;
}

int read_line(char str[])
{
    int ch;
    int i = 0;

    while (isspace(ch = getchar()))
    {
    }

    while (ch != '\n' && ch != EOF)
    {
        if (i < NAME_LENGTH)
        {
            str[i++] = ch;
        }
        ch = getchar();
    }

    str[i] = '\0';

    return i;
}
