class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int i = 0; // index of the next value we need from target

        for (int num = 1; num <= n && i < (int)target.size(); num++) {
            ops.push_back("Push");
            if (num == target[i]) {
                i++;               // keep it
            } else {
                ops.push_back("Pop"); // not needed, discard
            }
        }
        return ops;
    }
};