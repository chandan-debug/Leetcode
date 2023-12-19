class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int row = img.size(), col = img[0].size();
        vector<vector<int>>ans(row, vector<int>(col, 0));
        int x[9] = {0,-1, 0, 1, 1, 1, 0,-1,-1};
        int y[9] = {0,-1,-1,-1, 0, 1, 1, 1, 0};

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int sum = 0, count = 0;
                for(int k = 0; k < 9; k++){
                    int newR = i + y[k];
                    int newC = j + x[k];

                    if(newR >= 0 && newR < row && newC >= 0 && newC < col){
                        count++;
                        sum += img[newR][newC];
                    }
                }
                ans[i][j] = sum/count;
            }
        }

        return ans;

        
    }
};