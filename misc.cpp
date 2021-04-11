#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	
	ll t,q,d;
	cin>>t>>q>>d;
	while(t--)
	{
	    ll lx =(-1LL)*1e18, rx=1e18, ly=lx, ry=rx; 
	    lx--;
	    rx++;
	    ly--;
	    ry++;
	    ll curr=1;
	    string cc;
	    ll z=-1;
	    while(true){
	        if(curr==1)
	        {
	            if(rx>=(lx+2) && ry>=(ly+2))
	            {
	                ll midx=(rx+lx)/2;
	                ll midy=(ry+ly)/2;
	                cout<<curr<<" "<<midx<<" "<<midy<<endl;
	                cin>>cc;
	                if(cc.compare("O")==0 || cc.compare("FAILED")==0)
	                break;
	                if(cc[0]=='X')
	                {
	                    lx=midx-1;
	                    rx=midx+1;
	                }else if(cc[0]=='P')
	                    {
	                    if(d==0)
	                    {
	                        rx=midx-1;
	                    }else
	                    {
	                        rx=midx;
	                        lx--;
	                    }
	                }else
	                    {
	                    if(d==0)
	                    {
	                        lx=midx+1;
	                    }else
	                        {
	                        lx=midx;
	                        rx++;
	                        }
	                    }
	                if(cc[1]=='V')
	                {
	                    ly=midy-1;
	                    ry=midy+1;
	                }
	                else if(cc[1]=='P')
	                {
	                if(d==0)
	                {
	                    ry=midy-1;
	                }else{
	                    ry=midy;
	                    ly--;
	                }
	            }
	            else{
	                if(d==0)
	                {
	                    ly=midy+1;
	                }else{
	                    ly=midy;
	                    ry++;
	                }
	            }
	            if(d==0)
	            {
	                
	            }else{
	                if((rx<=(lx+3))&&((ry<=(ly+3)))
	                {
	                    curr=2;
	                }
	            }
	        }
	        else{
	            curr=2;
	            cout<<curr<<" "<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<endl;
	            cin>>cc;
	            break;
	        }
	    }
	    else{
	        if((rx==(lx+3))&&((ry==(ly+3)))){
	            cout<<curr<<" "<<lx<<" "<<ly<<" "<<lx+2<<" "<<ry<<endl;
	            cin>>cc;
	            if(cc.compare("O")==0){
	            break;
	            }
	            else if(cc.compare("IN")==0){
	                rx=lx+2;
	            }
	            else{
	                lx=lx+2;
	                rx++;
	            }
	        }
	        if((rx==(lx+2))&&((ry==(ly+3)))){
	            cout<<curr<<" "<<lx<<" "<<ly<<" "<<rx<<" "<<ly+2<<endl;
	            cin>>cc;
	            if(cc.compare("O")==0){
	                
	            }
	            else if(cc.compare("IN")==0){
	                cout<<curr<<" "<<lx<<" "<<ly<<" "<<rx<<" "<<ly+2<<endl;
	                cin>>cc;
	            }
	            else{
	                cout<<curr<<" "<<lx<<" "<<ly+2<<" "<<rx<<" "<<ly+4<<endl;
	                cin>>cc;
	            }
	            break;
	        }
	        if((rx==(lx+3))&&((ry==(ly+2)))){
	            cout<<curr<<" "<<lx<<" "<<ly<<" "<<lx+2<<" "<<ry<<endl;
	            cin>>cc;
	            if(cc.compare("O")==0){
	                
	            }else if(cc.compare("IN")==0){
	                cout<<curr<<" "<<lx<<" "<<ly<<" "<<lx+2<<" "<<ry<<endl;
	                cin>>cc;
	            }
	            else{
	                cout<<curr<<" "<<lx+2<<" "<<ly<<" "<<lx+4<<" "<<ry<<endl;
	                cin>>cc;
	                }
	                break;
	       }
	       else{
	           cout<<curr<<" "<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<endl;
	           cin>>cc;
	           break;
	       }
	   }
	   cout.flush();
    }
	 cout.flush();
 }
}
			   ///
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
vector<long long> graph[100001];
long long A[1000001];
long long B[1000001];
long long con[1000001];
long long a[100001];
long long b[100001];
long long par[100001];
long long h[100001];
long long vis[100001];
vector<long long> sset;
priority_queue<pair<long long,long long> >LT;
long long n,s;
long long TEMP;
void solve(long long SUP, long long d)
{
    vis[SUP]++;
    h[SUP] = d;
    bool is_it = true;
    for(long long CHD:graph[SUP])
    {
        if(!vis[CHD])
        {
            par[CHD] = SUP;
            solve(CHD,d+1);
            is_it = false;
        }
    }
    if(is_it==true)
        LT.push({d,SUP});
}
void done()
{
    for(long long i=0; i<n+1; i++)
    {
        graph[i].clear();
        a[i]=0;
        b[i]=0;
        par[i]=0;
        h[i]=0;
    }
    while(!LT.empty())
       LT.pop();
}
void clean(long long SUP)
{
    con[a[SUP]]=0;
    con[b[SUP]]=0;
    A[a[SUP]]=0;
    A[b[SUP]]=0;
    B[a[SUP]]=0;
    B[b[SUP]]=0;
}
int solve2(long long SUP)
{
    B[b[SUP]]++;
    A[a[SUP]]++;
    if(A[a[SUP]]==B[a[SUP]]&&con[a[SUP]]!=0)
    {
        con[a[SUP]]--;
        TEMP--;
    }
    else if(con[a[SUP]]==0)
    {
        con[a[SUP]]++;
        TEMP++;
    }
    if(A[b[SUP]]==B[b[SUP]]&&con[b[SUP]]!=0)
    {
        con[b[SUP]]--;
        TEMP--;
    }
    else if(con[b[SUP]]==0)
    {
        con[b[SUP]]++;
        TEMP++;
    }
    vis[SUP]++;
    sset.push_back(SUP);
    if(TEMP==0)
    {
        if(vis[par[SUP]]==0&&SUP!=1)
            LT.push(make_pair(h[par[SUP]], par[SUP]));
        clean(SUP);
        return 1;
    }
    if(SUP==1)
    {
        clean(SUP);
        return 0;
    }
    if(vis[par[SUP]]==0)
    {
        if(solve2(par[SUP])==1)
        {
            clean(SUP);
            return 1;
        }
    }
    clean(SUP);
    return 0;
}
int sol()
{
    cin>>n>>s;
    for(long long i=0; i<n; i++)
    {
        long long u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(long long i=1; i<n+1; i++)
    cin>>a[i];
    for(long long i=1; i<n+1; i++)
    cin>>b[i]
    for(long long i=1; i<n+1; i++)
    {
        vis[i]=0;
        par[i]=0;
        h[i]=0;
    }
    solve(1,1);
    for(long long i=1; i<n+1; i++)
        vis[i]=0;
    bool correct = true;
    vector<vector<long long> > sets;
    while(!LT.empty())
    {
        pair<long long, long long> leaf = LT.top();
        LT.pop();
        if(vis[leaf.second]==0)
        {
            TEMP = 0;
            sset.clear();
            if(solve2(leaf.second)==0)
            {
                correct = false;
                break;
            }
            else
               sets.push_back(sset);
        }
    }
    if(correct==false)
    {
        cout<<0<<endl;
        return 0;
    }
    if(s==1)
    {
        cout<<1<<endl;
        return 0;
    }
    long long a = 1;
    long long x = sets.size();
    for(long long i=0; i<x; i++)
    {
        long long u = sets[i][0];
        long long l = sets[i][0];
        long long sze = sets[i]size();
        for(long long j=1; j<sze; j++)
        {
            if(h[sets[i][j]]>h[l])
              l = sets[i][j];
            if(h[sets[i][j]]<h[u])
              u = sets[i][j];
              
        }
        long long cnt = 0;
        for(long long c:graph[1])
        {
            if(c!par[l])
            cnt++;
        }
        a = (a*(cnt+1))%mod;
    }
    cout<<a<<endl;
    return 0;
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        sol();
        done();
    }
    return 0;
}
