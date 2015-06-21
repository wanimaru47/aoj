//
//  main.cpp
//  AOJ-0099
//
//  Created by Wanikawa on 2013/06/30.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int number = 0,ive,max = 0,top = 1,num;
    cin >> number >> ive;
    int men[1000001] = {0};
    int numbers = number;
    for(int i = 0; i < ive; i++){
        cin >> number >> num;
        men[number] += num;
        if(num > 0){
            if(men[number] >= max){
                if(men[number] == max){
                    if(top > number){
                        top = number;
                        max = men[number];
                    }
                }else{
                    top = number;
                    max = men[number];
                }
                cout << top << " " << max << endl;
            }else{
                cout << top << " " << max << endl;
            }
        }else{
            if(number == top){
                if(men[number] < max){
                    max = 0;
                    top = 0;
                    for(int k = numbers; k > 0; k--){
                        if(max <= men[k]){
                            top = k;
                            max = men[k];
                        }
                    }
                    cout << top << " " << max << endl;
                }
            }else{
                cout << top << " " << max << endl;
            }
        }
    }
        return 0;
}
/*
int member,event,max = 0,top,num,members;
    cin >> member >> event;
    int men[1000000] = {0};
    max = 0;
    top = 0;
    for (int i = 0; i < event; i++) {
        cin >> members >> num;
        men[members] += num;
        if (num > 0) {
            //cout << max << "??%%" << men[members] << endl;
            if (men[members] >= max) {
                if (men[members] == max) {
                    if (top < members) {
                        cout << top << " " << max << endl;
                        continue;
                    }
                }
                top = members;
                max = men[members];
            }
        }else{
            max = 0;
            top = 0;
            for (int k = member; k > 0; k--) {
                if (max <= men[k]) {
                    max = men[k];
                    top = k;
                }
            }
        }
        if (men[members] < 0) {
            men[members] = 0;
        }
        
        if (max == 0) {
            cout << "1" << " " << "0" << endl;
            continue;
        }
         
        
       
        cout << top << " " << max << endl;
        //cout << endl << "??" << men[1] << endl;
    }

*/