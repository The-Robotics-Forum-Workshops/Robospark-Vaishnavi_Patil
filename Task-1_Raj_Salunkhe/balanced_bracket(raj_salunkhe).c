#include <stdio.h>
#include <string.h>
#define SIZE 6

int top = -1;
void push(char sta[SIZE], char cha)
{
    if(top==-1)
    {
        top=0;
        sta[top] = cha;
    }
    else
    {
        sta[++top] = cha;
    }
}

void pop(char sta[SIZE])
{
    if(top==-1)
    {
        printf("Stack is Empty !\n");
    }
    else
    {
        top--;
    }
}

void BrackCheck(char sta[SIZE], char character[SIZE])
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(character[i] == '(')
        {
            push(sta,character[i]);
        }
        else if(character[i] == '{')
        {
            push(sta,character[i]);
        }
        else if(character[i] == '[')
        {
            push(sta,character[i]);
        }

        else if(character[i] == '}')
        {
            if(sta[top]=='{')
            {
                pop(sta);
            }
            else{
                printf("Invalid String !\n");
                exit(0);
            }
        }
        else if(character[i] == ')')
        {
            if(sta[top]=='(')
            {
                pop(sta);
            }
            else{
                printf("Invalid String !\n");
                exit(0);
            }
        }
        else if(character[i] == ']')
        {
            if(sta[top]=='[')
            {
                pop(sta);
            }
            else{
                printf("Invalid String !\n");
                exit(0);
            }
        }
    }
    if(top==-1)
    {
        printf("Valid String !\n");
    }
    else
    {
        printf("4 Invalid String !\n");
        //printf("\n%d\n", top);
    }
}

void display(char sta[SIZE])
{
	printf("stack is:");
    for(int i=top;i>=0;i--)
    {
        printf(" %c ",sta[i]);
    }
}

void main()
{
    int i;
    char sta[SIZE];
    char character[SIZE];
    printf("Enter Your String: ");
    for(i=0; i<SIZE; i++)
    {
        scanf("%c", &character[i]);
    }
    BrackCheck(sta,character);
    display(sta);
}
