#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int weight[128] = { 0 };
        weight['I'] = 1;
        weight['V'] = 5;
        weight['X'] = 10;
        weight['L'] = 50;
        weight['C'] = 100;
        weight['D'] = 500;
        weight['M'] = 1000;
        int prev = 0;
        int result = 0;
        for (int i=s.size()-1; i>=0; i--)
        {
            int w = weight[s[i]];
            if (w < prev) result -= w;
            else result += w;
            prev = w;
        }
        return result;
    }
};


int main()
{
    vector<string> nums {"III", "IV", "IX", "LVIII", "MCMXCIV"};
    Solution s;
    for (auto& num : nums)
        std::cout << num << ":" << s.romanToInt(num) << std::endl;
    return 0;
}
/*
            Input: "III"
            Output: 3

            Input: "IV"
            Output: 4

            Input: "IX"
            Output: 9

            Input: "LVIII"
            Output: 58

            Input: "MCMXCIV"
            Output: 1994
*/

