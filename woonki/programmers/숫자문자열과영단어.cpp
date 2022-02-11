#include<vector>
#include<string>


using namespace std;



vector<string> numbers = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int solution(string s) {
    string answer = "";
    string temp = ""; // 앞 두 글자만 확인
    
    for(int i = 0; i < s.length(); i++) {
        if (s[i] >= 48 and s[i] <= 57) { // 숫자인 경우
            answer += s[i];
        }
        else { // 영문인 경우
            temp = s.substr(i, 2);

            for(int j = 0; j < numbers.size(); j++) {
                string cur = numbers[j].substr(0, 2);

                if ( cur == temp) {
                    answer += to_string(j);
                    i += numbers[j].length() - 1;
                    break;
                }
            }
        }
    }
    return stoi(answer);
}
