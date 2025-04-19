class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> m;
        string ans = "";
        for (auto k : knowledge) {
            m[k[0]] = k[1];
        }

        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                int j = i + 1;
                string key = "";
                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }

                if (m.count(key)) {
                    ans += m[key];
                } else {
                    ans += '?';
                }

                i = j;
            } else {
                ans += s[i];
            }
            i++;
        }

        return ans;
    }
};