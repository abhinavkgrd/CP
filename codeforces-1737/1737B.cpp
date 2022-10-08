#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define MOD 10e7 + 9

void setupFileIO()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}
void setup()
{
    // setupFileIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
}

ll subSolve(ll x)
{
    if (x == 0)
    {
        return 0;
    }
    ll sx = sqrt(x);
    ll ans = x / sx - sx + 1;
    return ans;
}

void solve()
{
    // solution goes here
    ll l, r;
    cin >> l >> r;

    ll al = 3 - subSolve(l - 1);
    // cout << ll(sqrt(r)) << " " << ll(sqrt(l)) << "\n";
    ll am = 3 * (ll(sqrt(r)) - ll(sqrt(l)) - 1);
    ll ar = subSolve(r);
    // cout << al << " " << am << " " << ar << "\n";
    ll ans = al + am + ar;
    cout << ans << "\n";
}

int main()
{
    setup();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}