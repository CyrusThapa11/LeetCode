class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        int all = 1,n=c.size(),ans=0;
        for(int i=0;i<n;i++){
            if(c[i] == c[(i+1)%n]){
                all=0;
                break;
            }
        }
        if(all)return n;
        int st=0,ed=n-1;
        if(c[0] != c[n-1]){
            int cnt=2,i=0;
            while( c[i]!=c[i+1]){
                ++cnt, ++i;
            }
            // n-1 
            if(i==n-1)return (n - k + 1);
            // , n - 1 
            int j= n-1;
            while(c[j]!=c[(j-1+n)%n]){
                --j,++cnt;
            }
            ans+=max(0,cnt-k+1);
            st = i+1,ed=j-1;
        }
        int cnt=1;
        for(int l=st; l <= ed ;l++){
            if(c[l] != c[(l+1)%n]){
                ++cnt;
            }else{
                ans+=(max(0,cnt-k+1));
                cnt=1;
            }
        }
        
        return ans;
    }
};