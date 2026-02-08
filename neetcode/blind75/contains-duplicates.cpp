#include <bits/stdc++.h>

bool hasDuplicate(std::vector<int> &nums)
{
    std::unordered_set<int> seen;

    for (int num : nums)
    {
        if (seen.find(num) != seen.end())
        {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main()
{
    std::vector<int> nums;

    for (int i = 0; i < 5; i++)
    {
        nums.push_back(i);
    }
    nums.push_back(3);

    if (hasDuplicate(nums))
    {
        std::cout << "Has duplicates" << std::endl;
    }
    else
    {
        std::cout << "Duplicate free" << std::endl;
    }

    return 0;
}
