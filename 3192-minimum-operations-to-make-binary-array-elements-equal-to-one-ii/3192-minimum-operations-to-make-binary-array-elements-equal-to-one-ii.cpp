class Solution {
public:
    int minOperations(vector<int>& a) {
        int ans=0;
        int t=0;
        for(int x:a){
            if(( t&1 && x == 1) || (!(t&1) && x==0)){
                ++ans;
                t++;
            }
        }
        return ans;
        /*
        t&1 ? 1-->0 , 0-->1
        !(t&1) ? 1-->1 , 0 --> 0 
        */
    }
};