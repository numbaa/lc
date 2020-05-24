#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct Group {
    vector<int> nums;
    const int max() const
    {
        return std::max(nums[0], std::max(nums[1], nums[2]));
    }
    const int min() const
    {
        return std::min(nums[0], std::min(nums[1], nums[2]));
    }
    const bool operator==(const Group& other) const
    {
        return max() == other.max() && min() == other.min();   
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>{};
        //unordered_map<int/*num*/, vector<int>/*index*/> indexes;
        map<int/*num*/, vector<int>/*index*/> indexes;
        vector<Group> results;
        for (int i=0; i<nums.size(); i++)
        {
            auto iter = indexes.find(nums[i]);
            if (iter == indexes.end())
                indexes[nums[i]] = { i };
            else
                iter->second.push_back(i);
        }
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                auto iter = indexes.find(0-nums[i]-nums[j]);
                if (iter == indexes.end())
                    continue;
                for (auto third_idx : iter->second)
                    if (third_idx > j)
                    {
                        auto new_group = Group{{nums[i], nums[j], nums[third_idx]}};
                        if (!exist(new_group, results))
                            results.push_back(new_group);
                    }
            }
        }
        vector<vector<int>> transformed_result(results.size());
        for (int i=0; i<transformed_result.size(); i++)
            transformed_result[i] = std::move(results[i].nums);
        return transformed_result;
    }

    bool exist(const Group& new_group, const vector<Group>& results) const
    {
        for (auto& group : results)
            if (group == new_group)
                return true;
        return false;
    }
};

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution s;
    auto results = s.threeSum(nums);
    for (auto& result : results)
    {
        cout << '[';
        for (auto& num : result)
            cout << num << ',';
        cout << "]";
    }
    return 0;
}


/*
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/