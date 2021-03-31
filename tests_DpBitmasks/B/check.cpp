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

    int n,val,diff = 0;
    finp>>n;
    
    vector < int > a;
    while(finp >> val){
        a.emplace_back(val);
    }
    
    vector < int > author_ans;
    cout<<"AUTHOR:\n";
    while(fout >> val){
        author_ans.emplace_back(val);
        cout<<val<<' ';
    }
    cout<<'\n';
    for(int i = 0;i < n;++i){
        diff += (int)abs(a[i] - author_ans[i]);
    }
    
    vector < int > cper_ans;
    cout<<"CPER\n";
    while(fans >> val){
        cper_ans.emplace_back(val);
        cout<<val<<' ';
    }
    cout<<'\n';
    
    if((int)cper_ans.size() != n){
        ok = false;
    } else {
        int chk = true;
        for(int i = 0;i < n;++i){
            for(int j = i + 1;j < n;++j){
                if(__gcd(cper_ans[i],cper_ans[j]) != 1){
                    chk = false;
                }
            }
        }
        
        for(int i = 0;i < n;++i){
            diff -= (int)abs(a[i] - cper_ans[i]);
        }
        
        if(!chk or diff != 0){
            ok = false;
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

