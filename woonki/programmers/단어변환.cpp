#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;

struct Word{
    string word;
    int count;
};

bool word(string a, string b){
    int cnt = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]) cnt ++;
    }
    
    if(cnt == 1 ) return true;
    else return false;
}


int solution(string begin, string target, vector<string> words) {
    int flag =0;
    int answer = 0;
    for(int i=0; i<words.size(); i++){    
        if(target == words[i]) flag = 1;
    }
    if(flag == 0) return 0;
    
    
    vector<int> check(words.size(), 0);
    queue<Word> q;
    
    q.push({begin,1});
    
    while(!q.empty()){
        Word tmp = q.front();
        if(tmp.word == target) break;
        q.pop();
        
        int cnt = tmp.count;
        answer = cnt;
        
        
        for(int i = 0; i<words.size(); i++){
            if(word(tmp.word, words[i]) && check[i] == 0) {
                q.push({words[i],cnt+1});
                check[i] = 1;
            }
        }
    }
    
    
    return answer;
}
