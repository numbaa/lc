#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0, end = height.size() - 1;
        int max = 0;
        while (front < end)
        {
            max = std::max(max, (end-front)*std::min(height[front], height[end]));
            height[front] < height[end] ? front++ : end--;
        }
        return max;
    }
};


int main()
{
    vector<int> v1{1,8,6,2,5,4,8,3,7};
    Solution s;
    std::cout <<  s.maxArea(v1) << std::endl;
    return 0;
}


/*
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */
