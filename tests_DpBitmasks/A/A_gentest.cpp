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

    const int N = 18;
    const int MAX_VALUE = (int)1e9 + 1;
    
    void solve(){
        int coins = rand(2);
        int n = (coins ? 1 + rand(N) : 14 + rand(5));
        int m = (coins ? 1 + rand(n) : n);
        
        int l = n * (n - 1) / 2;
        int r = n * (n - 1);
        
        int k = (coins ? rand(n * (n - 1) + 1) : l + rand(r - l + 1));
        cout<<n<<' '<<m<<' '<<k<<'\n';
        for(int i = 1;i <= n;++i){
            cout<<rand(MAX_VALUE)<<' ';
        }
        cout<<'\n';
        vector < pair < int,int > > pairs;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                if(i == j){
                    continue;
                }
                pairs.emplace_back(make_pair(i,j));
            }
        }
        shuffle(pairs.begin(),pairs.end(),generator);
        assert(len(pairs) >= k);
        for(int i = 0;i < k;++i){
            pair < int,int > p = pairs[i];
            cout<<p.first<<' '<<p.second<<' '<<rand(MAX_VALUE)<<'\n';
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Task::solve();
}

