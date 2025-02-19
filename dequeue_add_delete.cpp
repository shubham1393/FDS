/*
Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.
*/

#include<iostream>

#define SIZE 10

using namespace std;

class dequeue {
    int a[20], f, r;
public:
    dequeue();

    void insert_begin(int);

    void insert_end(int);

    void delete_front();

    void delete_rear();

    void show();
};

dequeue::dequeue() {
    f = -1;
    r = -1;
}

void dequeue::insert_end(int i) {
    if (r >= SIZE - 1) {
        cout << "Overflow!!!" << endl;
    } else {
        if (f == -1) {
            f++;
            r++;
        } else {
            r = r + 1;
        }
        a[r] = i;
    }
}

void dequeue::insert_begin(int i) {
    if (f == -1) {
        f = 0;
        a[++r] = i;
    } else if (f != 0) {
        a[--f] = i;
    } else {
        cout << "Overflow!!!" << endl;
    }
}

void dequeue::delete_front() {
    if (f == -1) {
        cout << "Empty Dequeue" << endl;
        return;
    } else {
        cout << "Item deleted: " << a[f];
        if (f == r) {
            f = r = -1;
            return;
        } else {
            f = f + 1;
        }
        cout << endl;
    }
}

void dequeue::delete_rear() {
    if (f == -1) {
        cout << "Empty Dequeue" << endl;
        return;
    } else {
        cout << "Item deleted: " << a[r];
        if (f == r) {
            f = r = -1;
        } else {
            r = r - 1;
        }
        cout << endl;
    }
}

void dequeue::show() {
    if (f == -1) {
        cout << "Dequeue is empty";
    } else {
        for (int i = f; i <= r; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int c, i;
    dequeue d;
    cout
            << "\n 1. Insert at beginning\n 2. Insert at end\n 3. Display\n 4. Delete from front\n 5. Delete from rear\n 6. Exit"
            << endl;
    do {
        cout << "Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter element: ";
                cin >> i;
                d.insert_begin(i);
                break;
            case 2:
                cout << "Enter element: ";
                cin >> i;
                d.insert_end(i);
                break;
            case 3:
                d.show();
                break;
            case 4:
                d.delete_front();
                break;
            case 5:
                d.delete_rear();
                break;
            case 6:
                cout << "Exiting...";
                exit(0);
            default:
                cout << "Try Again!!!\n";
                break;
        }
    } while (c != 7);
}

