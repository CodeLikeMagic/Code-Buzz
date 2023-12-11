class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int threshold = arr.size() / 4;
        
        for(int i=0; i < arr.size() - threshold; i++){
            
            if(arr[i] == arr[i + threshold]){
                return arr[i];
            }
            
        }
        return -1;
    }
};