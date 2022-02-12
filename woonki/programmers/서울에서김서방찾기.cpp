#include <string>
#include <vector>
#include<iostream>
#include<sstream>

using namespace std;

string solution(vector<string> seoul) {
    string answer="김서방은 ";
    ostringstream o;
    
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i] == "Kim"){
            o<<i;
            answer+= o.str();
            break;
        }
    }  
    
   return answer+"에 있다";
}
