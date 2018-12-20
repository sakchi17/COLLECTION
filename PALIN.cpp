// THE NEXT PALINDROME
// https://www.spoj.com/problems/PALIN/

#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  long long int mid,f,l,j,i,t,a[1000001];
  cin>>t;
  while(t--)
  {
      cin>>s;
      f=0;
      bool left=false;
      for(i=0;s[i]!='\0';i++)
      {
        a[i]=(int)s[i]-48;
        if(a[i]!=9)
        f=1;
      }
      l=i;
      mid=l/2;
      if(f==0)
      {
          cout<<"1";
          for(i=1;i<l;i++)
          cout<<"0";
          cout<<"1";
      }
      else
      {
      i=mid-1;
      j=(l%2)?mid+1:mid;
      while(i>=0 && a[i]==a[j])
      {
          j++;i--;
      }
      if(i<0 || a[i]<a[j])
      left=true;
      while (i >= 0) 
    { 
        a[j]=a[i]; 
        j++; 
        i--; 
    } 
    if(left==true)
    {
        int c=1;
        i=mid-1;
        if(l%2)
        {
            a[mid] += c; 
            c = a[mid] / 10; 
            a[mid] %= 10; 
            j = mid + 1; 
        }
        else
        {
            j=mid;
        }
        while (i >= 0) 
        { 
            a[i] += c; 
            c = a[i] / 10; 
            a[i] %= 10; 
            a[j++] = a[i--]; 
        } 
    }
    for(i=0;i<l;i++)
    cout<<a[i];
      }
      cout<<"\n";
      
  }
  return 0;
}
