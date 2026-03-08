#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

// Returns operator precedence
int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Returns true if character is an operator
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Converts infix expression to postfix
string infixToPostfix(const string& infix)
{
    Stack<char> opStack;
    string postfix = "";

    cout << "\nStep-by-step conversion:\n";
    cout << "----------------------------\n";

    for (int i = 0; i < (int)infix.size(); i++)
    {
        char c = infix[i];

        if (c == ' ')
            continue;

        // Operand → goes straight to output
        else if (isalnum(c))
        {
            postfix += c;
            postfix += ' ';
            cout << "Read operand  '" << c << "'  -->  output: " << postfix << "\n";
        }

        // Left parenthesis → push onto stack
        else if (c == '(')
        {
            opStack.Push(c);
            cout << "Read '('           -->  push to stack\n";
        }

        // Right parenthesis → pop until matching '('
        else if (c == ')')
        {
            cout << "Read ')'           -->  pop until '('\n";
            while (!opStack.isEmpty())
            {
                char top = opStack.Pop();
                if (top == '(')
                    break;              // discard '(' and stop
                postfix += top;
                postfix += ' ';
            }
        }

        // Operator → pop higher/equal precedence first, then push
        else if (isOperator(c))
        {
            while (!opStack.isEmpty())
            {
                char top = opStack.Pop();

                if (top == '(' || precedence(top) < precedence(c))
                {
                    opStack.Push(top);  // put it back
                    break;
                }
                postfix += top;
                postfix += ' ';
            }
            opStack.Push(c);
            cout << "Read operator '" << c << "'   -->  push to stack\n";
        }
    }

    // Pop all remaining operators
    while (!opStack.isEmpty())
    {
        postfix += opStack.Pop();
        postfix += ' ';
    }

    return postfix;
}

int main()
{
    cout << "==========================================\n";
    cout << "   Part (a): Infix to Postfix Conversion  \n";
    cout << "==========================================\n";

    string infix = "(A + B) * (C - D) + E";
    cout << "\nInfix Expression  : " << infix << "\n";

    string result = infixToPostfix(infix);

    cout << "----------------------------\n";
    cout << "Postfix Result    : " << result << "\n";

    return 0;
}
