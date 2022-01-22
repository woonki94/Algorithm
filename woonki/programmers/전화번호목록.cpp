#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> umap;
    
    for(int i =0; i<phone_book.size(); i++){
        umap[phone_book[i]] = 1;
    }
    
    for(int i=0; i<phone_book.size(); i++){
        string check = "";
        for(int j=0; j<phone_book[i].size(); j++){
            check += phone_book[i][j];
        
           if(umap[check] && (check != phone_book[i])) 
             answer = false;
        
        }
    }
    
    
    
    
    
    return answer;
}
