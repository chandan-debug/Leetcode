class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        map<int,int> mrow;
        map<int,int> mcol;
        int row = mat.size();
        int col = mat[0].size();

        for (int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if (mat[i][j] == 1){
                    mrow[i]++;
                    mcol[j]++;
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if (mat[i][j] == 1 && mrow[i] == 1 && mcol[j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};