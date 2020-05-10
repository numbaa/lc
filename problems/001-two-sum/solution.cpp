#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i=0; i<nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for (int i=0; i<nums.size(); i++)
        {
            int need = target - nums[i];
            auto iter = m.find(need);
            if (iter != m.end() && iter->second != i)
            {
                return {i, iter->second };
            }
        }
        return {0, 1};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11,15};
    auto result = sol.twoSum(nums, 18);
    std::cout << result[0] << ',' << result[1] << std::endl;
    return 0;
}