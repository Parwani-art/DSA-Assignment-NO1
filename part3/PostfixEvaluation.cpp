#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

// Evaluates a postfix expression and returns the result
int evaluatePostfix(const string& postfix)
{
    Stack<int> numStack;

    cout << "\nStep-by-step evaluation:\n";
    cout << "----------------------------\n";

    for (int i = 0; i < (int)postfix.size(); i++)
    {
        char c = postfix[i];

        if (c == ' ')
            continue;

        // Digit → convert char to int and push
        else if (isdigit(c))
        {
            int num = c - '0';
            cout << "Read number  " << num << "       -->  push to stack\n";
            numStack.Push(num);
        }

        // Operator → pop two operands, apply, push result
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int b = numStack.Pop();   // right operand
            int a = numStack.Pop();   // left  operand
            int result = 0;

            switch (c)
            {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            }

            cout << "Apply  " << a << " " << c << " " << b
                << " = " << result << "        -->  push result\n";

            numStack.Push(result);
        }
    }

    return numStack.Pop();
}

int main()
{
    cout << "==========================================\n";
    cout << "   Part (b): Postfix Expression Evaluator \n";
    cout << "==========================================\n";

    string postfix = "5 2 3 * + 9 -";
    cout << "\nPostfix Expression : " << postfix << "\n";

    int result = evaluatePostfix(postfix);

    cout << "----------------------------\n";
    cout << "Final Result       : " << result << "\n";

    return 0;
}