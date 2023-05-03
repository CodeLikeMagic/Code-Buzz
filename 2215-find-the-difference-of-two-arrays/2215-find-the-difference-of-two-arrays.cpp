class Solution {
public:
    vector<int> makeDistinct(vector<int>& nums1, vector<int>& nums2){
        
        unordered_set<int> onlyInF;
        unordered_set<int> onlyInS;
        
        for(int num: nums2){
            onlyInS.insert(num);
        }
        
        for(int num: nums1){ ///if that element isn't in second
            if(onlyInS.find(num) == onlyInS.end()){
                onlyInF.insert(num);
            }            
        }
        
        return vector<int> (onlyInF.begin(), onlyInF.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> answer;
        
        vector<int> a1 = makeDistinct(nums1, nums2);
        vector<int> a2 = makeDistinct(nums2, nums1);
        
        answer.push_back(a1);
        answer.push_back(a2);
        
        return answer;
    }
};