#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> count_map;
    for (int num : nums)
    {
        count_map[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for (auto &entry : count_map)
    {
        min_heap.push({entry.second, entry.first});

        if (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }

    vector<int> result;
    while (!min_heap.empty())
    {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    int k = 2;

    return 0;
}