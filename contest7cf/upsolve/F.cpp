#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = (ll)4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, Ax, Ay, Bx, By;
        cin >> n >> Ax >> Ay >> Bx >> By;

        vector<ll> x(n), y(n);
        for (auto &v : x) cin >> v;
        for (auto &v : y) cin >> v;

        // group houses by x
        vector<pair<ll,ll>> pts;
        pts.reserve(n + 2);

        for (int i = 0; i < n; i++) {
            pts.push_back({x[i], y[i]});
        }

        // add start and end as artificial columns
        pts.push_back({Ax, Ay});
        pts.push_back({Bx, By});

        sort(pts.begin(), pts.end());

        // compress columns: for each unique x → (low, high)
        vector<ll> xs;
        vector<pair<ll,ll>> col; // (low, high)

        for (auto &p : pts) {
            if (xs.empty() || xs.back() != p.first) {
                xs.push_back(p.first);
                col.push_back({p.second, p.second});
            } else {
                col.back().first  = min(col.back().first,  p.second);
                col.back().second = max(col.back().second, p.second);
            }
        }

        int m = xs.size();

        // dp[i][0] → end at low[i]
        // dp[i][1] → end at high[i]
        vector<array<ll,2>> dp(m, {INF, INF});

        // base case (start column)
        dp[0][0] = abs(Ay - col[0].second) + (col[0].second - col[0].first);
        dp[0][1] = abs(Ay - col[0].first ) + (col[0].second - col[0].first);

        for (int i = 1; i < m; i++) {
            ll dx = xs[i] - xs[i-1];
            ll low  = col[i].first;
            ll high = col[i].second;
            ll prevLow  = col[i-1].first;
            ll prevHigh = col[i-1].second;
            ll span = high - low;

            // end at low
            dp[i][0] = min(
                dp[i-1][0] + abs(prevLow  - high) + dx,
                dp[i-1][1] + abs(prevHigh - high) + dx
            ) + span;

            // end at high
            dp[i][1] = min(
                dp[i-1][0] + abs(prevLow  - low) + dx,
                dp[i-1][1] + abs(prevHigh - low) + dx
            ) + span;
        }

        cout << min(dp[m-1][0], dp[m-1][1]) << '\n';
    }
}
