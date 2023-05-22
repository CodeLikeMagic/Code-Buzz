class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        
        for(auto p : um){            
            pq.push({p.second, p.first});
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};