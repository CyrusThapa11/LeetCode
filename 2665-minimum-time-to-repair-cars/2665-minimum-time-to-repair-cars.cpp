class Solution {
public:
    #define ll long long 
    bool ok (ll t,vector<int>&a,int c) {
        for(int x:a) {
            int curr = 0;
            while( ( (curr + 1)*1ll * (curr + 1) * x ) <= t * 1ll) {
                ++curr;
            }
            c-=curr;
            if(c<=0ll)return 1;
        }
        return 0;
    }
    long long repairCars(vector<int>& r, int c) {
        sort(begin(r),end(r));
        int n =r.size();
        ll lo=1,hi=c*r[n-1] * 1ll * c,ans=c * 1ll*r[n-1] * c;
        while(lo<=hi){
            ll mid = (hi + lo)/2;
            if(ok(mid,r,c)) {
                ans=mid;
                hi=mid-1;
            }else {
                lo=mid+1;
            }
        }
        return ans;
    }
};