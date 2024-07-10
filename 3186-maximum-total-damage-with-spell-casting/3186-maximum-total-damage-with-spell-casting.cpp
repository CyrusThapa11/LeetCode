class Solution {
public:
    #define ll long long 
    unordered_map<int,int>mp;
    int N;
    ll go(vector<int>&p,int pos,vector<ll>&dp){
        if(pos>=N){
            return 0;
        }
        
        if(dp[pos]!=-1)return dp[pos];
        
        ll o1 = go(p,pos+1,dp);
        ll o2 = p[pos]*1ll*mp[p[pos]];
        int i=pos;
        while(i < N && p[i]<=p[pos]+2)++i;
        
        if(i>=N)dp[i] = 0;
        
        if(i < N && dp[i] == -1)o2+= go(p,i,dp);
        else o2+= dp[i];
        
        return dp[pos] = max(o1,o2);
    }
    
    long long maximumTotalDamage(vector<int>& p) {
        for(int x:p)mp[x]++;        
        vector<int>P;
        for(auto pp:mp)P.push_back(pp.first);
        sort(begin(P),end(P));
        int n=P.size();
        vector<ll>dp(n + 1,-1);
        N=n;
    return go(P,0,dp);
    }
};