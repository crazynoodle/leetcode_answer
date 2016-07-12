/*
 *  '.' Matches any single character.
 *  '*' Matches zero or more of the preceding element.
 *  
 *  The matching should cover the entire input string (not partial).
 *  
 *  The function prototype should be:
 *  bool isMatch(const char *s, const char *p)
 *  
 *  Some examples:
 *  isMatch("aa","a") → false
 *  isMatch("aa","aa") → true
 *  isMatch("aaa","aa") → false
 *  isMatch("aa", "a*") → true
 *  isMatch("aa", ".*") → true
 *  isMatch("ab", ".*") → true
 *  isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[1] != '*'){//首先判断第二个字符是否为‘*’；若不是‘*’，判断第一字符是否匹配成功，成功，那么继续进行下一字符的匹配；\
        若第一字符匹配不成功，则整个字符串匹配不成功；
            if(s[0] != '\0' && (s[0] == p[0] || p[0] == '.')) return isMatch(s.substr(1),p.substr(1));
            else return false;
        }else
        {
            //如果匹配段第二个字符是''*'，若第一字符匹配不成功，那么直接跳过匹配段的两个字符，进行isMatch(s,p.substr(2))，\
            此处相当于抛弃匹配段的头两个字符;若第一字符匹配成功，先判断待匹配字符段与匹配字符段除去前两个字符的段匹配；\
            若成功，那么结果成功；否则，待匹配字符段跳过第一个字符，继续判断下一字符与当前匹配段第一字符是否匹配；如此循环；直到s或p为空；
            while(s[0] != '\0' && (s[0] == p[0] || p[0] == '.'))
            {
                if(isMatch(s,p.substr(2))) return true;
                s.erase(s.begin());
            }
            return isMatch(s,p.substr(2));
        }
    }
};
