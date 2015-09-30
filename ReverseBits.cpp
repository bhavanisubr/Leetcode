/**
 * Reverse bits of a given 32 bit unsigned integer.
 * For example: Given input 43261596 (represented in binary as 00000010100101000001111010011100), 
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t output = 0;
       for (int i = 0, j = 31; i < 32 && j >= 0; i++, j--) {
          int mask = 1 << i;
          if (n & mask)   output += pow(2, j);
       }
       return output;
    }
};