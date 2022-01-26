#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

string solution(string new_id) {
    string answer = new_id;
    
    //Stage 1. A -> a
    for(int i=0;i<answer.size();i++){
        if(answer[i]>='A'&& answer[i]<='Z'){
            answer[i]+=32;
        }
    }
    string ans="";
    //Stage 2. Erase 
    for(int i=0;i<answer.size();i++){
        if(('a'<=answer[i] && answer[i] <= 'z')||('0'<=answer[i] && answer[i]<='9')||answer[i]=='.'||answer[i]=='-'||answer[i]=='_')ans.push_back(answer[i]);
        else continue;
    }
    answer=ans;
    
    ans="";
    //Stage 3. ...... -> .
    int flag=0;
    for(int i=0;i<answer.size();i++){
        if(answer[i]=='.'&&flag==1)continue;
        if(answer[i]=='.')flag=1;
        if(answer[i]!='.'&&flag==1)flag=0;
        ans.push_back(answer[i]);
    }
    answer=ans;
   
    ans="";
    //Stage 4. .[word]. -> [word]
    for(int i=0;i<answer.size();i++){
        if(i==0&&answer[i]=='.')continue;
        if(i==answer.size()-1 && answer[i]=='.')continue;
        ans.push_back(answer[i]);
    }
    answer=ans;
    ans="";
    //Stage 5. "" -> "a"
    if(answer.size()==0)answer="a";
    //Stage 6. ~16~ -> ~15~
    if(answer.size()>15){
        for(int i=0;i<15;i++){
            if(i==14 && answer[i]=='.')continue;
            ans.push_back(answer[i]);
        }
        answer=ans;
    }
    
    ans="";
    //Stage 7. ~1,2~ -> ~3~
    int index=answer.size()-1;
    while(answer.size()<3){
        answer.push_back(answer[index]);
    }
    
    return answer;
}
