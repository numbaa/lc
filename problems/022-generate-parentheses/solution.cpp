#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {

    vector<string> gp_aux(const string& prefix, int left, int nlp)
    {
        vector<string> result;
        if (left == 0 && nlp == 0)
            return {prefix};
        if (left != 0)
        {
            string pref = prefix;
            pref.push_back('(');
            vector<string> tmp = gp_aux(pref, left-1, nlp+1);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        if (nlp != 0)
        {
            string pref = prefix;
            pref.push_back(')');
            vector<string> tmp = gp_aux(pref, left, nlp-1);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        return result;
    }

public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        return gp_aux("", n, 0);
    }
};


int main()
{
    Solution s;
    auto result = s.generateParenthesis(3);
    for (auto& item : result)
        cout << item << '\n';
    return 0;
}
