//
//  main.cpp
//  AOJ-0226
//
//  Created by Wanikawa on 2013/10/26.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    
    int ans,sccs,hit=0,brow=0;
    int success[4] = {0},answer[4] = {0};
    
    while (1) {
        cin >> sccs >> ans;
        if (ans == 0 && sccs == 0) break;
        hit = 0;
        brow = 0;
        
        for (int i = 3; i >= 0; i--) {
            answer[i] = ans % 10;
            ans = ans / 10;
            success[i] = sccs % 10;
            sccs = sccs / 10;
        }
        
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < 4; k++) {
                if (answer[i] == success[k]) {
                    if (i == k) {
                        hit++;
                        break;
                    }else {
                        brow++;
                        break;
                    }
                }
            }
        }
        
        cout << hit << " " <<  brow << endl;
    }
    return 0;
}

