class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1) return 1;
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if(s[left]==s[right] && left!=right){
                char a = s[left];
                while (left <s.size() && s[left] == a) left += 1;
                while (right >=0 && s[right]==a) {
                    right-=1;
                    s.pop_back();
                }
            }
            else {
                return right-left+1;
            }
        }
        return 0;
    }
};

//cbc