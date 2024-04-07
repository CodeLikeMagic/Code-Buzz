class Solution {
public:
    void solve(vector<int>& nums, int start, vector<vector<int>> &result){
        
        if(start == nums.size()){
            result.push_back(nums);
        }
        
        unordered_set<char> mp;
        
        for(int i=start; i<nums.size(); i++){
            
            if(mp.find(nums[i]) == mp.end()){
                mp.insert(nums[i]); //keep distinct 
                
                swap(nums[start], nums[i]); //make changes
                
                solve(nums, start+1, result);   //rc
                
                swap(nums[start], nums[i]); //backtrack
            }           
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<vector<int>> result;
        
        solve(nums, 0, result);
        
        return result;
    }
};