/*
Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given
conditions:
  1. Operands and operator, both must be single character.
  2. Input Postfix expression must be in a desired format.
  3. Only '+', '-', '*' and '/' operators are expected.
*/

#include <iostream>

using namespace std;

#define SIZE 50
char s[SIZE];
int top = -1;

void push(char elem) {
    s[++top] = elem;
}

char pop() {
    return (s[top--]);
}

int pr(char elem) {
    switch (elem) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
    }
    return 6;
}

int main() {
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    cout << "Infix Expression: ";
    cin >> infix;
    push('#');
    while ((ch = infix[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')') {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        } else {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        postfix[k++] = pop();
    postfix[k] = '\0';
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}


