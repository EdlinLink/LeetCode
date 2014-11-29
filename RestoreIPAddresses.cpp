/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Restore IP Addresses 
    Source:     https://oj.leetcode.com/problems/restore-ip-addresses/

    Given a string containing only digits, restore it by returning all possible valid IP address combinations.

    For example:
    Given "25525511135",

    return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

    Solution:   i, j, k, l is the end position of the num which exclude.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        int n = s.size();
        if(s.size()>12) return result;

        for(int i=1; i<=3 && i<n; i++){
            if(invalid(s, 0, i))    continue;

            for(int j=i+1; j<=i+3 && j<n; j++){
                if(invalid(s, i, j))    continue;

                for(int k=j+1; k<=j+3 && k<n; k++){
                    if(invalid(s, j, k))    continue;
                    
                    if(!invalid(s, k, n))
                        push(s, i, j, k);
                }
            }
        }

        return result;
    }

    bool invalid(const string &s, int a, int b){
        int num = 0;
        for(int i=a; i<b; i++){
            num *= 10;
            num += (s[i]-'0');
        }

        if(num==0 && b-a>1)
            return true;
        if(num!=0 && s[a]=='0')
            return true;
        return !(0<=num && num<=255);
    }

    void push(string s, int a, int b, int c){
       s.insert(c, "."); 
       s.insert(b, "."); 
       s.insert(a, "."); 
       result.push_back(s);
    }
    
};

int main(){
    Solution s;
    s.restoreIpAddresses("0000");
    return 0;
}
