class Solution {
public:
    int maxOperations(string s) {
        /*
        2
        0001111
        [0] [0] 11111101101
        
        11101101101
        */
        string t = "";
        for(char c:s){
            if( !(t.size()) && (c=='1')  ){
                t+=c;
            }else if(t.size() && ((c=='1') || (c=='0' && t.back()=='1') ))t+=c;
        }
        int cc=0,ans=0;
        for(char c:t){
            if(c=='0'){
                ans+=cc;
            }else cc+=1;
        }
        return ans;
    }
};