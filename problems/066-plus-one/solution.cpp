class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int count = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			digits[i] += count;
			if (digits[i] >= 10)
			{
				digits[i] -= 10;
				count = 1;
			}
			else
			{
				count = 0;
			}
		}
		if (count == 1)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};
