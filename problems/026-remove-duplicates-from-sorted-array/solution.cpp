#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int prev = nums[0];
        int gap = 0;
        int len = 1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                gap++;
            }
            else
            {
                nums[i-gap] = nums[i];
                len++;
            }
            prev = nums[i];
        }
        return len;
    }
};


