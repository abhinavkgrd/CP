#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i, a, b) for (int i = a; i <= b; i++)

#define MOD 10e7 + 9

#define MAX_SIZE 1000001

void setupFileIO()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
void setup()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // setupFileIO();
}
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    REP(i, 0, n - 1)
    {
        cin >> a[i];
    }
    ll minSize = *min_element(a, a + n);
    ll maxAllowedSize = 2 * minSize - 1;
    ll ans = 0;
    REP(i, 0, n - 1)
    {
        ans += (a[i] - 1) / maxAllowedSize;
    }
    cout << ans << "\n";
}

int main()
{
    setup();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}