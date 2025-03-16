class Solution {
public:
    set<int>sett;
    int totalNumbers(vector<int>& a) {

        int n=a.size(),ans=0;
        for(int i=0;i<n;i++){
            if(a[i] == 0)continue;
            for(int j=0;j<n;j++) {
                if(i==j)continue;
                for(int k=0;k<n;k++) {
                    if(j==k || k==i)continue;
                    int N = a[i] * 100 + a[j] * 10 + a[k];
                    if(N&1)continue;
                    sett.insert(N);
                }
            }
        }
        return sett.size();
    }
};