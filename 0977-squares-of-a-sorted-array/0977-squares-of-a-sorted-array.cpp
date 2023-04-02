class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        
        for(auto x : nums){
            answer.push_back(x*x);
        }
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};