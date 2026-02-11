#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> sort_map;

    for (auto &str : strs)
    {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        sort_map[sorted_str].push_back(str);
    }

    vector<vector<string>> result;

    for (auto &sorted_pair : sort_map)
    {
        result.push_back(sorted_pair.second);
    }

    return result;
}

int main()
{
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};

    vector<vector<string>> result = groupAnagrams(strs);

    for (auto &items : result)
    {
        cout << "[ ";
        for (auto &item : items)
        {
            cout << item << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}