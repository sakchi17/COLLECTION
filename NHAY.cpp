
//NHAY - A Needle in the Haystack
//https://www.spoj.com/problems/NHAY/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string pat,s;
void need(ll len)
{
ll i,j,ln;
vector <int> kmp(len);
kmp[0]=0;
for(i=1;i<len;i++)
{
j=kmp[i-1];
while(j>0 && pat[i]!=pat[j])
{j=kmp[j-1];}
if(pat[i]==pat[j])
j++;
kmp[i]=j;
}

ln=s.size();
j=0;
for(i=0;i<ln;i++)
{
while(j>0 && s[i]!=pat[j])
j=kmp[j-1];
if(s[i]==pat[j])
j++;
if(j==len)
{
cout<<i-len+1<<"\n";
j=kmp[j-1];
}
}
}


int main()
{
ll len;
while(cin>>len)
{
getline(cin, pat);
getline(cin, pat);
getline(cin, s);
need(len);
cout<<"\n";
}
return 0;
}
