class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        for (int s : students) count[s]++;

        int i = 0; // index into sandwiches
        int n = sandwiches.size();

        while (i < n && count[sandwiches[i]] > 0) {
            count[sandwiches[i]]--;
            i++;
        }
        return n - i;
    }
};