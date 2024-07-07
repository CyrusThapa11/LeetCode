class Solution {
public:
    #define ll long long
    long long maximumPoints(vector<int>& ee, int ce) {
        sort(begin(ee),end(ee));
        ll i=0,n=ee.size()-1,ans=0,pt=0;
        
        while(i <= n && n>=0){
            if(ee[i] > ce){
                if(!pt)return pt;
                ce+=ee[n];
                --n;
            }else{
                // ce -= ee[i++];
                ll N = ce/ee[i];
                pt += N;
                ce -= (ee[i]*N);
            }
        }
        return pt;
    }
};