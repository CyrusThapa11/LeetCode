class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return 1;
        if(n==2)return 5;
        
        return (n*1ll * (n+1)) - 1ll + ((n-2)*1ll*(n-1));


    }
};