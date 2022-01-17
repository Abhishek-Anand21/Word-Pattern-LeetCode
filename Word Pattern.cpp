class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map <char,string> ch_map;
        unordered_map <string,char> wrd_map;
        stringstream s(str);
        string word;
        int i=0,n=pattern.size();
        while(s >> word) {
            char ch = pattern[i];
            if(i==n) return false;
            if(ch_map.count(ch) != wrd_map.count(word)) return false;
            if(ch_map.count(ch)) {
                if(ch_map[ch] != word || wrd_map[word] != ch) return false;
            }
            else {
                ch_map.insert({ch, word});
                wrd_map.insert({word, ch});
            }
            i++;
        }
        return i==n;
    }
};
