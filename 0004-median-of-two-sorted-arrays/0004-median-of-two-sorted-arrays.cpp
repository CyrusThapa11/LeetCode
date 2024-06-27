class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size())return findMedianSortedArrays(b,a);
        double ans=0.0;
        int an=a.size(),bn=b.size(),tot=a.size()+b.size();
        if(an==0){
            if(bn&1)return b[bn/2];
            return (b[bn/2]+b[bn/2-1])/2.0;
        }
        if(bn==0){
            if(an&1)return a[an/2];
            return (a[an/2]+a[an/2-1])/2.0;
        }
        // for(int x:a)cout<<x<<" ";
        int lo=0,hi=a.size();
        while(lo<=hi){
            
            int mid = (lo+hi)/2;
            int mid2= (tot+ 1)/2 - mid ;
            
            int p1= mid-1>=0 ?  a[mid-1] : INT_MIN;
            int p2= mid2-1>=0 ?  b[mid2-1] : INT_MIN;
            int q1= mid  < an ?   a[mid] : INT_MAX;
            int q2= mid2 < bn ?  b[mid2] : INT_MAX;
            
            if( p1<= q2 && p2 <= q1  ){
                if(tot&1)return max(p1,p2);
                else return (max(p1,p2)+min(q1,q2))/2.00;
            }else if( p1 > q2 )
                hi=mid-1;
            else lo=mid+1;
        }
        
        
        return ans;
    }
};