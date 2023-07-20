class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for(int i=0; i<asteroids.size(); i++){
            
            if(asteroids[i] > 0){//----> right
                st.push(asteroids[i]);
            }
            else{ //<----- left , negative value
                
                while(st.size() > 0 &&st.top() > 0 && st.top() < -asteroids[i]){
                    st.pop();   //when smaller - greater values collide
                }
                if(st.size() > 0 && st.top() == -asteroids[i]){
                    st.pop();
                }
                else if(st.size() > 0 && st.top() > -asteroids[i]){
                    
                }
                else{
                    st.push(asteroids[i]);   //takes over    
                }     
            }
        }
        
        int m = st.size();
        vector<int> answer(m);
        
        for(int i=m-1; i>=0; i--){
            answer[i] = st.top();
            st.pop();
        }
        
        return answer;
    }
};