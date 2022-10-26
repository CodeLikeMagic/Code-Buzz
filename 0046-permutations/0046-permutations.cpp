class Solution {
public:
    void func(int index, vector<int>& nums, vector<vector<int>> &answer)
    {
        if(index == nums.size())
        {
            answer.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
             swap(nums[index], nums[i]);    //swap
             func(index+1,nums,answer);
             swap(nums[i], nums[index]);    //reswap backtrack
        }
    }   
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        func(0, nums, answer);
        return answer;
    }
};