class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

    uint32_t newN = 0;
    uint32_t j = 0;
    bool flag = false;

    for(int i=31; i>=0; i--){

        int mask = (1 << i); ///check 1 or 0

        if(flag){

            if((n & mask) != 0){
            //    cout<<"1";

                uint32_t nmask = (1 << j);
                newN |= nmask;  ///or to make new number

            }else{
               // cout<<"0";
            }
            j++;
        }else{

            if((n & mask) != 0){
                flag = true;    ///first 1
             //   cout<<"1";
                uint32_t nmask = (1 << j);
                newN |= nmask;

            }else{
            }
            j++;
        }
    }

    //cout<<"\n"<<n<<" : "<<newN<<endl;
    return newN;
    }
};