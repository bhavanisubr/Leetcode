class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> outputIndices;
		map<int, int> numsMap;
		for (int i = 0; i < nums.size(); i++)
			numsMap[nums[i]] = i;
		for (int i = 0; i < nums.size(); i++)
		{
			int curValComplement = target - nums[i];
			auto it = numsMap.find(curValComplement);
			if (it != numsMap.end() && it->second != i)	
			{
				outputIndices.push_back(i + 1);
				outputIndices.push_back(it->second + 1);
				return outputIndices;
			}
		}
		return outputIndices;
    }
};