// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       int begin = 1, end = n;
       while (begin <= end) {
          if (begin == end && isBadVersion(begin))   return begin;
          int mid = begin + (end - begin) / 2;
          if (isBadVersion(mid))   end = mid - 1;
          else   begin = mid + 1;
       }
    }
};
