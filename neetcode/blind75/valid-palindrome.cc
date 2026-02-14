#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    string clean_s = "";
    for (char c : s)
    {
        if (isalnum(c))
        {
            clean_s += tolower(c);
        }
    }

    string rev = clean_s;
    reverse(rev.begin(), rev.end());

    return clean_s == rev;
}

int main()
{
    string str = "Was it a car or a cat I saw?";
    cout << isPalindrome(str) << endl;

    return 0;
}