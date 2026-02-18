#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &heights)
{
    if (heights.size() < 2)
    {
        return 0;
    }

    int res = 0;
    int left = 0;
    int right = heights.size() - 1;

    while (left < right)
    {
        int area = (right - left) * min(heights[left], heights[right]);
        res = max(res, area);

        if (heights[left] < heights[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return res;
}

int main()
{
    vector<int> heights = {1, 7, 2, 5, 4, 7, 3, 6};

    cout << maxArea(heights) << endl;

    return 0;
}
