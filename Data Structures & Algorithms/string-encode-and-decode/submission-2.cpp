class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string i:strs){
            int len = i.length();
            s+= to_string(len);
            s+= "#";
            s+= i;
        }
        return s;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> v;
        while(i<s.length()){
            int j = i;
            
            while(s[j]!='#')j++;
            
            int len = stoi(s.substr(i,j-i));

            i=j+1;
            v.push_back(s.substr(i,len));
            i+=len;
        }
        return v;
    }
};
