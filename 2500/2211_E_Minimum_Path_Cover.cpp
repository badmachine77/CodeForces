#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll mod197 = 1e9 + 7;

vector<ll> fact;

ll fastpow(ll number,ll power,ll mod){
    ll answer = 1;
    
    while(power){
        if(power%2){
            answer = (answer * number) % mod;
        }
        number = (number * number) % mod;
        power /= 2;
    }

    return answer;
}

void init_fact(ll n, ll mod){
    fact = vector<ll>(n+1);

    fact[0]=1;
    for(ll i=1;i<=n;++i){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

ll C(ll from,ll take, ll mod){
    ll res = fact[from];
    res = (res*fastpow(fact[take],mod-2,mod))%mod;
    res = (res*fastpow(fact[from-take],mod-2,mod))%mod;
    return res;
}

vector<ll> vals[200200];
ll res[200200];
ll n;

void solve(){
    cin>>n;
    fill(res,res+(n+1),0);

    for(int i=0;i<=n;++i){
        vals[i].clear();
    }

    ll curval,curcnt,child_res_sum;
    vector<ll> helper;

    for(ll i=n;i>0;--i){
        cin>>curval>>curcnt;
        
        child_res_sum = 0;

        for(ll j=0,neigh_id;j<curcnt;++j){
            cin>>neigh_id;

            child_res_sum += res[neigh_id];
            for(ll h=0,x;h<vals[neigh_id].size();++h){
                x = __gcd(vals[neigh_id][h],curval);
                if(x!=1)vals[i].push_back(x);
            }
        }

        if(vals[i].size()==0){
            res[i] = child_res_sum + 1;
            vals[i].clear();
            vals[i].push_back(curval);
            cout<<res[i]<<endl;
            cout.flush();
            continue;
        }

        helper.clear();
        helper.push_back(vals[i][vals[i].size()-1]);
        vals[i].pop_back();
        
        ll x,helperid=0,gc;
        while(!vals[i].empty()){
            if(helperid==helper.size()){
                helperid=0;
                helper.push_back(vals[i][vals[i].size()-1]);
                vals[i].pop_back();
                continue;
            }

            x=vals[i][vals[i].size()-1];
            if(x==1){
                vals[i].pop_back();
                continue;
            }

            gc=__gcd(x,helper[helperid]);
            if(gc==helper[helperid]){
                vals[i][vals[i].size()-1]/=gc;
                continue;
            }
            else if(gc==1){
                ++helperid;
                continue;
            }
            else {
                vals[i][vals[i].size()-1]/=gc;
                helper[helperid]/=gc;
                vals[i].push_back(gc);
                continue;
            }
        }

        vals[i] = move(helper);
        res[i] = child_res_sum;
        cout<<res[i]<<endl;
        cout.flush();
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
/*
1
5
11 0
7 0
5 0
3 2 4 5
2 2 2 3

4
5
11 0
7 0
5 0
3 2 4 5
2 2 2 3
5
10 0
8 0
6 0
4 0
2 4 2 3 4 5
6
221 0
143 1 6
77 1 5
35 1 4
15 1 3
6 1 2
3
1000000000000000000 0
999999999999999998 0
999999999999999998 2 3 2

*/