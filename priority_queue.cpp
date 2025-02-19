/*
Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. Create a class
that includes the data items (which should be template) and the priority (which should be int). The inorder list should
contain these objects, with operator <= overloaded so that the items with highest priority appear at the start of the
list (which will make it relatively easy to retrieve the highest item.)
*/
#include <iostream>

using namespace std;

int f = 0, r = -1;

template<class T>
class priorityQ {
public:
    T arr[100];

    void push(T x);

    T pop();

    void printQ();
};

template<class T>
void priorityQ<T>::push(T x) {
    if (r >= 5)
        cout << "\nJob Queue is full";
    else {
        r++;
        arr[r] = x;
    }
}

template<class T>
void priorityQ<T>::printQ() {
    for (int i = f; i <= r; i++) {
        cout << "\n" << arr[i];
    }
}

template<class T>
T priorityQ<T>::pop() {
    T p;
    if (f > r)
        cout << "Queue is empty";
    else {
        p = arr[f];
        f = f + 1;
        return (p);
    }
}

int main() {
    char t1, pp, el[10], sudo_ch;
    int ch = 1, n;
    int p[10], i, j, t;
    priorityQ<char> int_q;
    cout << "No. of jobs: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Job ID: ";
        cin >> el[i];
        cout << "Job priority: ";
        cin >> p[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (p[i] < p[j]) {
                t = p[i];
                t1 = el[i];
                p[i] = p[j];
                el[i] = el[j];
                p[j] = t;
                el[j] = t1;
            }

        }
    }
    cout << "\n\nSorted jobs";
    for (i = 0; i < n; i++) {
        cout << "\nJob id: " << el[i];
        cout << "\nJob Priority: " << p[i];
        int_q.push(el[i]);
    }
    ch = 1;
    while (ch == 1) {
        pp = int_q.pop();
        cout << "\nPopped Job: " << pp;
        cout << "\nDo you want to pop more jobs(Y/N)?! ";
        cin >> sudo_ch;
        if (sudo_ch == 'Y' || sudo_ch == 'y') {
            ch = 1;
        } else {
            ch = 0;
        }
    }
    cout << "\nJob Queue contents";
    int_q.printQ();
}

