class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
     
        if(ind == arr.size()){
            //iterated all possible
            if(target == 0){
                ans.push_back(ds); //stack call possible answer
            }
            //if not 0
            return; ///trackback
        }///base condition
        
        if(arr[ind] <= target){
            
            ds.push_back(arr[ind]);//visit push
            
            findCombination(ind, target-arr[ind], arr, ans, ds);                
            ds.pop_back();  ///backtrack pop
        }
        
        findCombination(ind+1, target, arr, ans, ds);
        
    }    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> ds;
        
        findCombination(0, target, candidates, ans, ds);
        ///target -> sum
        ///given ans
        ///ans -> to store results
        ///ds -> stack call / possible answers
        return ans;
    }
};