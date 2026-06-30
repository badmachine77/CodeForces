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
ll n;

void solve(){
    v.clear();
    cin>>n;
    char c,cc;
    ll num=1;
    cin>>cc;
    for(ll i=1;i<n;++i){
        cin>>c;
        if(c!=cc){
            v.push_back({cc-'0',num});
            cc=c;
            num=1;
        }
        else {
            ++num;
        }
    }
    v.push_back({cc-'0',num});

    if(v[0].first==0)v.erase(v.begin()+0);
    if(v.empty()){
        cout<<"Bob"<<endl;
        return ;
    }
    if(v[v.size()-1].first==1)v.erase(v.end()-1);
    if(v.size()<2){
        cout<<"Bob"<<endl;
        return ;
    }

    ll s = 0;
    for(ll i=1;i<v.size();i+=2){
        s+=v[i].second;
    }
    if(s%2==1){
        cout<<"Alice"<<endl;
        return ;
    }
    for(ll i=1;i<v.size();i+=2){
        if(v[i].second%2==1){
            cout<<"Alice"<<endl;
            return ;
        }
    }
    s=0;
    for(ll i=0;i<v.size();i+=2){
        s+=v[i].second;
    }
    if(s%2==1){
        cout<<"Alice"<<endl;
        return ;
    }
    for(ll i=0;i<v.size();i+=2){
        if(v[i].second%2==1){
            cout<<"Alice"<<endl;
            return ;
        }
    }

    cout<<"Bob"<<endl;
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