#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//제곱근이 있으면 홀수
bool count_divisor(int n){
    if(n == 1) return false;
    
    for(int i = 1; i<= n/2 ;i++){
        if(i*i == n) return false;
    }
    
    return true;
    
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i<=right; i++){
        if(count_divisor(i))
            answer+= i;
        else answer -= i;
    }
    
    return answer;
}
