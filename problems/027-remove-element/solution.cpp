#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        int gap = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] == val)
                gap++;
            else
            {
                length++;
                nums[i-gap] = nums[i];
            }
        }
        return length;
    }
};
