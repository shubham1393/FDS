/*
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
*/

#include <iostream>

#define MAX 10

using namespace std;

struct queue {
    int data[MAX];
    int front, rear;
};

class Queue {
    struct queue q;
public:
    Queue() { q.front = q.rear = -1; }

    int isempty();

    int is_full();

    void enqueue(int);

    int del_queue();

    void display();
};

int Queue::isempty() {
    return (q.front == q.rear) ? 1 : 0;
}

int Queue::is_full() {
    return (q.rear == MAX - 1) ? 1 : 0;
}

void Queue::enqueue(int x) {
    q.data[++q.rear] = x;
}

int Queue::del_queue() {
    return q.data[++q.front];
}

void Queue::display() {
    int i;
    cout << "\n";
    for (i = q.front + 1; i <= q.rear; i++)
        cout << q.data[i] << " ";
}

int main() {
    Queue obj;
    int ch, x;
    cout << "1. Insert Job\n2. Delete Job\n3. Display\n4. Exit";
    do {
        cout << "\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                if (!obj.is_full()) {
                    cout << "Enter data: ";
                    cin >> x;
                    obj.enqueue(x);
                } else
                    cout << "Queue is overflow";
                break;
            case 2:
                if (!obj.isempty())
                    cout << "Deleted Element: " << obj.del_queue();
                else {
                    cout << "\n Queue is underflow";
                }
                cout << "\nRemaining jobs: ", obj.display();
                cout << endl;
                break;
            case 3:
                if (!obj.isempty()) {
                    cout << "Queue contains: ", obj.display();
                    cout << endl;
                } else
                    cout << "Queue is empty!!";
                break;
            case 4:
                cout << "Exiting...";
                exit(0);
        }
    } while (ch != 4);
    return 0;
}

