//
//  main.cpp
//  AOJ-1172
//
//  Created by Wanikawa on 2013/05/29.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//


#include <iostream>
using namespace std;

int main()
{
    int num,prmnum[21786],k=0,ans1,ans2;
    num = 3;
    prmnum[0] = 2;
    while (num < 246912) {
        for (int i = 0; i <= k; i++) {
            if (num % prmnum[i] == 0) {
                break;
            }
            if (k == i) {
                k++;
                prmnum[k] = num;
            }
        }
        num += 2;
    }
    //cout << k << endl;
    while (cin >> num) {
        if (num == 0) break;
        for (int i = 0; i < k; i++) {
            if (num < prmnum[i]) {
                ans1 = i;
                //cout << ans1 << prmnum[i] << "|";
                break;
            }
        }
        for (int i = k; i >= 0; i--) {
            if (num*2 >= prmnum[i]) {
                ans2 = i;
                //cout << ans2 << "|";
                break;
            }
        }
        ans1 = ans2 - ans1 + 1;
        cout << ans1 << endl;
    }
    return 0;
}

/*
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <climits>
 #include <cmath>
 #include <ctime>
 #include <cassert>
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <iomanip>
 #include <complex>
 #include <string>
 #include <vector>
 #include <list>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <set>
 #include <map>
 #include <bitset>
 #include <iterator>
 #include <functional>
 #include <utility>
 #include <algorithm>
 #include <numeric>
 #include <typeinfo>
 
 using namespace std;
 
 #define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
 #define repi(i,a,b) for(int i=int(a);i<int(b);i++)
 #define rep(i,n) repi(i,0,n)
 #define iter(c) __typeof((c).begin())
 #define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
 #define allof(c) (c).begin(),(c).end()
 #define mp make_pair
 
 typedef unsigned int uint;
 typedef long long ll;
 typedef unsigned long long ull;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef vector<double> vd;
 typedef vector<vd> vvd;
 typedef vector<string> vs;
 typedef pair<int,int> pii;
 
 int main()
 {
 vi ps;
 {
 vi isp(300000,1);
 isp[0]=isp[1]=0;
 rep(i,isp.size()) if(isp[i]) for(int j=i+i;j<isp.size();j+=i)
 isp[j]=0;
 rep(i,isp.size()) if(isp[i])
 ps.push_back(i);
 }
 
 for(int n;cin>>n,n;){
 iter(ps) it1=upper_bound(allof(ps),n);
 iter(ps) it2=upper_bound(allof(ps),2*n);
 cout<<it2-it1<<endl;
 }
 
 return 0;
 }
 */