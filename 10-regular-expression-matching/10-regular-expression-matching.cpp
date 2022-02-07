class Solution 
{
public:
    unordered_map<int, unordered_map<char, int>> automaton;
    int state = 1;
    bool isMatch(string s, string p)
    {
        int plen = p.length();
        for (int i = 0; i < plen; ++i)
        {
            char x = p[i];
            if ('a' <= x && x <= 'z' || x == '.')
                automaton[state][x] = state + 1, state += 1;
            else if (x == '*' && i > 0)
            {
                automaton[state - 1][p[i - 1]] = state - 1; // match >= 1 p[i - 1]
                automaton[state - 1]['$'] = state;          // match zero p[i - 1]
            }
        }
        return match(s, 0, 1);
    }
    
    /* idx - we are matching s[idx]
     * cur - current state in automaton
     */
    bool match(string &s, int idx, int cur)
    {
        int n = s.length();
        
        if (cur == 0) return false;
        if (idx >= n && cur == state) return true;
        
        if (idx < n)
        {
            /* Each node in automaton, has no more than 3 edges,
             * '$' means matching no character, hence still use `idx` in next matching.
             * For example, p = "a.b*c", s = "aac", we should output true,
             * match(s, idx, s3) means that, we skip matching "b*" in automaton (matched zero 'b').
             */
            int s1 = automaton[cur][s[idx]];
            int s2 = automaton[cur]['.'];
            int s3 = automaton[cur]['$'];
            return match(s, idx + 1, s1) || match(s, idx + 1, s2) || match(s, idx, s3);
        }
        else if (idx == n) 
        {
            /* May be the last edge of automaton is `state[n-1] -- $ --> state[n]`
             * e.g. s = "aa", p = "a*"
             */
            return match(s, idx, automaton[cur]['$']);
        }
        return false;
    }
};