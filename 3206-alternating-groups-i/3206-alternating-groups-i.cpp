class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c) {
        int n=c.size(),ans=0;
        
        for(int i=0;i<n;i++){
            ans+=( c[(i-1+n)%n] == c[(i+1)%n] && c[i] != c[(i+1)%n]);
        }
        return ans;
    }
};