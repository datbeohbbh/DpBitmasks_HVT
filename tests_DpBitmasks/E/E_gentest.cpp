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

    const int T = 40;
    const int N = 4;
    const int M = 100;
    const int MAX_VALUE = (int)1e5;
    
    void solve(){
        auto func = [](const tuple < int,int,int,int,int,int > &t) -> void{
            int L_T,R_T;
            int L_N,R_N;
            int L_M,R_M;
            tie(L_T,R_T,L_N,R_N,L_M,R_M) = t;
            int numTest = L_T + rand(R_T - L_T + 1);
            cout<<numTest<<'\n';
            for(int _ = 1;_ <= numTest;++_){
                int n = L_N + rand(R_N - L_N + 1);
                int m = L_M + rand(R_M - L_M + 1);
                cout<<n<<' '<<m<<'\n';
                for(int i = 1;i <= n;++i){
                    for(int j = 1;j <= m;++j){
                        cout<<1 + rand(MAX_VALUE)<<' ';
                    }
                    cout<<'\n';
                }
            }
        };
        tuple < int,int,int,int,int,int > p[] = {
            {1,20,1,3,1,20},
            {1,20,3,4,10,20},
            {20,40,3,4,30,50},
            {40,40,3,4,60,100},
            {40,40,4,4,50,80},
            {40,40,4,4,90,100}
        };
        int coins = rand(6);
        func(p[coins]);
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Task::solve();
}

