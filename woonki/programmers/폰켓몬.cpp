#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    set<int> s;
    for(int i=0; i<n; i++){
        int k = nums[i];
        s.insert(k);
    }
    
    if(s.size() <=n/2 ) answer = s.size();
    else answer= n/2;
    
    return answer;
}
