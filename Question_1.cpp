#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int t,n,sum,r,c;
   cin >>t;
   for(int m=1;m<=t;m++)
   {
       sum=0;
        cin >>n;
        int a[n][n];
        set <int> s;
        r=0,c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >>a[i][j];
                s.insert(a[i][j]);
                if(i==j)
                {
                    sum = sum + a[i][j];
                }
            }
            if(s.size()<n)r++;
            s.clear();
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                s.insert(a[i][j]);
            }
            if(s.size()<n)c++;
            s.clear();
        }
       cout<<"Case #"<<m<<": "<<sum<<" "<<r<<" "<<c<<endl;
   }
}
