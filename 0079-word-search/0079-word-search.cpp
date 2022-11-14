class Solution {
public:
    int dx[4] = {1, -1, 0 , 0};
    int dy[4] = {0, 0, 1 , -1};
    
    bool dfs(int i, int j, int index, vector<vector<char>>& board, string word,
    int row, int cols, vector<vector<int>>& Vboard         
    ){
        ///index tracks how many letters were matched
        if(index == word.size()){
            return true;
        }
        
        if(i < 0 || j < 0 || i >= row || j >= cols){
            return false;
        }
        if(word[index] != board[i][j]){
            return false;
        }
        ///if its visited
        if(Vboard[i][j] == 1){
            return false;
        }
        
        Vboard[i][j] = 1;
        
        for(int k=0; k<4; k++){
            
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(dfs(ni, nj, index+1, board, word, row, cols, Vboard)){
                return true;
            }
        }
        
        Vboard[i][j] = 0;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        ///track visited 
        vector<vector<int>> Vboard(rows, vector<int>(cols, 0));
        
        for(int i=0; i<rows; i++){
            
            for(int j = 0; j<cols; j++){
                 if(board[i][j] == word[0]
                   &&
                   dfs(i, j, 0, board, word, rows, cols, Vboard)){
                     return true;
                 }
            }
        }
        
        return false;
    }
};