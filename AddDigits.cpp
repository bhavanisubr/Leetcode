class Solution {
public:
    int addDigits(int num) {
        /* Trivial solution:
        int sum = 0;
	while (num) {
           sum += num % 10;
           num /= 10;
	}
	if (sum >= 10)   return addDigits(sum);
	return sum; */
	
	// O(1) time solution:
	return (1 + ((num - 1) % 9));
    }
};
