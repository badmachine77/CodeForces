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

void solve(){
    ll n;
    char ch[200];

    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>ch[i];
    }

    ll trans = 0;
    for(ll i=2;i<=n;++i){
        if(ch[i]!=ch[i-1])++trans;
    }

    if(ch[1]==ch[n]){
        cout<<"1"<<endl;
    }
    else {
        if(trans>1)cout<<"1"<<endl;
        else cout<<"2"<<endl;
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