class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        
        double answer = 0;
        //cout<<accumulate(salary.begin()+1, salary.end()-1, 0.0)/(salary.size()-2);
        answer = accumulate(salary.begin()+1, salary.end()-1, 0.0)/(salary.size()-2);
        return answer;
    }
};