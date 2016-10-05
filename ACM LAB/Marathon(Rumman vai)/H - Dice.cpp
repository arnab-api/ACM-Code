#include<bits/stdc++.h>
using namespace std;

int main()
{
    int even,odd,n,a;
    string name1,name2,pref;
    while(cin>>name1>>name2>>pref){
        if(name1=="#" && name2=="#" && pref=="#") break;
        even = 0;
        odd = 0;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&a);
            if(a&1) odd++;
            else even++;
        }
        if(pref=="even") swap(even,odd);
        cout<<name1<<" "<<even<<" "<<name2<<" "<<odd<<endl;
    }
    return 0;
}
