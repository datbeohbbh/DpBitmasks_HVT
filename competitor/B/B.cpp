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
 
    vector < int > primes;
    class Solver{
        public:
 
            static const int N = 100;
            vector < vector < vector < vector < int > > > > dp;
            
            int f(int val){
                if(val <= 0){
                    return 0;
                }
                vector < int > digits;
                digits.emplace_back(0);
                for(;val > 0;val /= 10){
                    digits.emplace_back(val % 10);
                }
                dp.assign(len(digits) + 2,vector < vector < vector < int > > > ((N + 10) / 2,vector < vector < int > > ((N + 10) / 2,vector < int > (2,-1))));
                dp[len(digits) - 1][0][0][1] = 1;
                for(int pos = len(digits) - 1;pos > 0;--pos){
                    for(int E = 0;2 * E <= N;++E){
                        for(int O = 0;2 * O <= N;++O){
                            for(int flag = 0;flag < 2;++flag){
                                int bound = flag ? digits[pos] : 9;
                                for(int k = 0;k <= bound;++k){
                                    int new_flag = flag & (digits[pos] == k);
                                    if(dp[pos][E][O][flag] == -1){
                                        continue;
                                    }
                                    int &cur = dp[pos - 1][E + (!(pos & 1) ? k : 0)][O + (pos & 1 ? k : 0)][new_flag];
                                    if(cur == -1){
                                        cur = dp[pos][E][O][flag];
                                    } else {
                                        cur += dp[pos][E][O][flag];
                                    }
                                }
                            }
                        }
                    }
                }
                int ans = 0;
                for(int E = 0;2 * E <= N;++E){
                    for(int i = 0;i < len(primes);++i){
                        if(E >= primes[i]){
                            for(int flag = 0;flag < 2;++flag){
                                if(dp[0][E][E - primes[i]][flag] != -1){
                                    ans += dp[0][E][E - primes[i]][flag];
                                }
                            }
                        }
                    }
                }
                return ans;
            }
            
            void solve(){
                int l,r; cin>>l>>r;
                cout<<f(r) - f(l - 1)<<'\n';
            }
 
            ~Solver(){} 
    };
 
    void solve(){
        int ntest = 1;
#ifndef  ONLINE_JUDGE
        ntest = 1; // single test to multitest.
#endif
        for(int i = 2;i <= 100;++i){
            bool ok = true;
            for(int j = 2;j * j <= i;++j){
                if(i % j == 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                primes.emplace_back(i);
            }
        }
        cin>>ntest;  // multitest
        while(ntest--){
            Solver().solve();
        }
    }
}
 
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Task::solve();
}
