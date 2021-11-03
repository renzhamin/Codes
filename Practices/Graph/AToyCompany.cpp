#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define d(x) mp[x[0]-'a'][x[1]-'a'][x[2]-'a']

int mp[26][26][26];
string st,en,u,c1,c2,fr[3],tmp;
int n,ans,qs;

int bfs(){
    if(d(st)==-1 || d(en)==-1)
        return -1;
    if(en==st) return 0;
    queue<string>q;
    q.push(st); d(st)=-1;
    while(!q.empty()){
        u=q.front(); q.pop();
        for(int i=0;i<3;i++){
            c1=c2=u;
            c1[i]=(u[i]-'a'+1)%26+'a';
            c2[i]=(u[i]-'a'+25)%26+'a';
            if(!d(c1)){
                d(c1)=d(u)+1;
                if(c1==en) return d(c1)+1;
                q.push(c1);
            }
            if(!d(c2)){
                d(c2)=d(u)+1;
                if(c2==en) return d(c2)+1;
                q.push(c2); 
            }
        }
    }
    return -1;
}

int main(){
    int t,T=1;cin>>t;
    while(t--){
        memset(mp,0,sizeof(mp));
        cin>>st>>en>>n;
        while(n--){
            cin>>fr[0]>>fr[1]>>fr[2];
            for(int i=0;i<fr[0].size();i++)
                for(int j=0;j<fr[1].size();j++)
                    for(int k=0;k<fr[2].size();k++){
                        tmp="";
                        tmp+=fr[0][i];tmp+=fr[1][j];tmp+=fr[2][k];
                        d(tmp)=-1;
                    }
        }
        cout<<"Case "<<T++<<": ";
        cout<<bfs()<<"\n";
    } 
}
