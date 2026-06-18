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

vector<pair<ll,ll>> v;
ll a[110];
ll n;

void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }

    v.clear();

    v.push_back({a[n],n});
    for(ll i=n-1;i>0;--i){
        while(!v.empty()){
            if(v[v.size()-1].first>=a[i]){
                v.pop_back();
            }
            else {
                break;
            }
        }

        v.push_back({a[i],i});
    }

    ll res=0;
    res += v[0].first * (n-v[0].second+1);

    for(ll i=1;i<v.size();++i){
        res+=v[i].first * (v[i-1].second-v[i].second);
    }
    cout<<res<<endl;
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
10
3
1 3 5
3
5 4 3
4
3 2 5 1
4
2 1 4 3
5
4 1 3 5 2
5
2 2 3 1 4
1
7
6
6 1 5 2 4 3
4
1 1 1 1
5
10 3 8 6 9

*/