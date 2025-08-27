class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
    if (mat.empty() || mat[0].empty()) return ans;
    
    int rowStart = 0, rowEnd = mat.size() - 1;
    int colStart = 0, colEnd = mat[0].size() - 1;
    
    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Traverse right
        for (int i = colStart; i <= colEnd; i++) {
            ans.push_back(mat[rowStart][i]);
        }
        rowStart++;
        
        // Traverse down
        for (int i = rowStart; i <= rowEnd; i++) {
            ans.push_back(mat[i][colEnd]);
        }
        colEnd--;
        
        if (rowStart <= rowEnd) {
            // Traverse left
            for (int i = colEnd; i >= colStart; i--) {
                ans.push_back(mat[rowEnd][i]);
            }
            rowEnd--;
        }
        
        if (colStart <= colEnd) {
            // Traverse up
            for (int i = rowEnd; i >= rowStart; i--) {
                ans.push_back(mat[i][colStart]);
            }
            colStart++;
        }
    }
    return ans;
    }
};