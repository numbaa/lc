#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> table {
    "", "", //0, 1
    "abc",  "def", "ghi", //2,3,4
    "jkl", "mno", "pqrs", //5,6,7
    "tuv", "wxyz"}; //8,9

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        return comb("", digits); //TODO: use string_view
    }

    vector<string> comb(const string& prefix, const string& num)
    {
        if (num.size() == 0) return {prefix};
        vector<string> result;
        char n = num[0];
        string new_num = num.substr(1);
        for (char c : table[n-'0'])
        {
            string new_prefix = prefix;
            new_prefix.push_back(c);
            auto tmp = comb(new_prefix, new_num);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        return std::move(result);
    }

};


int main()
{
    string num = "23";
    Solution s;
    auto result = s.letterCombinations(num);
    std::cout << '[';
    for (auto& item : result)
        std::cout << item << ',';
    std::cout << "]\n";
    return 0;
}
