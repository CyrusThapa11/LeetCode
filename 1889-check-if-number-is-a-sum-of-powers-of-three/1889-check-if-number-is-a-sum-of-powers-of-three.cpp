class Solution {
public:
    bool ok(int n,int a) {
        if(n==0)return 1;
        if(a > n)return 0;
        return ok(n - a, a*3 ) || ok(n,a*3);
    }
    bool checkPowersOfThree(int n) {

        return ok(n,1);

    }
};