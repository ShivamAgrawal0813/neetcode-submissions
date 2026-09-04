class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        int cnt = 0;

        for(int i=0;i<n;i++){

           char expected = i%2 == 0 ? '1' : '0';

           if(s[i]!=expected)cnt++;

        }
        
        return min(cnt,n-cnt);
    }
};