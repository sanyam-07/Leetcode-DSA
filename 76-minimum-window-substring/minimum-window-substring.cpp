class Solution {
public:
    string minWindow(string s, string t) {
          int hash[256] = {0};     // frequency array
    int l = 0, r = 0;
    int n = s.size();
    int m = t.size();
    int cnt = 0;

    int minLen = 1e9;        // large number
    int sIndex = -1;

    // Store frequency of characters of t
    for (int i = 0; i < m; i++) {
        hash[t[i]]++;
    }

    while (r < n) {

        // If current char is needed
        if (hash[s[r]] > 0) {
            cnt++;
        }

        hash[s[r]]--;

        // When all characters matched
        while (cnt == m) {

            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                sIndex = l;
            }

            hash[s[l]]++;

            if (hash[s[l]] > 0) {
                cnt--;
            }

            l++;
        }

        r++;
    }

    if (sIndex == -1) return "";

    return s.substr(sIndex, minLen);

    }
};