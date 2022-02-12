using namespace std;


long long solution(int price, int money, int count)
{
    long long answer=0;
    
    for(int i=1; i<=count; i++){
        answer += price * i;
    }
    
    if(answer > money) answer -= money;
    else answer = 0L;
    
    
    return answer;
}
