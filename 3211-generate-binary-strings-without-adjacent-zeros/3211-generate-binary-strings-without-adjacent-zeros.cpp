class Solution {
public:
    vector<string>v;
    void go(int n,string t){
        if(!n){
            v.push_back(t);
            return ;
        }
        if(!t.length() || t.back()=='1')go(n-1,t + string(1,'0'));
        go(n-1,t+string(1,'1'));
    }
    vector<string> validStrings(int n) {
        v.clear();
        go(n,"");
        return v;
    }
};