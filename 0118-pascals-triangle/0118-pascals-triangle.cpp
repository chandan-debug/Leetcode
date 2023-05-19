class Solution {
public:
   vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows);  // Initialize a 2D vector to store the triangle

    // Step 1: Iterate over the number of rows
    for (int i = 0; i < numRows; i++) {
        r[i].resize(i + 1);  // Resize the current row vector to have (i+1) elements
        r[i][0] = r[i][i] = 1;  // Set the first and last elements of the row to 1

        // Step 2: Calculate the values for the current row
        for (int j = 1; j < i; j++) {
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];  // Calculate the current element by summing the two elements above it
        }
    }

    return r;  // Return the generated Pascal's triangle
}

};