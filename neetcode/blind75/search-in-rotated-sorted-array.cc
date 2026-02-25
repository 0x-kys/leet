#include <bits/stdc++.h>

int binarySearch(std::vector<int> &nums, int target, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int search(std::vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    int result = binarySearch(nums, target, 0, left - 1);
    if (result != -1) {
        return result;
    }

    return binarySearch(nums, target, left, nums.size() - 1);
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> nums = {3, 5, 6, 0, 1, 2};
    std::cout << search(nums, 4) << std::endl;

    return 0;
}