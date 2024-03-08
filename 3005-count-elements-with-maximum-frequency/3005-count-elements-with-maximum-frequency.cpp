class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq, totalFreq = 0;
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        
        for(auto x: freq){
            pq.push(make_pair(x.second, x.first));
        }
        maxFreq = pq.top().first;
        
        while(!pq.empty()){
            auto x = pq.top();
            if(maxFreq == x.first){
                totalFreq += maxFreq;
            }else{
                break;
            }
            pq.pop();
        }
        return totalFreq;
    }
};