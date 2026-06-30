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
    vector<ll> v;

    cin>>n;
    for(ll i=0,x;i<n;++i){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    for(ll i=2;i<n;++i){
        if(v[i-2]%v[i-1]!=v[i]){
            cout<<"-1"<<endl;
            return ;
        }
    }

    cout<<v[0]<<" "<<v[1]<<endl;
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