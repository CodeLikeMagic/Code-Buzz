class Solution {
    public int jump(int[] arr) {
        if(arr.length<=1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int ladder=arr[0]; //keep track of largest ladder that you have
        int stairs=arr[0]; //keep track of stairs in the current ladder
        int jump=1;
        for(int level=1;level<arr.length;level++){
            if(level==arr.length-1){
                return jump;
            }
            if(level+arr[level]>ladder){
                ladder=level+arr[level]; //build up the ladder
            }
            stairs--;
            if(stairs==0){
                jump++; //no stairs left,now jump
                if(level>=ladder){
                    return -1;
                }
                stairs=ladder-level; //now get new set of stairs
            }
        }
        return jump;
    }
}