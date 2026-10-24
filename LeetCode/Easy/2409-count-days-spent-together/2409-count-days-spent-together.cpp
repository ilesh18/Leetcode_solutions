class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int daysBeforeMonth[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        auto getDay = [&](string date) {
            int month = (date[0] - '0') * 10 + (date[1] - '0');
            int day = (date[3] - '0') * 10 + (date[4] - '0');
            return daysBeforeMonth[month] + day;
        };
        int startAlice = getDay(arriveAlice);
        int endAlice = getDay(leaveAlice);
        int startBob = getDay(arriveBob);
        int endBob = getDay(leaveBob);
        int startTogether = max(startAlice, startBob);
        int endTogether = min(endAlice, endBob);
        return max(0, endTogether - startTogether + 1);
    }
};