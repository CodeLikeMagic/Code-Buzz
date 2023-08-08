class Solution {
public:
    int bs(vector<int>& nums,int start,int end, int target){
        
        int mid = 0 , result = -1;
       
        while(start <= end){
            
            mid = start + (end - start)/2;
            
            if(nums[mid] == target){
                result = mid;
                break;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
    
    void Number_of_Rotations(vector<int> arr, int N, int &result)
    {
        int next, prev, start, end, mid;

        start = 0;
        end = N - 1;

        if(arr[start] < arr[end])
        {
            result = start;
            return;
        }
        while(start <= end)
        {

            if(arr[start] <= arr[end])
            {
                result = start;
                break;
            }
            mid = start + (end - start)/2;

            cout<<" mid : "<<mid<<endl;
            next = (mid + 1)%N;
            prev = (mid + N - 1)%N;

            cout<<" p : "<<prev<<" n : "<<next<<endl;

            if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])  ///that minimum element is always in unsorted part   jo previous aur next dono se small ho
            {
                result = mid;
                break;
            }

            ///other
            if(arr[start] <= arr[mid])  ///if it is that means that array is in sorted order of that portion then
            ///Portion - 1 is Sorted                ///move to another portion and repeat process
            {
                cout<<" P - 1 "<<endl;
                start = mid + 1;
            }

            else if(arr[mid] <= arr[end])   ///Portion - 2 is Sorted
            {
                cout<<" P - 2 "<<endl;
                end = mid - 1;
            }
        }///while
    }
    
    int search(vector<int>& nums, int target) {
    
        int result = -1;

        if(nums.size() == 1 && nums[0] == target){
            return 0;    
        }else if(nums.size() == 1 && nums[0] != target){
            return -1;
        }
        
        Number_of_Rotations(nums, nums.size(), result);
        
        cout<<result<<endl;
        if(nums[result] == target){
            return result;
        }
        int x = bs(nums, 0, result, target);
        int y = bs(nums, result+1, nums.size()-1, target);
        
        if(x == -1 && y == -1){
            return -1;
        }
        if(x != -1){
            result = x;
        }
        if(y != -1){
            result = y;
        }
        return result;
    }
};