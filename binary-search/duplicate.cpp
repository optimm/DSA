#include <bits/stdc++.h>
using namespace std;
// find the only duplicate number in the array , --- approach 1 - sort and check - use map

// approach-2---- negative marking--- good approach

// For example, if the input array is [1, 3, 3, 2], then for 1, flip the number at index 1, making the array [1,-3,3,2]. Next, for -3 flip the number at index 3, making the array [1,-3,3,-2]. Finally, when we reach the second 3, we'll notice that nums[3] is already negative, indicating that 3 has been seen before and hence is the duplicate number.

int findDuplicate(vector<int> &nums)
{
    int duplicate = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur = abs(nums[i]);
        if (nums[cur] < 0)
        {
            duplicate = cur;
            break;
        }
        nums[cur] *= -1;
    }

    // Restore numbers
    for (auto &num : nums)
        num = abs(num);

    return duplicate;
}
//// another approach map all indexes to 0
// To illustrate the algorithm, lets consider an example[3, 3, 5, 4, 1, 3]:
//[ 3, 3, 5, 4, 1, 3 ]  Compare nums[0] to nums[nums[0]] (i.e. nums[0] to nums[3]). 3 != 4 Swap them. Now the first 3 will be swapped into its correct position, and position 0 has 4.
// [4, 3, 5, 3, 1, 3] // Compare nums[0] to nums[4]. 4 != 1. Not equal, so swap again. Now 4 is in its correct position.
//[1, 3, 5, 3, 4, 3] // Compare nums[0] with nums[1]. Not equal, swap.
//[3, 1, 5, 3, 4, 3] // Now nums[0] == nums[3] (both are 3). That's it! 3 is in both positions 0 and position 3, so it's the duplicate.
int findDuplicate(vector<int> &nums)
{
    while (nums[0] != nums[nums[0]])
        swap(nums[0], nums[nums[0]]);
    return nums[0];
}

/// --- binary search approach for each number in 1-n count of num<=x is equal to x and if > it means that duplicate occured
// example 1 2 3 4 4 5 - jaise 3 tak num bhi 3 hai to left half me to occur nahi karega right me karega or agar kahin occur kar raha hai to vo ek possible ans hua and fir left me firse lagao

int findDuplicate(vector<int> &nums)
{

    // Lambda function to count how many numbers are less than or equal to 'cur'
    auto small_or_equal = [&](int cur)
    {
        int count = 0;
        for (auto &num : nums)
        {
            if (num <= cur)
                count++;
        }
        return count;
    };

    // 'low' and 'high' represent the range of values of the target
    int low = 1, high = nums.size();
    int duplicate = -1;
    while (low <= high)
    {
        int cur = (low + high) / 2;

        if (small_or_equal(cur) > cur)
        {
            duplicate = cur;
            high = cur - 1;
        }
        else
        {
            low = cur + 1;
        }
    }

    return duplicate;
}
/// print all duplicate another method
// trat array as hash map
vector<int> dupli(vector<int> v)
{
    vector<int> s;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        v[v[i] % n] += n;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] / n > 1)
            s.push_back(i);
    }
    return s;
}

//// for other algos also check the questions sol
// there is bitset one too

/// floyd's tortoise and hare------read the algo in sol
int duplicate(vector<int> v)
{
    int slow = v[0];
    int fast = v[0];
    do
    {
        slow = v[slow];
        fast = v[v[fast]];
    } while (slow != fast);

    fast = v[0];
    while (slow != fast)
    {
        slow = v[slow];
        fast = v[fast];
    }
    return slow;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    return 0;
}