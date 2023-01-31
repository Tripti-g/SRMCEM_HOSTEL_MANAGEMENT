#include "bits/stdc++.h"
using namespace std;
#define int long long
//#pragma GCC target ("avx2")
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")
//#include "bits/extc++.h"
// using namespace __gnu_pbds;
// template <typename T>
// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//#define ook order_of_key
//#define fbo find_by_order
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// unordered_map<long long, int, custom_hash> safe_map;
// gp_hash_table<long long, int, custom_hash> safe_hash_table;
// class pqCompare
//{
// public:
//     bool operator()(int,int)
//     {
//         return true;
//     }
// };
//  comment endl for interactive problem
#define endl "\n"
#define PI 3.1415926535897932384626
#define yes() cout << "YES" << endl
#define no() cout << "NO" << endl
#define get(name, ind) get<ind>(name)
#define br cout << endl;
#define mint long long
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define call(x) x.cbegin(), x.cend()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define clr(s) memset(s, 0, sizeof(s))
#define valset(arr, size, val) fo(i, 0, size) arr[i] = val;
#define tr(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for (auto it = x.rbegin(); it != x.rend(); it++)
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define cntleadz(x) __builtin_clz(x)
#define cnttrailz(x) __builtin_ctz(x)
#define cntpop(x) __builtin_popcount(x)
#define binparity(x) __builtin_parity(x)
#define minof(x) min_element(x.begin(), x.end())
#define maxof(x) max_element(x.begin(), x.end())
#define make_graph(k, dir) \
    int x, y;              \
    fo(i, 0, k)            \
    {                      \
        cin >> x >> y;     \
        adj[x].pb(y);      \
        if (dir)           \
            adj[y].pb(x);  \
    }
#define make_weighted_graph(k, dir) \
    int x, y, z;                    \
    fo(i, 0, k)                     \
    {                               \
        cin >> x >> y >> z;         \
        adj[x].pb({y, z});          \
        if (dir)                    \
            adj[y].pb({x, z});      \
    }
#define fo(i, k, n) for (int i = k; k <= n ? i < n : i >= n; k < n ? i += 1 : i -= 1)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef pair<int, pair<int, int>> piii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<char, int> mci;
typedef set<int> si;

const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod2 = 998244353;
const int mod = 1e9 + 7;
const int N = 3e5;
vi fact;

