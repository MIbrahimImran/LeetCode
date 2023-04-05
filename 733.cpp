/* 733. Flood Fill */

class Solution {
public:
    // Time: O(n) && Space: O(1)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fillImage(sr, sc, image[sr][sc], color, image);
        return image;
    }

    void fillImage(int row, int col, int startColor, int paintColor, vector<vector<int>>& matrix) {
        if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[row].size()) return;
        if(matrix[row][col] != startColor || matrix[row][col] == paintColor) return;
        matrix[row][col] = paintColor;
        fillImage(row + 1, col, startColor, paintColor, matrix);
        fillImage(row - 1, col, startColor, paintColor, matrix);
        fillImage(row, col + 1, startColor, paintColor, matrix);
        fillImage(row, col - 1, startColor, paintColor, matrix);
    }
};