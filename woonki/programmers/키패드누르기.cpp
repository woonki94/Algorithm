#include <string>
#include <vector>
#include<stdio.h>
#include<iostream>
using namespace std;


typedef struct{
    int x;
    int y;
}matrix;

matrix L,R;

string solution(vector<int> numbers, string hand) {
    
    int num=0;
    string answer="";
    
    L.x = 0;
    L.y = 3;
    R.x = 2;
    R.y = 3;
 
    for(int i=0; i<numbers.size(); i++){
        num = numbers[i];
        
        // 1,4,7일때    
        if(num % 3 == 1){
            answer += 'L';
            L.x = 0;
            switch(num){
                case 1: L.y = 0; break;
                case 4: L.y = 1; break;
                case 7: L.y = 2; break;
                //default: printf("error!!"); break;
            }
        }
        else if(num % 3 == 0 && num!=0){
            answer += 'R';
            R.x = 2;
            switch(num){
                case 3: R.y = 0; break;
                case 6: R.y =1; break;
                case 9: R.y =2; break;
                //default: printf("error!!"); break;
            }
        }
        else{
           matrix mid;
            mid.x = 1;
            switch(num){
                case 2: mid.y = 0; break;
                case 5: mid.y= 1; break;
                case 8: mid.y = 2; break;
                case 0: mid.y =3; break;
            }
            int l_d = abs(mid.x - L.x) + abs(mid.y - L.y);
            int r_d = abs(mid.x - R.x) + abs(mid.y - R.y);
            
            if(l_d<r_d){
                answer+='L';
                L.x = mid.x;
                L.y = mid.y;
            }
            else if(l_d>r_d){
                answer+='R';
                R.x = mid.x;
                R.y = mid.y;
            }
            else{
                if(hand =="right") {
                    answer+= 'R';
                    R.x = mid.x;
                    R.y = mid.y;
                }
                else{
                    answer+= 'L';
                    L.x = mid.x;
                    L.y = mid.y;
                }
        }
    }
    }
    return answer;
}
