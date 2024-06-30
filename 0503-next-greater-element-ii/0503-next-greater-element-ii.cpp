class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        stack<int>st,st1;
        vector<int>ans(n,-1);
        for(int x:a)if(!st.size() or x>st.top())st.push(x);
        // st1=st;
        // while(st.size() && st.top())cout<<st.top()<<" ",st.pop();
        for(int i=n-1; i>=0; i--){
            if(!st.size())st.push(a[i]);
            else if(a[i]<st.top()){
                ans[i]=st.top();
                st.push(a[i]);
            }else{
                while(st.size() && st.top()<=a[i])st.pop();
                if(st.size())ans[i]=st.top();
                st.push(a[i]);
            }
        }
        
        for(int i=n-1; i>=0; i--){
            if(!st.size())st.push(a[i]);
            else if(a[i]<st.top()){
                ans[i]=st.top();
                st.push(a[i]);
            }else{
                while(st.size() && st.top()<=a[i])st.pop();
                if(st.size())ans[i]=st.top();
                st.push(a[i]);
            }
        }
         
     return ans;   
    }
};