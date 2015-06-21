//
//  main.cpp
//  pck2013
//
//  Created by Wanikawa on 2013/09/14.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /*
     hitogagominoyouda
     */
    while (1) {
        int num,feeld = 0;
        int play[10] = {0};
        string crad;
        
        cin >> num;
        if (num == 0) break;
        cin >> crad;
        //cout << crad;
        
        int pt = 0;
        while (pt < 100) {
            for (int i = 0; i < num; i++) {
                if (pt > 100) break;
                if (crad[pt] == 'M') {
                    play[i]++;
                }
                if (crad[pt] == 'S') {
                    feeld++;
                    feeld += play[i];
                    play[i] = 0;
                }
                if (crad[pt] == 'L') {
                    play[i] = play[i] + feeld + 1;
                    feeld = 0;
                }
                pt++;
            }
        }
        
        vector<int> p;
        for (int i = 0; i < num; i++) {
            p.push_back(play[i]);
        }
        sort(p.begin(), p.end());
        
        for (int i = 0; i < num; i++) {
            cout << p[i] << " ";
        }
        cout << feeld << endl;
    }
    
    return 0;
}

