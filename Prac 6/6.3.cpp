#include <iostream>
#include <string>
using namespace std;
int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}
int main()
{
    string infix, postfix = "";
    char stack[100];
    int top = -1;
    cout << "Enter expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9')
        {
            postfix = postfix + ch;
        }
        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix = postfix + stack[top];
                top--;
            }
            top--;
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch))
            {
                postfix = postfix + stack[top];
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }
    while (top != -1)
    {
        postfix = postfix + stack[top];
        top--;
    }
    cout << "Postfix = " << postfix << endl;
    int numbers[100];
    int nTop = -1;
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9')
        {
            nTop++;
            numbers[nTop] = ch - '0';
        }
        else
        {
            int b = numbers[nTop];
            nTop--;
            int a = numbers[nTop];
            nTop--;
            if (ch == '+')
                numbers[++nTop] = a + b;
            else if (ch == '-')
                numbers[++nTop] = a - b;
            else if (ch == '*')
                numbers[++nTop] = a * b;
            else if (ch == '/')
                numbers[++nTop] = a / b;
        }
    }
    cout << "Result = " << numbers[nTop] << endl;
    return 0;
}