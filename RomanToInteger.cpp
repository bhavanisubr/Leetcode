class Solution {
public:
    int romanToInt(string s) 
    {
        map<char, int> romanToIntMap;
	romanToIntMap['I'] = 1;
	romanToIntMap['V'] = 5;
	romanToIntMap['X'] = 10;
	romanToIntMap['L'] = 50;
	romanToIntMap['C'] = 100;
	romanToIntMap['D'] = 500;
	romanToIntMap['M'] = 1000;

	int total = romanToIntMap.find(s.back())->second;
	for (int i = s.length() - 2; i >= 0; i--)
	{
		int currentNum = romanToIntMap.find(s[i])->second;
		int nextNum = romanToIntMap.find(s[i + 1])->second;
		total = currentNum >= nextNum ? total + currentNum : total - currentNum;
	}
	return total;
    }
};
