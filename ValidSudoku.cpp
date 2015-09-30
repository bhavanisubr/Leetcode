/**
 * Determine if a Sudoku is valid. The Sudoku board could be partially filled, where empty cells are filled with the character '.'
 * 
 * Note: A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSubBoard(vector<vector<char> >& board, int beginRow, int endRow, int beginCol, int endCol) {
       map<char, bool> numsMap;
       for (char i = '1'; i <= '9'; i++)   numsMap[i] = false;
       for (int i = beginRow; i <= endRow; i++) {
          for (int j = beginCol; j <= endCol; j++) {
             if (board[i][j] != '.') {
                if (numsMap[board[i][j]])   return false;
                numsMap[board[i][j]] = true;
             }
          }
       }
       return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
       for (int i = 0; i <= 8; i++)
          if (!isValidSubBoard(board, i, i, 0, 8))   return false;
       for (int i = 0; i <= 8; i++)
          if (!isValidSubBoard(board, 0, 8, i, i))   return false;
       for (int rowBegin = 0, rowEnd = 2; rowBegin <= 6 && rowEnd <= 8; rowBegin += 3, rowEnd += 3) {
          for (int colBegin = 0, colEnd = 2; colBegin <= 6 && colEnd <= 8; colBegin += 3, colEnd += 3)
             if (!isValidSubBoard(board, rowBegin, rowEnd, colBegin, colEnd))   return false;
       }
       return true;
    }
};