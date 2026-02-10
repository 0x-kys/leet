#include <bits/stdc++.h>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }

    return result;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    for (int num : result) {
        std::cout << num << std::endl;
    }

    return 0;
}