class Solution {
public:
    int minOperations(vector<int>& a) {
        /*
        [0 0 1]
        1 1 0
        0 0 0 0 1 1 1 1 1 1
        0 0 1 
        1 0 0 1 1 0
        
        0 0 0) (0 0 0) (0 0 0
        1 1 1 1 1 1 0 0 0
        
        0 0 1 1 1 1 1 1 0 1 --> 7 
        1 1 1 1 1 1 0 0 0
        4
        
        1 1 1 1 1 1 0 0 0 1 -->
        
        0 1 1 1 1 1 1 0 0 1
        1 1 1 1 1 1 0
        3 1s --> 2 steps ! 
        4
        
        [1,0,0,1,1,0,1,1,1,0,0,0,1,0,1]
           1 1 1 1 1 1 1 1 1 1 0 0  0
        
        */
        int n=a.size(),ans=0;
        for(int i=0;i<n - 2;i++){
            if(a[i] == 0){
                a[i] = 1 - a[i];
                a[i + 1] = 1 - a[i + 1];
                a[i + 2] = 1 - a[i + 2];
                ++ans;
            }
        }
        int c= a[n-1]+ a[n-2]+a[n-3];
        
        return c%3 ? -1 : (c==0 ? ans+1 : ans);
    }
};