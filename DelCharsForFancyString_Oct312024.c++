class Solution {
public:
    string makeFancyString(string s) {
        stack<char> st;
        st.push(s[0]);
        st.push(s[1]);
        if(s.size() == 1)
        return s;
        for(int i=2;i<s.size();i++){
            char x=s[i];
            char c1=st.top();
            st.pop();
            char c2=st.top();
            st.pop();
            st.push(c2);
            st.push(c1);
            if(c1 == c2 and c1 == x){
            }
            else{
                st.push(x);
            }
        }
        string ans="";
        while(st.size() > 0){
            ans+=st.top();
            st.pop();
        }
        string rev="";
        for(int i=ans.size()-1;i>=0;i--)
        rev+=ans[i];
        return rev;
    }
};