#include <bits/stdc++.h>

using namespace std;

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

// success signal is 0, else fail

ifstream finp,fout,fans;

void init_ifstream(string init_finp,string init_fout,string init_fans){
    finp.open(init_finp,ifstream::in);
    fout.open(init_fout,ifstream::in);
    fans.open(init_fans,ifstream::in);
}

void close_ifstream(){
    finp.close();
    fout.close();
    fans.close();
}

int message(int flag){
    if(!flag){
        // success message
        cout<<"> competitor's answer is OK!!\n";
    } else {
        cout<<"> competitor found wrong answer.\n";
    }
    return flag;
}

int check(){
    // ok show if competitor's answer is correct - 0/1 <=> wrong/correct.
    int ok = 1;
    
    vector < pair < int,int > > segs;
    int n,a,b;
    
    finp >> n >> a >> b;
    for(int i = 1;i <= n;++i){
        int l,h;
        finp >> l >> h;
        segs.emplace_back(make_pair(l,h));
    }
    
    int author_ans; fout >> author_ans;
    int cper_ans; fans >> cper_ans;

    if(author_ans != cper_ans){
        ok = 0;
    } else {
        if(author_ans == -1){
            ok = 1;
        } else {
            int seg_idx;
            vector < int > sum(b + 2,0);
            while(fans >> seg_idx){
                if(seg_idx < 1 or seg_idx > n){
                    ok = 0;
                    break;
                }
                --seg_idx;
                pair < int,int > p = segs[seg_idx];
                ++sum[p.first];
                --sum[p.second + 1];
            }
            for(int i = 1;i <= b;++i){
                sum[i] += sum[i - 1];
                if(i >= a and sum[i] == 0){
                    ok = 0;
                    break;
                }
            }
        }
    }

    // do not edit 'return' line.
    return message(ok ? 0 : 1);
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(argc != 4){
        exit(1);
    } else {
        init_ifstream(argv[1],argv[2],argv[3]);
        int signal = check();
        close_ifstream();
        cout<<'\n';
        exit(signal);
    }
}
