#include <bits/stdc++.h>
using namespace std;
struct Queue
{
    int front, cap, size;
    int *arr;
    Queue(int c)
    {
        front = 0;
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
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void deque()
    {
        if (isEmpty())
        {
            cout << "Queue Empty\n";
            return;
        }
        front = (front + 1) % cap;
        size--;
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    int getFront()
    {
        if (isEmpty())
        {
            // cout << "Queue Empty\n";
            return -1;
        }
        // cout << arr[front] << endl;
        return front;
    }
    int getRear()
    {
        if (isEmpty())
        {
            // cout << "Queue Empty\n";
            return -1;
        }
        return (front + size - 1) % cap;
        // cout << arr[(front + size - 1) % cap] << endl;
    }
  
};

int main()
{
    Queue s(10);
    // s.print();

    // inserting elements in the queue
    s.enque(20);
    s.enque(30);
    s.enque(40);
    s.enque(50);
    s.deque();
    s.enque(50);
    // s.getFront();
    // s.getRear();
    // print Queue elements
    // s.print();
    return 0;
}