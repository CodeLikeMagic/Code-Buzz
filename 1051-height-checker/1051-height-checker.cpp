class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ex(heights.begin(), heights.end());
        
        sort(ex.begin(), ex.end());
        int d = 0;
        
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != ex[i]){
                d++;
            }
        }
        
        return d;
    }
};