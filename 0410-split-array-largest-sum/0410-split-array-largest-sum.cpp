class Solution {
public:
    
    bool ok(int summ, vector<int>&a,int k){
        int s=0,cnt=1;
        for(int x:a){
            if(s+x>summ){
                ++cnt;
                s=0;
            }
            s+=x;
        }
        return cnt<=k;
    }
    
    int splitArray(vector<int>& a, int k) {
        int n=a.size(),lo=0,hi=accumulate(begin(a),end(a),0),ans=0;
        lo=*max_element(begin(a),end(a)) , ans=hi ;
        if(k>n)return -1;
        while(lo<=hi){
            
            int mid=(lo+hi)/2;
            if(ok(mid,a,k)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;            
        }
        return ans;
    }
};