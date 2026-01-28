#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> swords(n), b(n);
        for (auto &x : swords) cin >> x;
        for (auto &x : b) cin >> x;

        sort(swords.begin(), swords.end());

        ll bIndex = 0;
        ll numSwords = n;
        vector<ll> tempB;

        // initial allocation
        while (bIndex < n && numSwords > 0) {
            if (numSwords >= b[bIndex]) {
                numSwords -= b[bIndex];
                tempB.push_back(0);
                bIndex++;
            } else {
                tempB.push_back(b[bIndex] - numSwords);
                numSwords = 0;
            }
        }

        vector<ll> levelsForX;

        if (bIndex == n) {
            levelsForX.push_back(bIndex);
            bIndex--;
        }

        for (int i = n - 1; i >= 0; i--) {

            // no levels left
            if (bIndex < 0) {
                levelsForX.push_back(0);
                continue;
            }

            // ensure tempB index is valid
            if (bIndex >= (ll)tempB.size()) {
                levelsForX.push_back(bIndex);
                continue;
            }

            if (tempB[bIndex] == b[bIndex]) {
                bIndex--;
                if (bIndex < 0) {
                    levelsForX.push_back(0);
                    continue;
                }
            }

            if (bIndex >= 0 && bIndex < (ll)tempB.size())
                tempB[bIndex]++;

            levelsForX.push_back(max(0LL, bIndex));
        }

        if (!levelsForX.empty() && levelsForX[0] == n)
            levelsForX.pop_back();

        ll ans = 0;
        for (int i = 0; i < n && i < (int)levelsForX.size(); i++) {
            ans = max(ans, levelsForX[i] * swords[i]);
        }

        cout << ans << '\n';
    }
}
