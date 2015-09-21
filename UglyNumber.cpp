class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)   return false;
        if (num == 1)   return true;
        int factors[3] = {2, 3, 5};
        for (int i = 0; i < 3; i++)
        {
            if (num % factors[i] == 0)
            {
                num /= factors[i];
                return isUgly(num);
            }
        }
        return false;
    }
};