class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;  //min heap
        vector<int> temp;
        
        int k, steps = 0;
        
        for(auto i : nums){
            pq.push(i);            
        }
        
        
        while(!pq.empty()){
            
            if(pq.top() == 0){
                pq.pop();
                continue;
            }   //remove zeros not needed
            
            k = pq.top();
            pq.pop();
            
            while(!pq.empty()){
                //manipulation
                int x = pq.top();
                temp.push_back(x - k);
                pq.pop();                
            }
            steps++;
            //temp se min heap me copy
            for(auto i : temp){
                pq.push(i);               
            }
            
            temp.clear();
        }
        
        return steps;
    }
};