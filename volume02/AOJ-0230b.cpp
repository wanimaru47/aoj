//
//  main.cpp
//  AOJ-0230b
//
//  Created by Wanikawa on 2013/11/01.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include "iostream"
using namespace std;

int zwei(int step, int carsor, int street[2][100], int ridge, int num) {
	//two step up
	carsor += 2;
	step++;
	ridge = ridge == 1 ? 0 : 1;
    
	int s = street[ridge][carsor];
	if (carsor >= num) {
		return step;
	}else if(s == 0) {
		int i = eins(step, carsor, street, ridge, num);
		int k = zwei(step,carsor,street,ridge,num);
		if (i <= k && i != -1) {
			return i;
		}else if(k != -1) {
			return k;
		} else return i;
	}else if(s == 1) {
		int i = upstep(step,carsor,street,ridge,num);
		return i;
	}else {
		int i = downstep(step,carsor,street,ridge,num);
		return i;
	}
    
    
}

int eins(int step, int carsor, int street[2][100], int ridge, int num) {
	//one step up
	carsor++;
	step++;
	ridge = ridge == 1 ? 0 : 1;
    
	int s = street[ridge][carsor];
	if (carsor >= num) {
		return step;
	}else if(s == 0) {
		int i = eins(step,carsor,street,ridge,num);
		int k = zwei(step,carsor,street,ridge,num);
		if (i <= k && i != -1) {
			return i;
		}else if(k != -1) {
			return k;
		} else return i;
	}else if(s == 1) {
		int i = upstep(step,carsor,street,ridge,num);
		return i;
	}else {
		int i = downstep(step,carsor,street,ridge,num);
		return i;
	}
    
}

int downstep(int step, int carsor, int street[2][100], int ridge, int num) {
	//mizu step down
	while(street[ridge][carsor] == 2) {
		carsor--;
	}
	if(carsor == 0){
		return -1;
	}else {
		int i = eins(step,carsor,street,ridge,num);
		int k = zwei(step,carsor,street,ridge,num);
		if (i <= k && i != -1) {
			return i;
		}else if(k != -1) {
			return k;
		} else return i;
	}
    
}

int upstep(int step, int carsor, int street[2][100], int ridge, int num) {
	//hasigo step up
	while(street[ridge][carsor] == 1) {
		carsor++;
	}
	carsor--;
	if (carsor >= num) return step;
	else {
		int i = eins(step,carsor,street,ridge,num);
		int k = zwei(step,carsor,street,ridge,num);
		if (i <= k && i != -1) {
			return i;
		}else if(k != -1) {
			return k;
		} else return i;
	}
    
}

int main(void)
{
	int street,str[2][100],carsor;
    
	cin >> street;
	for (int i = 0; i < street; i++) {cin >> str[0][i];}
	for (int i = 0; i < street; i++) {cin >> str[1][i];}
    
	int i = str[0][0], i1=0, i2=0;
	int k = str[1][0], k1=0, K2=0;
    
	if(i == 0) {
		i1 = eins(0,0,str,0,street);
		i2 = zwei(0,0,str,0,street);
	}else if(i == 1) {
		i1 = upstep(0,0,str,0,street);
	}else {
		i1 = downstep(0,0,str,0,street);
	}
    
	if(k == 0) {
		k1 = eins(0,0,str,1,street);
		k2 = zwei(0,0,str,1,street);
	}else if(i == 1) {
		k1 = upstep(0,0,str,1,street);
	}else {
		k1 = downstep(0,0,str,1,street);
	}
	
	return 0;
}