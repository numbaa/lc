#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int end = nums.size() - 1;
        while (first <= end)
        {
            int mid = (end + first) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[first])
            {
                if (nums[mid] < target && target <= nums[end]) first = mid + 1;
                else end = mid - 1;
            }
            else if (nums[mid] > nums[end])
            {
                if (nums[mid] > target && target >= nums[first]) end = mid - 1;
                else first = mid + 1;
            }
            else
            {
                if (nums[mid] > target) end = mid - 1;
                else first = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums {4,5,6,7,0,1,2};
    std::cout << s.search(nums, 0) << ',' << s.search(nums, 3) << std::endl;
    return 0;
}


/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4 

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */
