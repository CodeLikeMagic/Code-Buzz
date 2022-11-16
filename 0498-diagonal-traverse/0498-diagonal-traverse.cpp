class Solution {
public:
    
    /*
    3x3
    00 01 02
    10 11 12
    20 21 22
    
    00 --- 01 10 --- 20 11 02 --- 12 21 --- 22 
    */
    
    // Intuition : Sum of indexes of Diagonal Elements of a matrix are same
// The even sum indexes are in reverse order and odd ones are in normal order
    
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        map<int, vector<int>> traversal;
        
        for(int i=0; i<mat.size(); i++){
            
            for(int j=0; j<mat[0].size(); j++){
                
                int sum = i+j;
                traversal[sum].push_back(mat[i][j]);
            }            
        }
        
        vector<int> ans;
        
        for(auto i : traversal){
            
            if(i.first % 2 == 0){
                
               // even index elements are in reverse order
               for(int x = i.second.size()-1; x>= 0; x--){
                   ans.push_back(i.second[x]);
               }
            }
            else{
             
               // odd index elements are in normal order 
               for(int x =0; x<i.second.size(); x++){
                   ans.push_back(i.second[x]);
               } 
            }            
        }
        
        return ans;
    }
};