int add(mint a, mint b, mint p = mod)
{
    int res = (a % p + b % p) % p;
    return res;
}
int sub(mint a, mint b, mint p = mod)
{
    int res = (a % p - b % p + p) % p;
    return res;
}
int mul(mint a, mint b, mint p = mod)
{
    int res = ((a % p) * (b % p)) % p;
    return res;
}
void factorial(mint n, int p = mod)
{
    fact.resize(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fact[i] = mul(i, fact[i - 1], p);
    }
}
int binExp(mint x, int y, int p = mod)
{
    mint res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modInv(mint i, int p = mod) { return binExp(i, p - 2, p); }
mint ncr(mint n, int r, int p = mod)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fact[n] * modInv(fact[r], p) % p * modInv(fact[n - r], p) % p) % p;
}
int divi(mint a, mint b, int p = mod)
{
    int binv = modInv(b, p);
    int res = ((a % p) * (binv % p)) % p;
    return res;
}
vector<bool> is_prime;
vector<int> primes;
void sieve(int n = 3e5 + 5)
{
    n = sqrt(n);
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (is_prime[i] == true)
            primes.push_back(i);
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
#ifndef ONLINE_JUDGE
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " = " << arg1 << endl;
    __f(comma + 1, args...);
}
#else
#define deb(...) 42
#endif
// IO operators for vectors, pairs, sets, maps and __int128
#define in(...)      \
    int __VA_ARGS__; \
    read(__VA_ARGS__);
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
template <typename T>
ostream &operator<<(ostream &ost, vector<T> v)
{
    if (&ost == &cerr)
    {
        cerr << "{";
        int cnt = v.size();
        for (auto x : v)
        {
            cerr << x;
            cnt--;
            if (cnt)
                cerr << ", ";
        }
        cerr << "}";
    }
    else
        for (auto i : v)
            ost << i << " ";
    return ost;
}
template <typename T>
ostream &operator<<(ostream &ost, set<T> s)
{
    if (&ost == &cerr)
    {
        cerr << "{";
        int cnt = s.size();
        for (auto x : s)
        {
            cerr << x;
            cnt--;
            if (cnt)
                cerr << ", ";
        }
        cerr << "}";
    }
    else
        for (auto i : s)
            ost << i << " ";
    return ost;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, map<U, V> &m)
{
    if (&ost == &cerr)
    {
        cerr << "{";
        int cnt = m.size();
        for (auto x : m)
        {
            cerr << x;
            cnt--;
            if (cnt)
                cerr << ", ";
        }
        cerr << "}";
    }
    else
        for (auto i : m)
            ost << i;
    return ost;
}
template <typename U, typename V>
istream &operator>>(istream &in, pair<U, V> &p)
{
    in >> p.first >> p.second;
    return in;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, pair<U, V> p)
{
    if (&ost == &cerr)
        ost << "{" << p.first << ": " << p.second << "}";
    else
        ost << p.first << " " << p.second << " ";
    return ost;
}
template <class TupType, size_t... I>
ostream &tuple_print(ostream &os,
                     const TupType &_tup, index_sequence<I...>)
{
    if (&os == &cerr)
    {
        os << "{";
        (..., (os << (I == 0 ? "" : ", ") << get<I>(_tup)));
        os << "}";
    }
    else
    {
        (..., (os << get<I>(_tup) << " "));
    }
    return os;
}
template <class... T>
ostream &operator<<(ostream &os, const tuple<T...> &_tup)
{
    return tuple_print(os, _tup, make_index_sequence<sizeof...(T)>());
}
// compile using g++ 17 64 bit msys
// typedef __int128_t xll;
// ostream &operator<<(ostream &ost, __int128_t x)
//{
//    string output = "";
//    while (x)
//        output += '0' + x % 10, x /= 10;
//    reverse(all(output));
//    ost << output;
//    return ost;
//}
// istream &operator>>(istream &in, __int128_t &x)
//{
//    x = 0;
//    string num;
//    cin >> num;
//    for (char c : num)
//        x *= 10, x += c - '0';
//    return in;
//}
// Variadic IO
template <typename... T>
void read(T &...args) { ((cin >> args), ...); }
template <typename... T>
void print(T... args)
{
    ((cout << args << " "), ...);
    cout << endl;
}

// useful fucntions iota(all(v),init) , accumulate(all(v),init)
// all_of(all(v),[](int i){ return i % 2 == 0; }),
// any_of(), none_of(),includes(all(v),all(b),comp)
//[=] byvalue, [&] byref  lambda => [&val](int x){return x;}
// auto& [x,y] : adj[i];
// auto& [x,ignore,y] : adj[i];
// pair p = {1,1}
// custom-comparator :
// auto comp = [](auto &a, auto &b)
//{ return get<1>(a) > get<1>(b); };
// set<tuple<int, int, int>, decltype(comp)> high(comp);
// cout<<fixed<<setprecision(3)<<x<<endl;

void global()
{
    return;
}
void solution()
{
    int sum = 0, cnt = 0, ans = 0, flag = 0;
    in(n);
    vi v(n);
    cin >> v;
    vi s(n + 1);
    for (int i = 0; i < n; i++)
    {
        // v[i] %= n;
        s[i + 1] += s[i] + v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // v[i] %= n;
        s[i] %= n;
        if (s[i] == 0)
        {
            cout << i << endl;
            for (int j = 0; j < i; j++)
            {
                cout << j + 1 << " ";
            }
            return;
        }
    }
    deb(s);
    vi m(n, -1);
    fo(i, 1, n + 1)
    {
        if (m[s[i]] != -1)
        {
            int k = m[s[i]];
            cout << i - k << endl;
            fo(j, k, i)
            {
                cout << j + 1 << " ";
            }
        }
        m[s[i]] = i;
    }

    // there will always be a subarray so the answer will be same for sub set
    //
    // in(n);
}
signed main()
{
    // comment below for interactive problem
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    global();
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        // cout << "Case #" << i << ": ";
        solution();
    }
    return 0;
}