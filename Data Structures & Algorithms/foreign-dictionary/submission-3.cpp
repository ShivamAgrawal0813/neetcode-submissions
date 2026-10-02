class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;

        int n = words.size();

        int i = 0;
        int j = 1;

        while (j < n) {
            int l1 = words[i].size();
            int l2 = words[j].size();

            int cnt = 0;

            for (int k = 0; k < min(l1, l2); k++) {
                char c1 = words[i][k];
                char c2 = words[j][k];

                if (c1 == c2) {
                    // adj[c1].push_back({});
                    if (!indeg.count(c1)) indeg[c1] = 0;
                    if (!indeg.count(c2)) indeg[c2] = 0;
                    cnt++;
                } else {
                    adj[c1].insert(c2);
                    if (adj[c2].count(c1)) return "";
                    // indeg[c2]++;
                    if (!indeg.count(c1)) indeg[c1] = 0;
                    break;
                }

                if (cnt == min(l1, l2) && l1 > l2) return "";
            }

            i++;
            j++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                char c = words[i][j];
                if(!indeg.count(c))indeg[c] = 0;
            }
        }

        for (auto& i : adj) {
            for (auto& c: i.second) {
                indeg[c]++;
            }
        }

        queue<char> q;
        for (auto& i : indeg) {
            if (i.second == 0) q.push(i.first);
        }

        string ans = "";

        while (!q.empty()) {
            char c = q.front();
            q.pop();
            // cout<<c<<" ";
            ans += c;

            for (auto& n : adj[c]) {
                // if(c=='n')cout<<n<<" ";
                indeg[n]--;
                if (indeg[n] == 0) q.push(n);
            }
        }

        if(ans.size()<indeg.size())return "";
        return ans;
    }
};
