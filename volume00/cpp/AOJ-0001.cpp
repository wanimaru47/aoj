//
//  main.cpp
//  AOJ-0001
//
//  Created by Wanikawa on 2013/05/10.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//


#include <iostream>
using namespace std;

int main()
{
    int num[4],tmp;
    for (int i=0; i<10; i++)
    {
        cin >> num[3];
        for(int k=0;k<3;k++)
        {
            if (num[3] > num[k]) {
                tmp = num[k];
                num[k] = num[3];
                num[3] = tmp;
            }
        }
    }
    for (int i=0; i<3; i++) {
        cout << num[i] << endl;
    }
    return 0;
}

/*
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 int main(){
 int n;
 vector<int> high;
 
 for(int i=0 ; i<10 ; i++){
 cin >> n;
 high.push_back( n );
 }
 
 sort( high.begin() , high.end() );
 
 for(int i=9 ; i>=7 ; i--){
 cout << high.at( i ) << endl;
 }
 }
 */


