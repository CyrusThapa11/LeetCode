class Spreadsheet {
public:

    vector<vector<int>>t;
    Spreadsheet(int r) {
        t.resize(r + 1);
        for(int i=0;i<=r;i++) {
            t[i].resize(27);
            fill(begin(t[i]),end(t[i]),0);
        }
    }

    
    void setCell(string cell, int v) {
        int c = cell[0] - 'A' + 1;
        int r = stoi(cell.substr(1));
        t[r][c] = v;
    }
    
    void resetCell(string cell) {
        int c = cell[0] - 'A' + 1;
        int r = stoi(cell.substr(1));
        t[r][c] = 0;
        
    }
    
    int getValue(string f) {
        stringstream ss(f.substr(1));
        string s;
        int sum = 0;
        while(getline(ss,s,'+')) {
            int num=1;
            for(char c:s){
                if(!isdigit(c)) {
                    num=0;
                    break;
                }
            }
            int val = 0;
            if(num ) {
                val = stoi(s);
                sum+=val;
            }else {
                int c = s[0] - 'A' + 1;
                int r = stoi(s.substr(1));
                sum+= t[r][c];
            }
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */