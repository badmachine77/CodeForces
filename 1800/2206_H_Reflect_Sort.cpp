#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100100];
ll n;

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    ll gcd = -1;
    ll difs = llabs(a[2]-a[1]);
    if(llabs(a[2]-a[1])!=0)gcd = llabs((a[2]-a[1])*2ll);
    
    for(int i=3;i<=n;++i){
        if(a[i]!=a[i-1]){
            if(gcd==-1)gcd = llabs((a[i]-a[i-1])*2ll);
            else gcd = __gcd(gcd,llabs((a[i]-a[i-1])*2ll));
        }
        difs += llabs(a[i]-a[i-1]);
    }


    if(gcd==-1){
        cout<<a[1]<<endl;
        return ;
    }

    ll minfirst = a[1];
    if(a[1]%gcd==0)minfirst = min(minfirst,gcd);
    else minfirst = min(minfirst,a[1]%gcd);

    cout<<minfirst+difs<<endl;
    return ;
}

int main(){

    ll t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*

x8 = x10*2 - x8
x8 = x10*2 - x9*2 + x8
x9 = x10*2 - x9
x1 = x10*2 - x1

x1 = x10*2 - x9*2 + x1

x10*2 - x9*2 + x8*2 - x1


*/