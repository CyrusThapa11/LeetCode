class Solution {
public:
    
    vector<int>getPrimes(int n) {
        //debug("here");
        int lim = 2e5 + 100;
        int a[lim];
        memset(a, 1, sizeof a);
        a[1] = 0;
        for (int i = 2; i < lim; ++i)
        {
            if (a[i]) {
                for (int j = 2 * i; j < lim; j += i)
                {
                    a[j] = 0;
                }
            }
        }
        vector<int>p;
        for (int i = 2; i < lim; ++i)
        {
            if (a[i])p.push_back(i);
        }
        // debug(p);
        return p;
    }

    int nonSpecialCount(int l, int r) {
        /*
        9 -> 1, 3
        25->1,5
        */
        vector<int>a;
        vector<int>b=getPrimes(r+1);
        for(int x:b){
            if(x*x>r)break;
            a.push_back(x*x);
        }
        int L=upper_bound(a.begin(),a.end(),r)-a.begin();
        if(L!=0)--L;
        int R=lower_bound(a.begin(),a.end(),l)-a.begin();
        // if(L!=0)--L;
        if(a.size()==0){
            return r-l+1;
        }
        // for(int x:a)cout<<x<<" ";
        // cout<<endl;
        // cout<<L<<"-"<<R<<endl;
        int cnt=(L-R+1);
        return (r-l+1-cnt);
    }
};