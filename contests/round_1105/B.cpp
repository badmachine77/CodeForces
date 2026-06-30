#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll mod197 = 1e9 + 7;

const ll mod99 = 998244353;

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

void solve(){
    ll n,m,r,c;

    cin>>n>>m>>r>>c;

    if(r==1 && c==1){
        cout<<1<<endl;
    }
    else if(r==1){
        ll res = fastpow(2,c-1,mod99);
        res = fastpow(res,n,mod99);
        cout<<res<<endl;
    }
    else if(c==1){
        ll res = fastpow(2,r-1,mod99);
        res = fastpow(res,m,mod99);
        cout<<res<<endl;
    }
    else {
        ll res = fastpow(2,r,mod99);
        res = fastpow(res,c,mod99);
        res = ((res*fastpow(2,mod99-2,mod99)%mod99)+mod99)%mod99;

        if(n>r){
            res = (res*fastpow(2,(c-1)*(n-r),mod99))%mod99;
        }
        if(m>c){
            res = (res*fastpow(2,(r-1)*(m-c),mod99))%mod99;
        }
        cout<<res<<endl;
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

*/