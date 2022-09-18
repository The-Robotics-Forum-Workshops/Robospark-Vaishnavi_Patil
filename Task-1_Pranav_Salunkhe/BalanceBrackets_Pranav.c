#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
int top = -1;

int push(char stack[SIZE],int x)
{
    if(top==-1){
        top =0;
        stack[top]=x;
    }
    else{
        top++;
        stack[top]=x;
    }
}

int pop(char stack[SIZE])
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        top --;
    }
}

void display(char stack[SIZE])
{
	printf("stack is:");
    for(int i=top;i>=0;i--)
    {
        printf(" %c ",stack[i]);
    }
}

int checkbrackets(char str [],char stack[SIZE], int size)
{
    int flag = 1;
	for(int i=0;i<size;i++)
    {
        if(flag == 0) break;
        switch(str[i])
        {
            case '[':
            push(stack,str[i]);
            break;
            case '(':
            push(stack,str[i]);
            break;
            case '{':
            push(stack,str[i]);
            break;
            case ']':
            if(stack[top] == '[') pop(stack);
            else flag = 0;
            break;
            case ')':
            if(stack[top] == '(') pop(stack);
            else flag = 0;
            break;
            case '}':
            if(stack[top] == '{') pop(stack);
            else flag = 0;
            break;
        }

    }
    if(top == -1 && flag == 1)
    {
        printf("\nBrackets are balanced");
    }
    else
    {
        printf("\nBrackets are not balanced");
    }
}

int main()
{
    char stack[SIZE];
    char str[] = "{[[abc](a)]}(1)";
    int size = strlen(str);
    checkbrackets(str,stack, size);
    checkbrackets("]",stack, size);
    checkbrackets("(a)}",stack, size);
    checkbrackets("}()",stack, size);
    checkbrackets("{({}[()])}",stack, size);

    // or
    // char stack[SIZE];
    // char input[20];
    // printf("Input - ");
    // scanf("%s", input);
    // int size = strlen(input);
    // checkbrackets(input,stack, size);

    return 0;
}