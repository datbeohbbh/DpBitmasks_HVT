#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rand __rand
    mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
    template <class T = int>
    T rand(T range = numeric_limits <T> :: max()){
        return (T) (generator() % range);
    }
}
using namespace DEBUG;

template <class T,class U>
void maximize(T &lhs,U rhs){
    if(lhs < rhs)lhs = rhs;
}
template <class T,class U>
void minimize(T &lhs,U rhs){
    if(lhs > rhs)lhs = rhs;
}
template <class T>
T tabs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong int64_t
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define file_name "test"    /// FILE NAME HERE!!!

/* ================================= END OF TEMPLATE ================================= */

namespace Task{

    class Solver{
        public:

            const int N = 16;
            const int INF = 1e9;
            vector < vector < int > > c;
            vector < vector < int > > dp;
            int n;
            
            void solve(){
                cin>>n;
                c.resize(n + 2,vector < int > (n + 2,0));
                for(int i = 0;i < n;++i){
                    for(int j = 0;j < n;++j){
                        cin>>c[i][j];
                    }
                }
                dp.resize(n + 2,vector < int > (1 << N,INF));
                for(int i = 0;i < n;++i){
                    dp[i][1 << i] = 0;
                }
                for(int mask = 0;mask < (1 << n);++mask){
                    for(int u = 0;u < n;++u){
                        if(!((mask >> u) & 1)){
                            for(int v = 0;v < n;++v){
                                if((mask >> v) & 1){
                                    minimize(dp[u][mask | (1 << u)],dp[v][mask] + c[v][u]);
                                }
                            }
                        }
                    }
                }
                int ans = INF;
                for(int u = 0;u < n;++u){
                    minimize(ans,dp[u][(1 << n) - 1]);
                }
                cout<<ans<<'\n';
            }

            ~Solver(){} 
    };

    void solve(){
        int ntest = 1;
#ifndef  ONLINE_JUDGE
        ntest = 1; // single test to multitest.
#endif
        //cin>>ntest;  // multitest
        while(ntest--){
            Solver().solve();
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen(file_name".inp","r",stdin);
    //freopen(file_name".out","w",stdout);	
    #endif // ONLINE_JUDGE
    Task::solve();
}
