/* GSS1: CAN YOU ANSWER THE QUERIES*/


#include<bits/stdc++.h>
using namespace std;
struct tr
{
int ms,rs,s,ls;
};
int a[50001];
tr segtr[4*50001],ans;
void build(int v,int st,int end)
{
if(st==end)
{segtr[v].ls=a[st];
segtr[v].rs=a[st];
segtr[v].s=a[st];
segtr[v].ms=a[st];
}
else
{
int mid=(st+end)/2;
build(2*v,st,mid);
build(2*v+1,mid+1,end);
segtr[v].s=segtr[2*v].s+segtr[2*v+1].s;
segtr[v].ls=max(segtr[2*v].ls,(segtr[2*v].s+segtr[2*v+1].ls));
segtr[v].rs=max(segtr[2*v+1].rs,(segtr[2*v+1].s+segtr[2*v].rs));
segtr[v].ms=max(max(segtr[2*v+1].ms,(segtr[2*v].rs+segtr[2*v+1].ls)),segtr[2*v].ms);
}
}


void query(tr &ans,int v,int st,int end,int l,int r)
{
if(l==st && r==end)
{
ans=segtr[v];
return;
}
int mid=(st+end)/2;
if(r<=mid)
query(ans,2*v,st,mid,l,r);
else if(l>mid)
query(ans,2*v+1,mid+1,end,l,r);
else
{
tr left,right;
query(left,2*v,st,mid,l,mid);
query(right,2*v+1,mid+1,end,mid+1,r);
ans.s=left.s+right.s;
ans.ls=max(left.ls,(left.s+right.ls));
ans.rs=max(right.rs,(right.s+left.rs));
ans.ms=max(max(right.ms,(left.rs+right.ls)),left.ms);
}
}


int main()
{
int m,x,y,n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
scanf("%d",&m);
build(1,0,n-1);
while(m--)
{
scanf("%d%d",&x,&y);
query(ans,1,0,n-1,x-1,y-1);
printf("%d\n",ans.ms);
}
return 0;
}
