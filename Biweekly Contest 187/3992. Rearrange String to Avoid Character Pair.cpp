class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] == x && s[j] == y){
                    swap(s[i], s[j]);
                }
            }
        }

        return s;
    }
};