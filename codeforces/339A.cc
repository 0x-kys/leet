#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string inp;

    std::cin >> inp;

    std::vector<int> nums;

    for (char c : inp) {
        if (c != '+') {
            nums.emplace_back(c - '0');
        }
    }

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i != nums.size() - 1) {
            std::cout << nums[i] << "+";
        } else {
            std::cout << nums[i] << std::endl;
        }
    }

    return 0;
}