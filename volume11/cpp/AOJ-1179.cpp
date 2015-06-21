//
//  main.cpp
//  JOI-1179
//
//  Created by Wanikawa on 2013/05/13.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int y,m,d,num,k,kk;
    cin >> num;
    for (int i=0; i<num; i++) {
        int days,days_y=0,days_m=0,days_d=0;
        cin >> y >> m >> d;
        k = y;
        kk = m;
        while(y<999)
        {
            if(y%3 == 0)
            {
                days_y += 200;
            }else{
                days_y += 195;
            }
            y++;
        }
        if(k % 3 == 0) {
            days_d += (21 - d);
            kk++;
            for (int i =kk; i<11; i++) {
                days_d += 20;
            }
        }else{
            days_d += 5;
            if (kk%2==0) {
                days_d += (20-d);
            }else{
                days_d += (21-d);
            }
            kk++;
            while(kk < 11)
            {
                if (kk%2 == 0) {
                    days_m +=19;
                    
                }else{
                    days_m +=20;
                }
                kk++;
            }
        }
        days = days_y + days_m + days_d;
        cout << days << endl;
    }
}

