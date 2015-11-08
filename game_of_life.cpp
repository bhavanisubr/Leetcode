/**
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton 
 * devised by the British mathematician John Horton Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with 
 * its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia 
 * article):
 *  
 * Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 *
 * Write a function to compute the next state (after one update) of the board given its current state.
 */

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    vector<pair<int, int>> changedCoordinates;
    for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
        int neighbors = 0;
        if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1])  ++neighbors;
        if (x - 1 >= 0 && board[x - 1][y])  ++neighbors;
        if (x - 1 >= 0 && y + 1 < cols && board[x - 1][y + 1])  ++neighbors;
        if (y - 1 >= 0 && board[x][y - 1])  ++neighbors;
        if (y + 1 < cols && board[x][y + 1])  ++neighbors;
        if (x + 1 < rows && y - 1 >= 0 && board[x + 1][y - 1])  ++neighbors;
        if (x + 1 < rows && board[x + 1][y])  ++neighbors;
        if (x + 1 < rows && y + 1 < cols && board[x + 1][y + 1])  ++neighbors;
        if ((board[x][y] && (neighbors < 2 || neighbors > 3)) || (!board[x][y] && neighbors == 3))
          changedCoordinates.push_back(make_pair(x, y));
      }
    }
    for (auto it : changedCoordinates) {
      int x = it.first;
      int y = it.second;
      board[x][y] = board[x][y] ? 0 : 1;
    }
  }
};
