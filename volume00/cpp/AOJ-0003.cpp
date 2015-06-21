//
//  main.cpp
//  AOJ-0003
//
//  Created by Wanikawa on 2013/05/10.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num, a, b, c;
    cin >> num;
    for (int i=0; i<num; i++) {
        vector<int> high;
        cin >> a >> b >> c;
        high.push_back(a);
        high.push_back(b);
        high.push_back(c);
        sort( high.begin() , high.end() );
        high.at(2) *= high.at(2);
        high.at(1) *= high.at(1);
        high.at(0) *= high.at(0);
        printf("%d%d%d\n",high.at(2),high.at(1),high.at(0));
        if((high.at(2)) == ((high.at(0)) + (high.at(1))))
        {
            cout << "YES" << endl;
        }
        else cout << "NO"<< endl;
    }
    return 0;
}

/*
 #include <iostream>
 using namespace std;
 
 bool check(int a, int b , int c){
 return ( a*a == ( b*b + c*c ) )? true : false ;
 }
 
 int main(){
 int n, a, b, c;
 
 cin >> n;
 for(int i=0 ; i<n ; i++){
 cin >> a >> b >> c;
 if( check(a,b,c) || check(b,c,a) || check(c,a,b) ){
 cout << "YES" << endl;
 }else{
 cout << "NO" << endl;
 }
 }
 }
 */
