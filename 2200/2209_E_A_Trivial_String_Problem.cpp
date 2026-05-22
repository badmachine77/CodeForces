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

ll f[1000100];
ll mins[1000100];
ll lps[1000100];
ll a[1000100];
ll used[1000100];
ll n,q;

void solve(){
    //cout<<"------------\n";
    cin>>n>>q;
    char cc;
    for(int i=1;i<=n;++i){
        cin>>cc;
        a[i]=cc-'a';
    }

    for(int i=0;i<=n+10;++i){
        f[i]=0;
        mins[i]=0;
        lps[i]=0;
        used[i] = 1e9;
    }

    ll l,r,res;
    while(q--){
        cin>>l>>r;

        lps[1] = 0;
        f[1] = 1;
        res = 1;
        mins[0] = 1e9;
        used[0] = q;
        ll i,x;
        for(int cnt=l+1;cnt<=r;++cnt){
            i = cnt-l+1;

            x=lps[i-1];
            
            //cout<<x<<" "<<cnt<<" "<<q<<endl;
            while(true){
                if(a[cnt]==a[l+x]){
                    break;
                }
                if(x==0){
                    x=-1;
                    break;
                }
                
                x = lps[x];
                //cout<<x<<" "<<cnt<<" "<<q<<endl;
            }

            if(x==-1){
                lps[i]=0;
                f[i]=1;
                ++res;
                continue;
            }

            lps[i]=x+1;
            if(used[x+1]!=q){
                used[x+1]=q;
                mins[x+1] = min(x+1,mins[lps[x+1]]);
            }

            f[i] = f[i-mins[x+1]]+1;
            res+=f[i];
        }

        /*
        cout<<endl;
        for(int i=l;i<=r;++i){
            cout<<f[i]<<" ";
        }cout<<endl;
        for(int i=l;i<=r;++i){
            cout<<lps[i]<<" ";
        }cout<<endl;
        for(int i=l;i<=r;++i){
            cout<<mins[i]<<" ";
        }cout<<endl;
        */
        cout<<res<<endl;
        //cout<<endl;
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
6
1 1
a
1 1
5 2
aaaaa
1 5
2 4
6 2
abcdef
1 6
3 5
6 3
abaaba
1 6
1 3
2 6
7 3
abcabca
1 7
2 7
4 7
8 3
aababaac
1 8
2 8
3 7

*/