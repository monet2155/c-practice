#include <stdio.h>

#define MAX_SIZE (6)

typedef struct
{
    int top;
    int data[MAX_SIZE];
} Stack;

void initialize_stack(Stack *stack);
void push(Stack *stack, int value);
void pop(Stack *stack);
int is_full(Stack *stack);
int is_empty(Stack *stack);
void print_stack(Stack *stack);

int main(void)
{
    Stack stack;

    initialize_stack(&stack);
    print_stack(&stack);

    push(&stack, 1);

    print_stack(&stack);

    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);

    print_stack(&stack);

    push(&stack, 7);

    print_stack(&stack);

    pop(&stack);

    print_stack(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    print_stack(&stack);

    pop(&stack);

    push(&stack, 1);
    push(&stack, 2);
    pop(&stack);
    push(&stack, 4);
    print_stack(&stack);

    return 0;
}

void initialize_stack(Stack *stack)
{
    stack->top = -1;
}

void push(Stack *stack, int value)
{
    if (is_full(stack))
    {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    stack->data[++stack->top] = value;
}

void pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    stack->top--;
}

int is_full(Stack *stack)
{
    return (stack->top == (MAX_SIZE - 1));
}

int is_empty(Stack *stack)
{
    return (stack->top == -1);
}

void print_stack(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }

    int i = stack->top;

    printf("Stack : ");

    for (; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }

    printf("\n");
}