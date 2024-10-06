class Solution {
public:
    bool Solve(vector<string>&A, vector<string>&B, int i, int j, int skipStatus){
        if(i==A.size() && j==B.size()) return true;
        
        if(i == A.size()){
            return skipStatus != 2; 
        }
        
        if(j == B.size()) return false;
        
        if(A[i]!=B[j]){
            if(skipStatus == 2) return false;
            return Solve(A, B, i, j+1, 1);
        }
        
        if(skipStatus == 1){
            return Solve(A, B, i+1, j+1, (skipStatus == 1) ? 2: skipStatus) || Solve(A, B, i, j+1, 1);
        }
        
        return  Solve(A, B, i+1, j+1, (skipStatus == 1) ? 2: skipStatus);
    }   
    
    vector<string> getWords(string &s){
        vector<string> temp ;
        for(int i=0; i<s.size(); i++){
            string str; 
            while(i<s.size() && s[i]!=' '){
                str += s[i++];
            }
            if(str.size() > 0) temp.push_back(str);
        }
        return temp;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> A = getWords(sentence1);
        vector<string> B = getWords(sentence2);
        if(A.size() > B.size()) swap(A,B);
        return Solve(A, B, 0, 0, 0);
    }
};