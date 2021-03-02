using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define sz(c) ((c).size())
#define all(c) (c).begin(),(c).end()
#define fn "test"   ///____FILE_NAME_HERE_____
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rrep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)

template <class T,class U> void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U> void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T> T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T> T safe_sqrt(T x)
{
    return sqrt(max((T)0,x));
}
template <class T,class U,class V> T addmod(T x,U k,V mod)
{
    return ((x + k)%mod + mod) % mod;
}
template <class T,class U,class V> T submod(T x,U k,V mod)
{
    return ((x - k)%mod + mod) % mod;
}
template <class T,class U,class V> T mulmod(T x,U k,V mod)
{
    return (ll)x*k%mod;
}

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=18;
ll dp[101][MASK(N)];
vector <int> digits;
ll n,ans;
int m;
int cnt[10];
ll ft[20];

void solve()
{
    cin>>n>>m;
    while(n)digits.pb(n%10),n/=10;
    rep(digits,it)cnt[*it]++;
    ft[0]=1;
    for(int i=1;i<=18;++i)ft[i]=ft[i-1]*1ll*i;
    dp[0][0]=1;
    for(int mask=0;mask < MASK(sz(digits));++mask)
        for(int mod=0;mod < m;++mod)
            for(int i=0;i<sz(digits);++i)
        {
            if(!mask and !digits[i])continue;
            if(BIT(mask,i))continue;
            dp[(mod*(10 % m) + digits[i])%m][mask ^ MASK(i)]+=dp[mod][mask];
        }
    ans=dp[0][MASK(sz(digits))-1];
    for(int i=0;i<=9;++i)
        ans/=ft[cnt[i]];
    cout<<ans<<'\n';
}}

int main(void)
{
    #ifndef ONLINE_JUDGE
    // freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
