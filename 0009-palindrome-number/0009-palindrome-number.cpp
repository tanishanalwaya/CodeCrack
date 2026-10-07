class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false; // trailing zero can't match a leading digit (except x=0 itself)

        int reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }

        return x == reverted || x == reverted / 10;
    }
};