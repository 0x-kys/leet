#include <bits/stdc++.h>

int findMin(std::vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    int res = nums[left];

    while (left <= right) {
        if (nums[left] < nums[right]) {
            res = std::min(res, nums[left]);
        }

        int mid = left + (right - left) / 2;
        res = std::min(res, nums[mid]);

        if (nums[mid] >= nums[left]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return res;
}

int main(int argv, char *argc[]) {
    std::vector<int> nums = {4, 5, 0, 1, 2, 3};

    std::cout << findMin(nums) << std::endl;

    return 0;
}