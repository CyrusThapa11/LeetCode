class Solution {
public:
    #define ll long long 
    ll dp[(ll)1e5 + 1][2];
    ll go(vector<int>&a,int pos,ll &n,int take,int par){
        // if(pos>=n)return -1e9;
        if(dp[pos][par]!=-1)return dp[pos][par];
        
        ll a1= a[pos] * (par&1 ? -1:1) + (pos!=n-1 ? go(a,pos+1,n,take,1^par):0);
        ll a2= a[pos] + (pos!=n-1?go(a,pos+1,n,take,0):0);
        
        return dp[pos][par]=max(a1,a2);
    }
    
    long long maximumTotalCost(vector<int>&a) {
        
        ll ans=-1e18,n=a.size(),mx=0,last=0;
        if(n==1)return a[0];
        memset(dp,-1,sizeof dp);
        ans= go(a,0,n,0,0);        
        return ans;
    }
};