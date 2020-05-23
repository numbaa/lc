#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        for (int i=0; i<strs[0].size(); i++)
        {
            for (int j=1; j<strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

int main()
{
    vector<string> s1 {"flower","flow","flight"};
    vector<string> s2 {"dog","racecar","car"};
    vector<string> s3 {"dog", ""};
    vector<string> s4 {"", ""};
    vector<string> s5 {""};
    vector<string> s6;
    vector<string> s7 {"abc", "abc", "abc"};
    vector<string> s8 {"abc"};
    vector<vector<string>> sss {s1, s2, s3, s4, s5, s6, s7, s8};
    Solution s;
    for (auto& strs : sss)
        std::cout << s.longestCommonPrefix(strs) << std::endl;
    return 0;
}

/*
 * Example 1:
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 */
