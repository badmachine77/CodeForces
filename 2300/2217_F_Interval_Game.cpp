#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
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

ll calc(ll x, ll ub){
    if(ub<=x)return 0;
    ll free = ub-x-1;
    ll cnt=0;
    for(ll i=22;i>=0;--i){
        if(x&(1<<i))continue;
        cnt*=2;
        if(free>=(1<<i)*2){
            cnt+=1;
            free-=(1<<i)*2;
        }
    }
    ++cnt;
    
    ll more=1;
    for(ll i=22;i>=0;--i){
        if(x&(1<<i)){
            more*=2;
        }
    }
    cnt*=more;

    return cnt;
}

void solve(){
    ll x,y;
    cin>>x>>y;

    ll miny = 1e9,idy=0,c;
    for(ll i=0;i<x;++i){
        c=calc(i,y);

        //cout<<i<<" "<<c<<endl;

        if(c<miny){
            miny = c;
            idy = i;
        }
    }

    cout<<idy+1<<" "<<x<<endl;
    //cout<<endl;
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
6
1 1
1 10
2 1
2 2
20 64578
185367 133524
*/