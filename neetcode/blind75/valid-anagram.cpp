#include <bits/stdc++.h>

// sol1 hashmap
bool isAnagram(std::string s, std::string t)
{
    if (s.length() != t.length())
        return false;

    int size = s.length();

    std::unordered_map<char, int> um_s;
    std::unordered_map<char, int> um_t;

    for (char c : s)
    {
        um_s[c]++;
    }

    for (char c : t)
    {
        um_t[c]++;
    }

    return um_s == um_t;
}

int main()
{
    std::string s = "ello";
    std::string t = "leloo";

    if (isAnagram(s, t))
    {
        std::cout << "is anagram" << std::endl;
    }
    else
    {
        std::cout << "is not anagram" << std::endl;
    }

    return 0;
}
