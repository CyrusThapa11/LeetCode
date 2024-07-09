class Solution {
public:
    #define ll long long
    long long countCompleteDayPairs(vector<int>& a) {
        map<ll,ll>mp;
        vector<ll>b;
        for(int &x:a){
            x%=24;
            ++mp[x];
            if(x && mp[x]==1){
                b.push_back(x);
            }
        }
        sort(begin(b),end(b));
        ll z= mp[0];
        ll ans=(z*(z-1))/2;
        ll i=0,j=b.size()-1;
        while(i<=j){
            if((b[i] + b[j]) > 24){
                --j;
            }else if(b[i] + b[j] < 24){
                ++i;
            }else {
                ll f=b[i],s=b[j];
                if(f==12){
                    ans+=(mp[b[i]]*(mp[b[i]] - 1))/2;                    
                }else{
                    ans+=(mp[b[i]]* mp[b[j]]);
                }
                ++i,--j;
            }
        }
        return ans;
    }
};