#include <iostream>
#include <string>
using namespace std;
/*
https://www.hackerrank.com/challenges/anagram
*/
#define NUM 26

int abs(int x){
    return x <0 ? -x : x;
}

int anagram(std::string& x, std::string& y){    
    int xr[NUM] = {0};
    int yr[NUM] = {0};
    
    for(auto i = x.begin();i!=x.end();i++)
        xr[*i - 'a']++;
    for(auto i = y.begin();i!=y.end();i++)
        yr[*i - 'a']++;  
    
    int diff = 0;
    for(int i = 0;i<NUM;i++)
        diff += abs(xr[i] - yr[i]);
        
    return diff >> 1;
}

int main(){
    int case_num,i,size;
    std::string s;
    
    cin >> case_num;
    
    for(i = 0;i<case_num;i++){
        cin >> s;
        size = (int)s.size();
        if((size & 1) == 0){
            size >>= 1;
            std::string x = s.substr(0,size);
            std::string y = s.substr(size);
            printf("%d\n",anagram(x,y));
        }
        else
            printf("-1\n");
    }
    return 0;
}
