#include <bits/stdc++.h>

int lengthOfLongestSubstring(std::string s)
{
    std::unordered_map<char, int> map;
    int left = 0, res = 0;

    for (int right = 0; right < s.size(); right++)
    {
        if (map.find(s[right]) != map.end())
        {
            left = std::max(map[s[right]] + 1, left);
        }
        map[s[right]] = right;
        res = std::max(res, right - left + 1);
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::string s = "zxyzxyz";

    std::cout << lengthOfLongestSubstring(s) << std::endl;

    return 0;
}