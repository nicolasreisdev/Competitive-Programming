
// prefixSum 1D 


class NumMatrix {
private:
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefixSum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size();i++){
            prefixSum[i][0] = matrix[i][0];
            for(int j = 1; j < matrix[i].size();j++){
                prefixSum[i][j] = prefixSum[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 > 0) ans += prefixSum[i][col2] - prefixSum[i][col1-1];
            else ans += prefixSum[i][col2];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

 // prefixSum 2D


 class NumMatrix {
private:
    vector<vector<int>> sumMat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        sumMat = vector<vector<int>>(ROWS + 1, vector<int>(COLS + 1, 0));

        for (int r = 0; r < ROWS; r++) {
            int prefix = 0;
            for (int c = 0; c < COLS; c++) {
                prefix += matrix[r][c];
                int above = sumMat[r][c + 1];
                sumMat[r + 1][c + 1] = prefix + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int bottomRight = sumMat[row2][col2];
        int above = sumMat[row1 - 1][col2];
        int left = sumMat[row2][col1 - 1];
        int topLeft = sumMat[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};