class Solution {
public:
    vector<vector<int>>v;
    vector<int>sz;
    
    int go(int node,int p,int &c){
        set<int>sett;
        int curr=1;
        for(int x:v[node]){
            if(x==p)continue;
            int s=go(x,node,c);
            sett.insert(s);
            curr+=s;
        }
        if(sett.size()<=1)++c;
        return curr;
    }
    int countGoodNodes(vector<vector<int>>& e) {
        int E=e.size();
        int n=E+1;
        sz.resize(n+1);
        v.resize(n+1);
        for(auto ee:e){
            v[ee[0]].push_back(ee[1]);
            v[ee[1]].push_back(ee[0]);
        }
        int c=0;
        go(0,-1,c);
        
        return c;
    }
};