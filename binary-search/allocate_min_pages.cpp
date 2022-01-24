#include <bits/stdc++.h>
using namespace std;
bool valid(int arr[], int n, int s, int max)
{
    int students = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = arr[i] + sum;
        if (sum > max)
        {
            students++;
            sum = arr[i];
        }
    }

    if (students > s)
    {
        return false;
    }
    else
        return true;
}

int binarySearch(int arr[], int n, int s)
{
    int result = -1;

    // if books is less than students
    if (n < s)
    {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = sum + arr[i];
    }

    // set l as max in arr
    int l = *max_element(arr, arr + n), h = sum;
    int res = -1;

    while (l <= h)
    {
        int mid = l + ((h - l) / 2);

        // check if mid is maximum pages a student can read
        if (valid(arr, n, s, mid) == true)
        {
            // if true then set result as mid and check if there exists a lower value(pages)
            result = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int students = 2;
    cout << "Minimum pages each student has to read:" << binarySearch(arr, n, students);
    return 0;
}
