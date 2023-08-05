class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();  // no.of row
        int m=matrix[0].size();  // no. of col
        vector<int> rowarray(n,1);
        vector<int> colarray(m,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rowarray[i]=0;
                    colarray[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rowarray[i]==0 || colarray[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};