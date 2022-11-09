class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        
        if(i<0 || j<0 || i==m || j==n || grid[i][j] == '0'){
            return;
        }
        
        grid[i][j]='0';
        
        dfs(grid, i+1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i-1, j, m, n);
        
        return;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == '1'){
                    ///incrementing count of islands as soon as we encounter 1 and its island companions are made 0 using dfs so to avoid confusion
                    res++;  ///island count
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return res;
    }
};