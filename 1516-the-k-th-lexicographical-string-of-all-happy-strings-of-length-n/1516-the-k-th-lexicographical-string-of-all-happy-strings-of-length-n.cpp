class Solution {
public:
    string ans="";
    int pos=0;
    void go(string a,int n,int i) {
        if(n==i) {
            if(--pos==0){
                ans=a;
            }
            return;
        }
        for(char ch: {'a','b','c'}) {
            if(i > 0 && a[i-1] != ch) {
                go(a + ch,n,i+1);
            }else if(i==0) go(a+ch,n,i + 1);
        }
    }

    string getHappyString(int n, int k) {
        pos = k;
        go("",n,0);
        return ans;
    }
};