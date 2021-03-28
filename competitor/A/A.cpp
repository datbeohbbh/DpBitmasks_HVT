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

            static const int N = 100;
            
            llong f(llong val){
                if(val <= 0){
                    return 0;
                }
                vector < int > digits;
                vector < vector < vector < llong > > > dp;
                vector < vector < vector < bool > > > ok;
                digits.emplace_back(0);
                for(;val > 0;val /= 10){
                    digits.emplace_back(val % 10);
                }
                
                dp.resize(len(digits) + 2,vector < vector < llong > > (N + 20,vector < llong > (2,0)));
                ok.resize(len(digits) + 2,vector < vector < bool > > (N + 20,vector < bool > (2,false)));

                dp[len(digits) - 1][0][1] = 1;
                ok[len(digits) - 1][0][1] = true;
                for(int pos = len(digits) - 1;pos > 0;--pos){
                    for(int sum = 0;sum <= N;++sum){
                        for(int flag = 0;flag < 2;++flag){
                            int bound = (flag ? digits[pos] : 9);
                            for(int k = 0;k <= bound;++k){
                                int new_flag = flag & (digits[pos] == k);
                                if(ok[pos][sum][flag] and sum + k <= N){
                                    dp[pos - 1][sum + k][new_flag] += dp[pos][sum][flag];
                                    ok[pos - 1][sum + k][new_flag] = ok[pos - 1][sum + k][new_flag] | ok[pos][sum][flag];
                                }
                            }
                        }
                    }
                }
                llong ans = 0;
                for(int sum = 0;sum <= N;++sum){
                    for(int flag = 0;flag < 2;++flag){
                        if(ok[0][sum][flag]){
                            ans += dp[0][sum][flag] * (llong)sum;
                        } 
                    }
                }
                return ans;
            }
            
            void solve(){
                int l,r;
                while(cin>>l>>r){
                    if(l == r and r == -1){
                        break;
                    }
                    llong ans = 0;
                    cout<<f(r) - f(l - 1)<<'\n';
                }
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

