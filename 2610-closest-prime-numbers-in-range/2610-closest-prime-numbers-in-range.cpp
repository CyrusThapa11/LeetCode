class Solution {
public:
    int N=1000001;
    vector<int>a;
    vector<int> closestPrimes(int l, int r) {
        vector<int>b;
        N=r + 1;
        a.resize(N);
        fill(begin(a),end(a),1);
        a[0]=a[1]=0;
        int lim = N;
        // for(int i=4;i<lim;i+=2)a[i]=0;
        for(int i=2;i<lim;i++){
            if(a[i])
            for(int j= 2*i;j<lim;j+=i){
                a[j] = 0;
            }
        }
        b.push_back(2);
        for(int i=3;i<lim;i+=2){
            if(a[i])b.push_back(i);
        }
        // cout<< " b "<<endl;
        // for(int x:b){
        //     cout<<x<<" , ";
        //     if(x>r)break;
        // }
        // cout<<endl;
        int n=b.size();
        int ans=1e9,x=-1,y=-1;
        for(int i=0; i < n ;i++ ) {
            if( i + 1 < n && b[i] >= l && b[i] <= r && b[i + 1] <= r) {
                if(ans==1e9) {
                    x=b[i],y=b[i + 1];
                    ans=y-x;
                }else if(ans > (b[i + 1]-b[i])) {
                    ans=b[i + 1]-b[i];
                    x=b[i] , y=b[i + 1];
                }
            }
        }

    return {x,y};
    }
};