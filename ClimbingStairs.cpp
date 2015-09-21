class Solution {
public:
    int climbStairs(int n) {
        map<int, int> numWaysMap;
	numWaysMap[0] = 1;
	numWaysMap[1] = 1;
	for (int i = 2; i <= n; i++)
		numWaysMap[i] = numWaysMap[i - 1] + numWaysMap[i - 2];
	return numWaysMap[n];
    }
};
