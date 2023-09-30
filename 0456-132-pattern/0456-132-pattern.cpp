class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //min - mins array
        //max - j iterate
        //mid - stack
        
        int mins[nums.size()];
        mins[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            mins[i] = min(mins[i-1], nums[i]);
        }//min array
        
        stack<int> st;
        bool found = false;
        
        for(int j=nums.size() - 1; j>=0; j--){
            
            while(st.size() > 0 && st.top() <= mins[j]){
                st.pop();
            }
            if(st.size() > 0 && st.top() < nums[j]){
                found = true;
                break;
            }
            st.push(nums[j]);
        }
        return found;
    }
};