#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int bsearch(vector<int>& nums, int first, int end, int target) {
        while (first <= end)
        {
            int mid = (first + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                first = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int front = 0;
        int end = nums.size() - 1;
        int found = bsearch(nums, front, end, target);
        cout << "found:" << found << endl;
        if (found == -1) return {-1, -1};
        int first = found, last = found, tmp;
        while ((tmp = bsearch(nums, 0, first - 1, target)) != -1)
        {
            first = tmp;
        }
        while ((tmp = bsearch(nums, last + 1, end, target)) != -1)
        {
            last = tmp;
        }
        return {first, last};
    }
};

int main()
{
    vector<int> nums{6};
    Solution s;
    auto result = s.searchRange(nums, 6);
    cout << result[0] << ',' << result[1] << endl;
    return 0;
}


