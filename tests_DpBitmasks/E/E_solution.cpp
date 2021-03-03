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
            
            int n,m;
            vector < vector < int > > a;
            vector < vector < int > > max_rotate;
            vector < vector < int > > f;
                    
            void solve(){
                cin>>n>>m;
                a.resize(n + 2,vector < int > (m + 2,0));
                for(int i = 0;i < n;++i){
                    for(int j = 0;j < m;++j){
                        cin>>a[i][j];
                    }
                }
                max_rotate.resize(m + 2,vector < int > ((1 << n) + 2,-INF));
                f.resize(m + 2,vector < int > ((1 << n) + 2,-INF));
                for(int j = 0;j < m;++j){
                    for(int mask = 0;mask < (1 << n);++mask){
                        for(int rot = 0;rot < n;++rot){
                            int mx = 0;
                            for(int i = 0;i < n;++i){
                                if((mask >> i) & 1){
                                    mx += a[(i + rot) % n][j];
                                }
                            }
                            maximize(max_rotate[j][mask],mx);
                        }
                    }
                }
                for(int mask = 0;mask < (1 << n);++mask){
                    f[0][mask] = max_rotate[0][mask];
                }
                for(int j = 1;j < m;++j){
                    for(int mask = 0;mask < (1 << n);++mask){
                        for(int submask = mask;true;submask = (submask - 1) & mask){
                            maximize(f[j][mask],f[j - 1][submask] + max_rotate[j][mask ^ submask]);
                            if(submask == 0){
                                break;
                            }
                        }
                    }
                }
                cout<<f[m - 1][(1 << n) - 1]<<'\n';
            }

            ~Solver(){} 
    };

    void solve(){
        int ntest = 1;
#ifndef  ONLINE_JUDGE
        ntest = 1; // single test to multitest.
#endif
        cin>>ntest;  // multitest
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
