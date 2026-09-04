class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto i:strs){
            s += i;
            s+= to_string(101);
            s+="x";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int cnt = 0;
        int p1 = 0;
        string check = to_string(101)+"x";
        string toadd = "";
        for(int i=0;i<s.length();i++){
            if(s.substr(i,4)==check){
                v.push_back(toadd);
                toadd = "";
                cnt++;
                i+=3;
            }else{
                toadd += s[i];
            }            
        }
        return v;
    }
};
