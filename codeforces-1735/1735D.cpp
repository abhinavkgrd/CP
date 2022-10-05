#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i, a, b) for (int i = a; i < b; i++)

ll MOD = 10e7 + 9;

void setupFileIO()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}
void setup()
{
    setupFileIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    // solution goes here
    int n, k;
    cin >> n >> k;
    string a[n];
    set<string> aSet;
    REP(i, 0, n)
    {
        a[i] = "";
        REP(j, 0, k)
        {
            char c;
            cin >> c;
            a[i] += c;
            aSet.insert(a[i]);
        }
    }

    map<string, int> cnt;
    REP(i, 0, n)
    {
        set<string> bSet;
        aSet.erase(a[i]);
        bSet.insert(aSet.begin(), aSet.end());
        for (auto b : bSet)
        {
            bSet.erase(b);
            string c = "";
            REP(kx, 0, k)
            {
                if (a[i][kx] == b[kx])
                {
                    c += a[i][kx];
                }
                else if (a[i][kx] == '1' && b[kx] == '2')
                {
                    c += '0';
                }
                else if (a[i][kx] == '0' && b[kx] == '2')
                {
                    c += '1';
                }
                else
                {
                    c += '2';
                }
            }
            if (bSet.find(c) != bSet.end())
            {
                cout << a[i] << " " << b << " " << c << "\n";
                cnt[a[i]]++;
                bSet.erase(c);
            }
        }
    }
    ll ans = 0;
    for (auto x : cnt)
    {
        cout << x.F << " " << x.S << "\n";
        if (x.S >= 2)
        {
            ans += x.S * (x.S - 1) / 2;
        }
    }
    cout << ans << "\n";
}

int main()
{

    setup();

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}