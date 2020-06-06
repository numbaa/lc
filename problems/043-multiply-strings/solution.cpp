#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int count = 0;
        string result(num1.size() * num2.size() + 1, '0');
        for (int i=0; i<num2.size(); i++)
        {
            int count = 0;
            for (int j=0; j<num1.size(); j++)
            {
                int m = (num2[num2.size()-i-1]-'0') * (num1[num1.size()-j-1]-'0') + count + result[i+j]-'0';
                if (m < 10)
                {
                    result[i+j] = m + '0';
                    count = 0;
                }
                else
                {
                    result[i+j] = m % 10 + '0';
                    count = m / 10;
                }
            }
            if (count != 0) result[i+num1.size()] = count + '0';
        }
        int k = result.size() - 1;
        while (k >= 0 && result[k] == '0') k--;
        return k < 0 ? "0" : string{ result.rbegin()+(result.size()-k-1), result.rend()};
    }
};

int main()
{
    Solution s;
    cout << s.multiply("9", "9") << endl;
    return 0;
}