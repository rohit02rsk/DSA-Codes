class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) return false;
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        for(char c : t) {
            if(mp.find(c) == mp.end()) return false;
            mp[c]--;
            if(mp[c] == 0) mp.erase(c);
        }
        return true;
    }
};