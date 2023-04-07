class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    void solve(vector<vector<int>>& image, int sr, int sc, int px, int color){
        
        int R = image.size();
        int C = image[0].size();
        if(sr<0 || sc<0|| sr>=R|| sc >=C){
            return;
        }
        
        if(image[sr][sc] != px || image[sr][sc] == color){
            return;
        }
        
        image[sr][sc] = color;
        
        for(int k=0; k<4; k++){
            cout<<sr<<" "<<sc<<endl;
            solve(image, sr+dx[k], sc+dy[k], px, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
         int px = image[sr][sc];
        
        solve(image, sr, sc, px, color);
        return image;    
    
    }
};