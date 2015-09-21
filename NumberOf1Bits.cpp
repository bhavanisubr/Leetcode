class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneCount = 0;
        for (int i = 0; i < 32; i++)
            if (n & (1 << i))   ++oneCount;
        return oneCount;
    }
};