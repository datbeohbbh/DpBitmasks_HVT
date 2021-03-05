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

    const int INF = 2e9;
    class Solver{
        public:

            vector < pair < int, int > > c;
            vector < pair < int, int > > trace;
            vector < vector < int > > dist;
            vector < int > f;
            int n;
            
            void solve(){
                c.resize(30,{0,0});
                cin>>c[0].first>>c[0].second>>n;
                for(int i = 1;i <= n;++i){
                    cin>>c[i].first>>c[i].second;
                }
                dist.resize(n + 2,vector < int > (n + 2,0));
                auto calc = [&](pair < int,int > x,pair < int,int > y) -> int{
                    return (y.first - x.first) * (y.first - x.first) + (y.second - x.second) * (y.second - x.second);
                };
                for(int i = 0;i <= n;++i){
                    for(int j = 0;j <= n;++j){
                        dist[i][j] = calc(c[i],c[j]);
                    }
                }
                f.resize((1 << n) + 2,INF);
                trace.resize((1 << n) + 2,{-1,-1});
                f[0] = 0;
                for(int mask = 0;mask < (1 << n);++mask){
                    for(int i = 0;i < n;++i){
                        if(!BIT(mask,i)){
                            if(f[mask | (1 << i)] > f[mask] + 2 * dist[0][i + 1]){
                                f[mask | (1 << i)] = f[mask] + 2 * dist[0][i + 1];
                                trace[mask | (1 << i)] = {-1,(1 << i)};
                            }
                            for(int j = i + 1;j < n;++j){
                                if(!BIT(mask,j)){
                                    if(f[mask | (1 << i) | (1 << j)] > f[mask] + dist[0][i + 1] + dist[i + 1][j + 1] + dist[j + 1][0]){
                                        f[mask | (1 << i) | (1 << j)] = f[mask] + dist[0][i + 1] + dist[i + 1][j + 1] + dist[j + 1][0];
                                        trace[mask | (1 << i) | (1 << j)] = {(1 << i),(1 << j)};
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
                cout<<f[(1 << n) - 1]<<'\n';
                int mask = (1 << n) - 1;
                vector < int > ans;
                vector < int > lg((1 << n) + 2,0);
                int h = 0;
                while(h <= n){
                    lg[1 << h] = h;
                    ++h;
                }
                while(true){
                    ans.emplace_back(0);
                    if(trace[mask] == make_pair(-1,-1)){
                        break;
                    }
                    ans.emplace_back(lg[trace[mask].second] + 1);
                    if(~trace[mask].first){
                        ans.emplace_back(lg[trace[mask].first] + 1);
                    }
                    mask ^= trace[mask].second ^ (~trace[mask].first ? trace[mask].first : 0);
                }
                reverse(ans.begin(),ans.end());
                for(int p : ans){
                    cout<<p<<' ';
                }
                cout<<'\n';
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
