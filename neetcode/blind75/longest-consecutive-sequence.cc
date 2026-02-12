#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int longest = 0;
    unordered_set<int> nums_set(nums.begin(), nums.end());

    for (int num : nums)
    {
        if (!nums_set.count(num - 1))
        {
            int currentNum = num;
            int currentStreak = 1;

            while (nums_set.count(currentNum + 1))
            {
                currentNum += 1;
                currentStreak += 1;
            }

            longest = max(longest, currentStreak);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {2, 20, 4, 10, 3, 4, 5};

    cout << longestConsecutive(nums) << endl;

    return 0;
}