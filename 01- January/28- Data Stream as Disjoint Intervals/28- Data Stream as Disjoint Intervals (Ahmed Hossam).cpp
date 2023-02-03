// Author: Ahmed Hossam

class SummaryRanges {
public:

    map < int, int > Intevals;

    SummaryRanges() {
        Intevals.clear();
    }

    void addNum(int value) {
        int l  = value, r = value;
        auto next = Intevals.upper_bound(value);
        if (next != Intevals.begin()) {
            auto prevx = next;
            --prevx;
            if (prevx -> second >= value) return;
            if (prevx -> second == value - 1) l = prevx -> first;
        }
        if (next != Intevals.end() && next -> first == value + 1)
            r = next -> second, Intevals.erase(next);
        Intevals[l] = r;
    }

    vector<vector<int>> getIntervals() {
        vector < vector < int > > result;
        for (const auto& [l, r] : Intevals)
            result.push_back({l, r});
        return result;
    }
};
