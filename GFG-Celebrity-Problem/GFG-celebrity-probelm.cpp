class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        stack<int> s;
        for(int i = 0; i < n; i++){
            s.push(i);
        }
        while(s.size() > 1){
            //Candidate 1
            int l = s.top();
            s.pop();
            //Candidate 2
            int r = s.top();
            s.pop();
            //Select Candidate
            if (mat[l][r] == 0){
                s.push(l);
            }else{
                s.push(r);
            }
        }
        int candidate = s.top();
        for(int i = 0; i < n; i++){
            if ((i != candidate) && (mat[i][candidate] == 0 || mat[candidate][i] == 1)){ // NO celebrity
                return -1;
            }
        }
        return candidate; // celebrity found
    }
};