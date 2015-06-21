//
//  main.cpp
//  AOJ-0258
//
//  Created by Wanikawa on 2013/08/29.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    
    
    while (1) {
        int num;
        cin >> num;
        
        
        if (num == 0) break;
        
        double vegetable[101] = {0};
        
        
        for (int i = 1; i <= num+1; i++) {
            cin >> vegetable[i];
            //cout << "i=" << i << ",vegetable=" << vegetable[i] << endl;
        }
        
        //int tmp[101] = {0};
        //int tmp1,tmp2,tmp3;
        int ans = 0;
        double kiso;
        
        if (((vegetable[3] - vegetable[1])/2+vegetable[1]) == vegetable[2]) {
            kiso = (vegetable[3] - vegetable[1])/2;
            //cout << "kiso" << kiso <<  endl;
            for (int i = 1; i < num+1 ; i++) {
                //cout << vegetable[i] + kiso << "<<" << vegetable[i+1] << endl;
                if ((vegetable[i]+kiso) != vegetable[i+1]) {
                    ans = vegetable[i+1];
                    
                    if (i+1 == 4) {
                        double tmpp = ((vegetable[4] - vegetable[1])/2+vegetable[1]);
                        kiso = (vegetable[4] - vegetable[1])/2;
                        if (tmpp == vegetable[3]) {
                            //cout << "test" << endl;
                            ans = vegetable[2];
                            for (int k = 3; k < num+1; k++) {
                                tmpp += kiso;
                                //cout << "test" << tmpp << "ans" << ans << "vegetable" << vegetable[i+1] << endl;
                                if (tmpp != vegetable[k+1]) {
                                    ans = vegetable[k+1];
                                }
                            }
                        }
                    }
                    //cout << "kiso" << kiso <<  endl;
                    break;
                }
            }
        }else {
            if (((vegetable[4] - vegetable[2])/2+vegetable[2]) == vegetable[3]) {
                ans = vegetable[1];
            }else {
                if (((vegetable[4] - vegetable[1])/2+vegetable[1]) == vegetable[2]) {
                    ans = vegetable[3];
                }else {
                    ans = vegetable[2];
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}

