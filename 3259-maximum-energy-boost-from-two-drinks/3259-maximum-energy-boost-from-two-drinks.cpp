class Solution {
public:
    #define ll long long 
    ll dp[(ll)1e5 + 2][2];
    ll go(vector<int>&a,vector<int>&b,ll pos, ll vec){
        if(pos<=0)return 0;
        if(dp[pos][vec]!=-1)return dp[pos][vec];
        ll o1=0,o2=0;
        if(vec){
            // B
            o1= b[pos-1]+go(a,b,pos-1,vec);
            o2= go(a,b,pos-1,1-vec);
        }else {
            o1= a[pos-1]+go(a,b,pos-1,vec);
            o2= go(a,b,pos-1,1-vec);            
        }
        return dp[pos][vec]=max(o1 , o2 );
    }
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        ll n = A.size();
        memset(dp,-1,sizeof dp);
        return max(go(A,B,n,0),go(A,B,n,1));
    }
};