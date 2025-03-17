class Solution {
public:
    bool divideArray(vector<int>& a) {
        map<int,int>m;
        for(int x:a)m[x]++;
        for(auto p:m){
            if(p.second & 1)return 0;
        }
        return 1;
    }
};