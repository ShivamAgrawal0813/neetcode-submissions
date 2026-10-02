class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;

        int n = words.size();

        for (string& word : words) {
            for (char c : word) {
                indeg[c] = 0;
            }
        }

        int i = 0;
        int j = 1;

        while (j < n) {
            int l1 = words[i].size();
            int l2 = words[j].size();

            bool allSame = true;

            for (int k = 0; k < min(l1, l2); k++) {
                char c1 = words[i][k];
                char c2 = words[j][k];

                if (c1 == c2) continue;

                if (adj[c2].count(c1)) return "";

                if (!adj[c1].count(c2)) {
                    adj[c1].insert(c2);
                    indeg[c2]++;
                }
                allSame = false;
                break;
            }
            if (allSame && l1 > l2) return "";

            i++;
            j++;
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

        if (ans.size() < indeg.size()) return "";
        return ans;
    }
};
