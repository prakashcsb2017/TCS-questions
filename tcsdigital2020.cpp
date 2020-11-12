#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;
 


void func(int n) 
{ 
    int n1 = n;
    int * fac;
    int s = -1,no2s = 0,no3s = 0;
    fac = new int[100]; 
	while (n % 2 == 0) 
	{ 
        s++;
        no2s++;
        fac[s] = 2;
		n = n/2; 
	} 
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{  
		while (n % i == 0) 
		{ 
            if(i == 3)
                no3s++;
            s++;
            fac[s] = i;
			n = n/i; 
		} 
	} 
	if (n > 2){ 
        s++;
		fac[s] = n; 
    }
    /*for(int i = 0 ;i<= s;i++)
            cout<<fac[i]<<endl;*/
    int no8s = 0;
    int no9s = 0;
    int no4s = 0,no6s = 0;
    if(no2s > 1 || no3s > 1){
        no6s = min(no2s,no3s);
        no2s -= no6s;
        no3s -= no6s; 
        while(no2s > 1){
            if(no2s >= 3){
                no8s++;
                no2s -= 3;
            }
            else if(no2s >=2 ){
                no4s++;
                no2s -= 2;
            }
        }
        while(no3s > 1){
            if(no3s >= 2){
                no9s++;
                no3s -= 2;
            }
        }
    }
    int pivot ;
        for(int i = 0 ;i<=s;i++){
            if(fac[i] > 3){
                pivot = i;
                break;
            }
        }
        string nos;
        if(no2s == 1)
            nos +='2';
        if(no3s == 1)
            nos +='3';
        for(int i = 1 ;i<= no4s;i++)
            nos +='4';
        for(int i = 1 ;i<= no6s;i++)
            nos +='6';
        for(int i = 1 ;i<= no8s;i++)
            nos +='8';
        for(int i = 1 ;i<= no9s;i++)
            nos +='9';
        char a[4];
        for(int i = pivot ;i<=s;i++ ){
            itoa(fac[i],a,10);
            nos += string(a);
        }
        int ac_nos = 1;
        for(int i = 0 ;i<= nos.length();i++){
            switch(nos[i]){
                case '2':
                    ac_nos *= 2;
                    break;
                case '3':
                    ac_nos *= 3;
                    break;
                case '4':
                    ac_nos *= 4;
                    break;
                case '5':
                    ac_nos *= 5;
                    break;
                case '6':
                    ac_nos *= 6;
                    break;
                case '7':
                    ac_nos *= 7;
                    break;
                case '8':
                    ac_nos *= 8;
                    break;
                case '9':
                    ac_nos *= 9;
                    break;
                default : ;
            }
        }
        if(ac_nos == n1)
            cout<<nos;
        else
            cout<<"Not Possible";
} 

int main(){
	int n;
    cin>>n ;
	func(n); 
    return 0;
}