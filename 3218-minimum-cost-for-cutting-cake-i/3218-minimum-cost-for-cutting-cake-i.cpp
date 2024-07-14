class Solution {
public:
    int dp[22][22][22][22];
    int go(int n,int m,vector<int>&h,vector<int>&v,int hi,int vi){
        if(n==1 && m== 1)return 0;
        if(dp[n][m][hi][vi] != -1)return dp[n][m][hi][vi] ;
        int ans=1e9;
        for(int i=1,j=hi;i<n;i++,j++){
            ans=min(ans, go(i,m,h,v,hi,vi) + go(n-i,m,h,v,j+1,vi) + h[ j ] );
        }        
        
        for(int i=1,j=vi;i<m;i++,j++){
            ans=min(ans, go(n,i,h,v,hi,vi) + go(n,m-i,h,v,hi,j+1) + v[j] );
        }
        return dp[n][m][hi][vi] = ans;
    }
    
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        /*
        
        
        -------------
        |      |     |       
        --------------       
        |      |     |   
        -------------
        
        */
        memset(dp,-1,sizeof dp);
        return go(m,n,h,v,0,0);
    }
};