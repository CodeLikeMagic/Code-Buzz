class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n, m;
        
        n = matrix.size();
        m = matrix[0].size();
        
        vector<vector<int>> vec(m, vector<int> (n, 0));
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
             
                vec[j][i] = matrix[i][j];
            }
        }
        
        return vec;
    }
};