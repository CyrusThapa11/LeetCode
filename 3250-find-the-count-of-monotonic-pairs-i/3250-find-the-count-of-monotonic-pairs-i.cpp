class Solution {
public:
    #define ll long long 
    #define mod ((ll)1e9 + 7)
    ll dp[51][2001];
    ll go(ll prev, ll index,vector<int>&a,ll &n){
        if(index>=n)return 1;
        
        if(dp[prev][index]!=-1)return dp[prev][index];
        
        ll n1 = prev,n2= a[index] ,c=0;
        for(ll i = prev;i <= n2;i++){
            if(n2 - i <= ( a[index-1] -prev ))
            c = ( c + go( i,index+1, a, n ) )%mod;
        }
        
        return dp[prev][index]=c;
    }
    
    int countOfPairs(vector<int>& a) {
        ll ans=0,n=a.size();
        memset(dp,-1,sizeof dp);
        for(int i=0;i<=a[0];i++){
            ans=(ans + go(i,1,a,n))%mod;
        }
        
        
        return ans;
    }
};