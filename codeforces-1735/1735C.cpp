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

#define MOD 10e7 + 9
#define MAX_SIZE 26

class DSU
{
    int parent[MAX_SIZE];
    int size[MAX_SIZE];

public:
    DSU()
    {
        fill_n(parent, MAX_SIZE, -1);
        fill_n(size, MAX_SIZE, -1);
    }

private:
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

public:
    int find_set(int v)
    {
        if (parent[v] == -1)
        {
            this->make_set(v);
        }
        if (parent[v] == v || parent[v] == -1)
        {
            return parent[v];
        }
        else
        {
            return parent[v] = find_set(parent[v]);
        }
    }

public:
    int sizeof_set(int v)
    {
        int pv = this->find_set(v);
        return size[pv];
    }

public:
    void union_set(int u, int v)
    {
        int pu = find_set(u);
        int pv = find_set(v);
        if (size[pu] < size[pv])
        {
            swap(pu, pv);
        }
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

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
    int n;
    cin >> n;
    int a[n];
    REP(i, 0, n)
    {
        char x;
        cin >> x;
        a[i] = x - 'a';
    }
    set<int> unusedChars;
    REP(i, 0, 26)
    {
        unusedChars.insert(i);
    }
    DSU charChains;
    int charPair[26];
    fill_n(charPair, 26, -1);
    REP(i, 0, n)
    {
        if (charPair[a[i]] != -1)
        {
            continue;
        }
        int availableChar = *unusedChars.begin();
        unusedChars.erase(availableChar);
        // cout << "availableChar -> " << char('a' + availableChar) << " " << charChains.find_set(availableChar) << " " << charChains.find_set(a[i]) << "\n ";
        if (
            charChains.find_set(availableChar) == charChains.find_set(a[i]) && charChains.sizeof_set(availableChar) != 26)
        {
            int unusableAvailableChar = availableChar;
            availableChar = *unusedChars.begin();
            unusedChars.erase(availableChar);
            unusedChars.insert(unusableAvailableChar);
        }
        charChains.union_set(availableChar, a[i]);
        charPair[a[i]] = availableChar;
    }
    REP(i, 0, n)
    {
        cout << char('a' + charPair[a[i]]);
    }
    cout << "\n";
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