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

            static const int LCM = 2520;
            static const int N = 20;
            static const int MAXDIGITS = 10;
            //llong dp[N + 2][(1 << MAXDIGITS) + 2][LCM + 2][2];

            llong f(llong val,int lim){
                if(val <= 0){
                    return 0;
                }
                vector < int > digits; digits.emplace_back(0);
                for(;val > 0;val /= 10){
                    digits.emplace_back(val % 10);
                }
                int L = len(digits);
                llong dp[L + 2][(1 << MAXDIGITS) + 2][LCM + 2][2] = {-1};
                //memset(dp,-1,sizeof(dp));
                //vector < vector < vector < vector < llong > > > > 
                //dp(L + 1,vector < vector < vector < llong > > > ((1 << MAXDIGITS) + 1,vector < vector < llong > > (LCM + 1,vector < llong > (2,-1))));
                dp[len(digits) - 1][0][0][1] = 1;
                for(int pos = len(digits) - 1;pos > 0;--pos){
                    for(int mask = 0;mask < (1 << MAXDIGITS);++mask){
                        for(int rm = 0;rm < LCM;++rm){
                            for(int flag = 0;flag < 2;++flag){
                                if(dp[pos][mask][rm][flag] != -1){
                                    int bound = flag ? digits[pos] : 9;
                                    for(int k = 0;k <= bound;++k){
                                        int new_flag = flag & (digits[pos] == k);
                                        int new_mask = mask | k ? mask | (1 << k) : 0;
                                        int new_rm = (rm * 10 + k) % LCM;
                                        llong &cur = dp[pos - 1][new_mask][new_rm][new_flag];
                                        if(cur == -1){
                                            cur = dp[pos][mask][rm][flag];
                                        } else {
                                            cur += dp[pos][mask][rm][flag];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                llong ans = 0;
                for(int mask = 0;mask < (1 << MAXDIGITS);++mask){
                    if(__builtin_popcount(mask) >= lim){
                        for(int rm = 0;rm < LCM;++rm){
                            int cnt = 0;
                            for(int i = 1;i < MAXDIGITS;++i){
                                if(mask & (1 << i)){
                                    cnt += (rm % i == 0);
                                }
                            }
                            if(cnt < lim){
                                continue;
                            }
                            for(int flag = 0;flag < 2;++flag){
                                if(dp[0][mask][rm][flag] != -1){
                                    ans += dp[0][mask][rm][flag];
                                }
                            }
                        }
                    }
                }
                return ans;
            }
            
            void solve(){
                llong l,r; int k; cin>>l>>r>>k;
                cout<<f(r,k) - f(l - 1,k)<<'\n';
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
    Task::solve();
}

