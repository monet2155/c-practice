#include <stdio.h>

#define MAX_SIZE (5)

typedef struct
{
    int top;
    int data[MAX_SIZE];
} Stack;

void initialize_stack(Stack *stack);
int is_full(Stack *stack);
int is_empty(Stack *stack);
void push(Stack *stack, int value);
void pop(Stack *stack);
void print_stack(Stack *stack);

int main(void)
{
    Stack stack;

    initialize_stack(&stack);

    push(&stack, 1);

    print_stack(&stack);

    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    print_stack(&stack);
    push(&stack, 6);
    print_stack(&stack);

    pop(&stack);
    print_stack(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);

    return 0;
}

void initialize_stack(Stack *stack)
{
    stack->top = -1;
}

int is_full(Stack *stack)
{
    return (stack->top + 1) == MAX_SIZE;
}

int is_empty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int value)
{
    if (is_full(stack))
    {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    stack->top++;

    stack->data[stack->top] = value;
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

void print_stack(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack : ");

    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }

    printf("\n");
}