#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll long long
#define lld long double
#define ull unsigned long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define forA(i,a,n,x) for(ll i=a;i<n;i+=x)
#define forD(i,a,n,x) for(ll i=n-1;i>=a;i-=x)
#define ranit(it,n) for(auto &it:n)
#define pb push_back
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define mod 1000000007
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vll , greater<ll>>
#define inf LLONG_MAX-1
#define init(a,x) memset(a,x,sizeof(a))
#define fastio() ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL)
#define nline "\n"

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef Athe1stB
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll tno = 1;
// const ll x[4] = {0, 1, 0, -1};
// const ll y[4] = {-1, 0, 1, 0};
// const ll x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
// const ll y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

ll dp[5003][5003];

ll MorBhai(ll n, ll k, ll m, vll &v)
{
    if(k==0)
        return 0;

    if(dp[n][k]!=-1)
        return dp[n][k];

    if(n-m>=0)
        return dp[n][k] = max(v[n]-v[n-m] + MorBhai(n-m,k-1,m,v), MorBhai(n-1,k,m,v));
    else
        return dp[n][k] = LLONG_MIN + 1;
}

void solve()
{
    cerr<<"\nCase #"<<tno<<":"<<"\n";

    ll n,m,k;
    cin>>n>>m>>k;

    vll v(n);
    ranit(it,v)cin>>it;

    init(dp,-1);

    vll prefix(n+1,0);
    forA(i,0,n,1)
        prefix[i+1] = prefix[i]+v[i];

    ll ans = MorBhai(n,k,m,prefix);

    cout<<ans;

    cerr<<"\n";
}

int main()
{
    fastio();
    auto start1 = high_resolution_clock::now();
    ll t=1;
    // cin>>t;
    while(t--)
        solve(),tno++;
    auto stop1 = high_resolution_clock::now();
    duration<double, milli> ms = stop1-start1;
        
    #ifdef Athe1stB
        cerr<<"Finished in "<< ms.count()<< " ms\n";
    #endif
        
    return 0;
}
