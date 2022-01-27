#include <string>
#include <vector>
#include<stdio.h>
#include<unordered_map>
#include<map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
 /*   vector<string> no_wan;
    
    for(int i=0; i<completion.size();i++){
        for(int j=0; j<participant.size();j++){
            if(participant[j]==completion[i]){
                participant[j] ="!";
                completion[i] = "?";
            }
        }
    }
    
    for(int i=0; i<participant.size();i++){
        if(participant[i]!="!"){
            answer = participant[i];
            break;
        }
    }
    */
    unordered_map<string, int> map;
  
    
    
    for(int i=0; i<participant.size(); i++){
        map[participant[i]]++;
    }
    for(int i=0; i<completion.size();i++){
        map[completion[i]]--;
    }
    
    for (pair<string, int> i : map) {
		if(i.second == 1) answer = i.first;
	}
    
    /*
    
    map<string, int> map;
    
    map["a"]=1;
    map["b"]=1;
    map["a"]=2;
    
    printf("%d", map.find("a")->second);
    
    */
    
    
    return answer;
}
