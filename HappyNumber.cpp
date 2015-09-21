class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
		int result = 0;
		while (n)
		{
			int rem = n % 10;
			result += rem * rem;
			n /= 10;
		}
		if (result == 1)	return true;
		if (result < 10)    return false;
		return isHappy(result);
    }
};