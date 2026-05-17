#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod197 = 1e9 + 7;

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

ll fact[100100];
ll b[100100];
ll num[30];
ll n;

ll C(ll n,ll r){
    return (((fact[n] * fastpow(fact[r],mod197-2,mod197))%mod197)*fastpow(fact[n-r],mod197-2,mod197))%mod197;
}

void solve(){
    for(int i=0;i<30;++i)num[i]=0;


    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>b[i];
    }

    ll now;
    ll sum = 0;
    ll innersum = 0;
    for(int i=n;i>0;--i){
        now = b[i];

        innersum = 0;
        for(int j=0;j<29;++j){
            if(num[j]==0)continue;

            innersum = (innersum + (C(num[j],i)*(1<<j))%mod197)%mod197;
        }

        now = (now + mod197 - innersum) % mod197;
        
        for(int j=0;j<29;++j){
            if(now&(1<<j)){
                num[j] = i;
            }
        }
    }


    ll x;
    for(int i=1;i<n;++i){
        x = 0;
        for(int j=0;j<29;++j){
            if(num[j]){
                x+=(1<<j);
                --num[j];
            }
        }

        cout<<x<<" ";
    }
    x = 0;
    for(int j=0;j<29;++j){
        if(num[j])x+=(1<<j);
        --num[j];
    }
    cout<<x<<endl;
}

int main(){
    fact[0] = 1;
    for(int i=1;i<=100005;++i){
        fact[i] = (fact[i-1] * i) % mod197;
    }

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
22 24 10 1 0


3
3
0 0 0
5
22 24 10 1 0
10
130 585 1560 2730 3276 2730 1560 585 130 13
*/