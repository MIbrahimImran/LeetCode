/* 463. Island Perimeter */

class Solution1 {
public:
    // Time: O(n + m) && Space: O(1)
    int islandPerimeter(vector<vector<int>>& matrix) {
        int perimeter = 0;
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[row].size(); col++) {
                if(matrix[row][col]) {
                    int boxPerimeter = 4;
                    if(row > 0 && matrix[row - 1][col]) boxPerimeter--;
                    if(col > 0 && matrix[row][col - 1]) boxPerimeter--;
                    if(row < matrix.size() - 1 && matrix[row + 1][col]) boxPerimeter--;
                    if(col < matrix[row].size() - 1 && matrix[row][col + 1]) boxPerimeter--;
                    perimeter += boxPerimeter;
                }
            }
        }

        return perimeter;
    }
};


class Solution2 {
public:
    // Time: O(n + m) && Space: O(1)
    int islandPerimeter(vector<vector<int>>& matrix) {
        int perimeter = 0;
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[row].size(); col++) {
                if(matrix[row][col]) {
                    int boxPerimeter = 4;
                    if(row > 0 && matrix[row - 1][col]) boxPerimeter--;
                    if(col > 0 && matrix[row][col - 1]) boxPerimeter--;
                    if(row < matrix.size() - 1 && matrix[row + 1][col]) boxPerimeter--;
                    if(col < matrix[row].size() - 1 && matrix[row][col + 1]) boxPerimeter--;
                    perimeter += boxPerimeter;
                }
            }
        }

        return perimeter;
    }
};