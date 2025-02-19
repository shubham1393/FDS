/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program
using stack to check whether given expression is well parenthesized or not.
*/

#include<iostream>

using namespace std;

class stack {
    char s[70];
    int top;
public:
    void push(char val);

    char pop();

    bool isempty();

    stack() {
        top = -1;
    }
};

void stack::push(char val) {
    if (top <= 69) {
        top++;
        s[top] = val;
    } else
        cout << "Stack is FUll!!" << endl;
}

char stack::pop() {
    char val;
    if (!isempty()) {
        val = s[top];
        top--;
        return val;
    } else {
        cout << "Stack is Empty!!" << endl;
        return '*';
    }
}

bool stack::isempty() {
    if (top == -1) {
        return -1;
    } else
        return 0;
}

class parenthesis {
    char expn[70];
    stack obj;
public:
    void read();

    void check_expn();
};

void parenthesis::read() {
    cout << "Enter expression: ";
    cin >> expn;
}

void parenthesis::check_expn() {
    int i, flag;
    char ch;
    for (i = 0; expn[i] != '\0'; i++) {
        if (expn[i] == '{' || expn[i] == '[' || expn[i] == '(') {
            obj.push(expn[i]);
        }
    }
    flag = 0;
    for (i = 0; expn[i] != '\0'; i++) {
        if (expn[i] == '}' || expn[i] == ']' || expn[i] == ')') {
            if (!obj.isempty()) {
                ch = obj.pop();
                if (expn[i] == '}' && ch != '{') {
                    cout << "Not well parenthesized" << endl;
                    flag = 1;
                    break;
                }
                if (expn[i] == ']' && ch != '[') {
                    cout << "Not well parenthesized" << endl;
                    flag = 1;
                    break;
                }
                if (expn[i] == ')' && ch != '(') {
                    cout << "Not well parenthesized" << endl;
                    flag = 1;
                    break;
                }
            } else {
                cout << "Not well parenthesized" << endl;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0 && obj.isempty())
        cout << "Well parenthesized" << endl;
    else
        cout << "Not well parenthesized" << endl;

}

int main() {
    parenthesis p;
    p.read();
    p.check_expn();
    return 0;
}

/*

 OUTPUT:
Enter expression: (a+b(c*d)/(f-g)))
Not well parenthesized
Not well parenthesized
PS C:\Users\Kishor\OPP\FDS_EX_KISHOR> ((a+b)*c)/d((a+b)*c)/d

*/