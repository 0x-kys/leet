#include <bits/stdc++.h>

bool isValid(std::string s)
{
    std::stack<char> stack;
    std::unordered_map<char, char> map = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    for (char c : s)
    {
        if (map.count(c))
        {
            if (!stack.empty() && stack.top() == map[c])
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            stack.push(c);
        }
    }

    return stack.empty();
}

int main(int argc, char *argv[])
{
    std::string s = "([{{])";

    std::cout << isValid(s) << std::endl;

    return 0;
}