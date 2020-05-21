#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = std::to_string(x);
        int front = 0, end = str.size() - 1;
        while (front <= end)
        {
            if (str[front] != str[end])
                return false;
            front++;
            end--;
        }
        return true;
    }
};


int main()
{
    vector<int> nums{1, 12, 12321, 123211, 0, -232};
    Solution s;
    std::cout << std::boolalpha;
    for (auto num : nums)
        std::cout << num << ':' << s.isPalindrome(num) << std::endl;
    return 0;
}
