#include <bits/stdc++.h>

using namespace std;

int arr[10], top = -1;

void push(int n)
{
    if (top == 9)
    {
        cout << "overflow\n";
    }
    else
    {
        top++;
        arr[top] = n;
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "underflow\n";
    }
    else
    {
        cout << arr[top] << "\n";
        top--;
    }
}
void peak()
{
    if (top == -1)
    {
        cout << "empty\n";
    }
    else
    {
        cout << arr[top] << "\n";
    }
}
int main()
{
    push(5);
    push(6);
    push(7);
    pop();
    peak();
}
