#include <queue>
#include <vector>

using namespace std;

#define MP(x, y) make_pair(x, y)

priority_queue<pair<double, int>> que;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        while(!que.empty()) que.pop();

        int n = classes.size();
        for (int i = 0; i < n; ++i)
        {
            int cur = classes[i][0], tot = classes[i][1];
            double value = 1.0 * (cur + 1) / (tot + 1) - 1.0 * cur / tot;
            que.push(MP(value, i));
        }

        for (int i = 0; i < extraStudents; ++i)
        {
            int c = que.top().second;
            que.pop();
            classes[c][0] += 1;
            classes[c][1] += 1;
            int cur = classes[c][0], tot = classes[c][1];
            double value = 1.0 * (cur + 1) / (tot + 1) - 1.0 * cur / tot;
            que.push(MP(value, c));
        }

        double ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int cur = classes[i][0], tot = classes[i][1];
            ans += 1.0 * cur / tot;
        }

        ans = ans / (double) n;

        return ans;

    }
};