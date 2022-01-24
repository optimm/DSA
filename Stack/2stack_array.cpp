#include <bits/stdc++.h>

using namespace std;

int arr[10], top1 = -1, top2 = 10;

void push1(int n)
{
    if (top1 == top2 - 1)
    {
        cout << "overflow stack 1\n";
    }
    else
    {
        top1++;
        arr[top1] = n;
    }
}
void push2(int n)
{
    if (top2 == top1 - 1)
    {
        cout << "overflow stack 2\n";
    }
    else
    {
        top2--;
        arr[top2] = n;
    }
}
void pop1()
{
    if (top1 == -1)
    {
        cout << "underflow stack 1\n";
    }
    else
    {
        cout << arr[top1] << "\n";
        top1--;
    }
}
void pop2()
{
    if (top2 == 10)
    {
        cout << "underflow stack 2\n";
    }
    else
    {
        cout << arr[top2] << "\n";
        top2++;
    }
}
void peak1()
{
    if (top1 == -1)
    {
        cout << "empty stack 1\n";
    }
    else
    {
        cout << arr[top1] << "\n";
    }
}
void peak2()
{
    if (top2 == 10)
    {
        cout << "empty stack 2\n";
    }
    else
    {
        cout << arr[top2] << "\n";
    }
}
int main()
{
    push1(1);
    push1(2);
    push1(3);
    push1(4);
    push1(5);
    push2(6);
    push2(7);
    push2(8);
    push2(9);
    push2(10);
    pop1();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2();


// 4 5 6 1 2
}
