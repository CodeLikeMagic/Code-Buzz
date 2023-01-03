#include<bits/stdc++.h>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       // track last two fruits seen
        int lastFruit = -1;
        int secondLastFruit = -1;
        int lastFruitCount = 0;
        int currMax = 0;
        int maxv = 0;
        
        for (int fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit)
                currMax++;
            else
                currMax = lastFruitCount + 1; // last fruit + new fruit
            
            if (fruit == lastFruit)
                lastFruitCount++;
            else
                lastFruitCount = 1; 
            
            if (fruit != lastFruit) {
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
            
            maxv = max(maxv, currMax);
        }
        
        return maxv;
    }
};