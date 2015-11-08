/**
 * Given n non-negative integers a1, a2, ..., an, where each integer represents a point at coordinate (i, ai). n 
 * vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
 * together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container. 
 */

class Solution {
public:
  int maxArea(vector<int>& height) {
    if (height.size() <= 1)  return 0;
    int maxAreaSoFar = 0;
    for (int begin = 0, end = height.size() - 1; begin < end; ) {
      maxAreaSoFar = max(maxAreaSoFar, min(height[begin], height[end]) * (end - begin));
      if (height[begin] < height[end])  ++begin;
      else  --end;
    }
    return maxAreaSoFar;
  }
};
