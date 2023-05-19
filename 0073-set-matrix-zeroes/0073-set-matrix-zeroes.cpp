class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();  // Number of rows
    int m = matrix[0].size();  // Number of columns

    vector<int> rowArray(n, 1);  // Initialize a vector to track zero rows
    vector<int> colArray(m, 1);  // Initialize a vector to track zero columns

    // Step 1: Traverse the matrix and mark the zero rows and columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                rowArray[i] = 0;  // Mark the row as zero
                colArray[j] = 0;  // Mark the column as zero
            }
        }
    }

    // Step 2: Modify the matrix based on the marked zero rows and columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (colArray[j] == 0 || rowArray[i] == 0) {
                matrix[i][j] = 0;  // Set the element to zero if the row or column is marked as zero
            }
        }
    }
}

};