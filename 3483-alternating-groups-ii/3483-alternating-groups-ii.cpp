class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a, int k) {
        int n=a.size(),ans=0,K=k;
        // 1 2 3 4 5 6 7 8, T = 5
        int cnt=0,ff=-1,last=-1,curr=0;
        int i=0;
        for(;i<n-1;i++) {
            if(a[i] != a[i+1]) {
                ++curr;
            }else {
                if(ff==-1)ff=curr;
                // else if(i==n-2)last=curr;
                else cnt+=(max(0,curr + 1 - k + 1));
                curr=0;
            }
            last=curr;
        }
        if(curr == n-1)return (a[0] == a[n-1] ? n-k + 1 : n);
        if(last==-1 && i==n-1)last=curr;
        cout<< ff << " , "<<last<<endl;
        if(a[0] == a[n-1]) {
            cnt+=(max(0,(ff + 1 >= k ? ff + 1 - k + 1:0)) + (max(0,(last + 1>= k ? last + 1 - k + 1: 0) )));
        }else {
            cnt+=max(0, (ff + 1  + last + 1 >= k ? ff + 1  + last + 1 - k + 1 : 0 ));
        }

    return cnt;
    }
};