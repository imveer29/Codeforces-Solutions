/*Chandraveer Singh*/

#include <bits/stdc++.h>
using namespace std;


/*-----------------------MACROS-----------------------------------*/

#define fastio()         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD              1000000007
#define MOD1             998244353
#define inf              1e18
#define endl             "\n"
#define sz(x)            (int)x.size()
#define pb               push_back
#define ppb              pop_back
#define mp               make_pair
#define ff               first
#define ss               second
#define pi               3.141592653589793238462
#define all(x)           (x).begin(), (x).end()
#define gcd              __gcd
#define setbits          __builtin_popcount
#define setbitsll        __builtin_popcountll

/*-----------------------Debugging--------------------------------*/

#ifndef ONLiNE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(stack <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/*--------------------------Algorithms----------------------------*/

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void google(int t) {cout << "Case #" << t << ": ";}

/*--------------------------Code begins---------------------------*/

// Problem Link : https://codeforces.com/contest/1201/submission/170834527

bool helper(vector<ll> arr, ll n, ll mid, ll k)
{
    ll ops = 0;
    for (ll i = n / 2; i < n; ++i)
        ops += max(0LL, mid - arr[i]);

    return k >= ops;

}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i)
        cin >> arr[i];
    sort(all(arr));
    ll left = arr[n / 2];
    ll right = arr[n / 2] + k;
    ll median = left;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (helper(arr, n, mid, k))
        {
            median = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << median << endl;

}

int main()
{
#ifndef ONLiNE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
