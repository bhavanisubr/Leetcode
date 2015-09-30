/**
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that 
 * nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int, vector<int> > numsMap;
       for (int i = 0; i < nums.size(); i++)   numsMap[nums[i]].push_back(i);
       for (auto it = numsMap.begin(); it != numsMap.end(); it++) {
          vector<int> temp = it->second;
          if (temp.size() >= 2) {
             for (int i = 0; i < temp.size() - 1; i++)
                if (temp[i + 1] - temp[i] <= k)   return true;
          }
       }
       return false;
    }
};