class Solution {
public:
    int lenOfLongSubarr(vector<int>& A, int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> m;
        int sum = K;
        int pre_sum = 0, res = 0;
        for(int i = 0; i<N; i++){
            
            pre_sum += A[i];
            
            //if sum index starts with 0th index
            if(pre_sum == sum){
                res = i+1;
            }
            
            if(m.find(pre_sum) == m.end()){
                m.insert({pre_sum, i});
                //add if tha sum is not present and left most index is stored
            }
            
            if(m.find(pre_sum - sum)!=m.end()){
                //if present calc whose index range is greater store that
                res = max(res, i - m[pre_sum - sum]);
            }
        }
        return res;
    } 
    
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }//replace values
        
        int answer = lenOfLongSubarr(nums, nums.size(), 0);
        return answer;
    }
};