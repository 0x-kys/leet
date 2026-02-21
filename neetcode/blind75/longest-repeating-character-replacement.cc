#include <bits/stdc++.h>

int characterReplacement(std::string s, int k)
{
    int res = 0;
    std::unordered_set<char> charSet(s.begin(), s.end());

    for (char c : charSet)
    {
        int count = 0, left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            if (s[right] == c)
            {
                count++;
            }

            while ((right - left + 1) - count > k)
            {
                if (s[left] == c)
                {
                    count--;
                }
                left++;
            }

            res = std::max(res, right - left + 1);
        }
    }

    return res;
}

int main()
{
    std::string s = "AAABABB";
    int k = 1;

    std::cout << characterReplacement(s, k) << std::endl;

    return 0;
}