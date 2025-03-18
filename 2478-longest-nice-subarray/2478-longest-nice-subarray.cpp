class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        int n = a.size(),ans=0;
  
        int st = 0 , ed = 0 ;
        vector<int>t(31,0);
        for(int end = 0;end < n; end++) {
            int num = a[end],j = 0;
            bool ok = 1;
            while(num) {
                t[j] += num&1;
                if(t[j++] > 1)ok=0;
                num/=2;
            }
            if(!ok) {
                ok= 0;
                while(st < end && !ok) {
                    num = a[st++],j=0;
                    ok=1;
                    while(j < 30) {
                        t[j] -= num&1;
                        if(t[j++] > 1)ok=0;
                        num/=2;
                    }
                    if(ok) {
                        // cout<<endl<<" t idx "<< end << " "<<endl;
                        // for(int x:t)cout<<x<<" , ";
                        // cout<<endl;
                    }
                }
            }
            if(ok){
                ans=max(ans,end - st + 1);
                cout<< ans <<  " "<<end<<" , " << st<<endl;
            }
        }
        return ans;
    }
};