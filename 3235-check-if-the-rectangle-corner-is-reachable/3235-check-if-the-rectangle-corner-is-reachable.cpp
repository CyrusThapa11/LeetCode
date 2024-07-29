class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        vector<int> parent(n + 2);
        for (int i = 0; i < n + 2; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            long x = circles[i][0];
            long y = circles[i][1];
            long r = circles[i][2];
            if (x - r <= 0 || y + r >= Y) {
                union_set(n,i,parent);
            }
            if (x + r >= X || y - r <= 0) {
                union_set(n+1,i,parent);
            }
            for (int j = 0; j < i; j++) {
                long x2 = circles[j][0];
                long y2 = circles[j][1];
                long r2 = circles[j][2];
                if (((x - x2) * (x - x2) + (y - y2) * (y - y2) <= (r + r2) * (r + r2))) {
                    union_set(i,j,parent);
                }
            }
        }
        return find(parent, n) != find(parent, n + 1);
    }
private:
    void union_set(int x, int y, vector<int>& parent){
        int px=find(parent,x);
        int py=find(parent,y);
        if(px!=py){
            parent[py]=px;
        }
    }
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }
};