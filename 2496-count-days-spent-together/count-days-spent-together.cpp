class Solution {
public:
    int convert(string s) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));
        int total = day;
        for (int i = 0; i < month - 1; i++)
            total += days[i];
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);
        int start = max(a1, b1);
        int end = min(a2, b2);
        return max(0, end - start + 1);
    }
};