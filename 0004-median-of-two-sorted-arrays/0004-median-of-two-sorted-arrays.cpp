class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      priority_queue<int, vector<int>, greater<int>> pq;
        int i=0, j=0;
        for(i=0, j=0; i < nums1.size() && j < nums2.size(); i++, j++){
            pq.push(nums1[i]);
            pq.push(nums2[j]);
        }
        if(i < nums1.size()){
            while(i != nums1.size()){
                pq.push(nums1[i]);
                i++;    
            }
        }
        
        if(j < nums2.size()){
            while(j != nums2.size()){
                pq.push(nums2[j]);
                j++;    
            }
        }
        
        if(pq.size()%2 != 0){
            int s = pq.size()/2;
            while(s--){
                pq.pop();
            }
            return pq.top();
        }
        else{
            int prev = 0;
            int s = pq.size()/2;
            while(s--){
                prev = pq.top();
                pq.pop();
            }
            cout<<prev<<" "<<pq.top();
            return (double)(prev + pq.top())/2;
        }  
    }
};