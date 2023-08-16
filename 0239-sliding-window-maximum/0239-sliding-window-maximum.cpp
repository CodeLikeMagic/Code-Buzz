class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          deque<pair<int, int>> dq;   //store elements of current window
        vector<int> answer;
        
        for(int i=0; i<nums.size(); ++i){
            
            if(!dq.empty() && dq.front().second <= (i-k)){  //remove front element if it goes out of window size //keeping relevant
                dq.pop_front();
            }
            
            while(!dq.empty() && dq.back().first < nums[i]) //maintaing DESC order
            {
                dq.pop_back();
            }
            dq.push_back(make_pair(nums[i], i));    //adding in right place
            
            if(i >= (k -1)){ ///current max for window
                answer.push_back(dq.front().first); //inc max of current window
            }
        }
        
        
        return answer;
    }
};