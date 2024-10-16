class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> maxHeap;

        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        while (!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top();
            maxHeap.pop();

            if (res.size() > 1 && res.back() == char1 && res[res.size() - 2] == char1) {
                if (maxHeap.empty()) break;

                auto [count2, char2] = maxHeap.top();
                maxHeap.pop();
                res += char2;
                if (--count2 > 0) maxHeap.push({count2, char2});

                maxHeap.push({count1, char1});
            } else {
                res += char1;
                if (--count1 > 0) maxHeap.push({count1, char1});
            }
        }
        return res;
    }
};