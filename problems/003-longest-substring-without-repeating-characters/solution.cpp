#include <string>
#include <map>
#include <set>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int32_t last_index[128];
        for (int i=0; i<128; i++)
            last_index[i] = -1;
        int max_distance = 0;
        for (int front=-1, end = 0; end<s.size(); end++)
        {
            auto idx = last_index[s[end]];
            if (idx == -1 || idx < front)
            {
                max_distance = std::max(max_distance, end - front);
            }
            else
            {
                front = idx;
            }
            last_index[s[end]] = end;
        }
        return max_distance;
    }
};

int main()
{
    Solution s;
    std::string s1 = "bbbb";
    std::string s2 = "abcabcbb";
    std::string s3 = "pwwkew";
    std::string s4 = "a";
    std::string s5 = "";
    std::string s6 = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
;
    std::cout << s1 << ':' << s.lengthOfLongestSubstring(s1) << '\n'
        << s2 << ':' << s.lengthOfLongestSubstring(s2) << '\n'
        << s3 << ':' << s.lengthOfLongestSubstring(s3) << '\n'
        << s4 << ':' << s.lengthOfLongestSubstring(s4) << '\n'
        << s5 << ':' << s.lengthOfLongestSubstring(s5) << '\n'
        << s6 << ':' << s.lengthOfLongestSubstring(s6) << '\n';
    
    return 0;
}