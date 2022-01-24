#include <bits/stdc++.h>
using namespace std;
struct Queue
{
    int cap, size;
    int *arr;
    Queue(int c)
    {
        cap = c;
        arr = new int[cap];
        size = 0;
    }

    void enque(int x)
    {
        if (isFull())
        {
            cout << "Queue Full\n";
            return;
        }
        arr[size] = x;
        size++;
    }
    void deque()
    {
        if (isEmpty())
        {
            cout << "Queue Empty\n";
            return;
        }
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == -1);
    }
    void getFront()
    {
        if (isEmpty())
        {
            cout << "Queue Empty\n";
            return;
        }
        cout << arr[0] << endl;
    }
    void getRear()
    {
        if (isEmpty())
        {
            cout << "Queue Empty\n";
            return;
        }
        cout << arr[size - 1] << endl;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue Empty\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue s(10);
    s.print();

    // inserting elements in the queue
    s.enque(20);
    s.enque(30);
    s.enque(40);
    s.enque(50);
    s.deque();
    s.enque(50);
    s.getFront();
    s.getRear();
    // print Queue elements
    s.print();
    return 0;
}