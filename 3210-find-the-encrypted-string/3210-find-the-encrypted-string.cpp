class Solution {
public:
    string getEncryptedString(string s, int k) {
        int l=s.length();
        k%=l;
        if(!k)return s;
        string t=s;
        for(int i=0;i<l;i++){
            t[i] = s[(k+i)%l];
        }
        return t;
    }
};