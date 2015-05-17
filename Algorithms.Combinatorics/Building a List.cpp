#include <iostream>
#include <sstream>
#include <algorithm>
/*
Building a List
https://www.hackerrank.com/challenges/building-a-list
*/
void compute(std::string prev, std::string curr)
{
    for(size_t i = 0;i < curr.size();i++)
	{
		std::string t = prev+curr[i];
		std::cout<<t<<"\n";
        compute(t,curr.substr(i+1));
	}
}

int main()
{
    int test_num,i,size;
    std::string curr;
    std::cin >> test_num;
    
    for(i=0;i<test_num;i++)
    {
        std::cin >> size;
        std::cin >> curr;
		std::stable_sort(curr.begin(),curr.end());
        compute("",curr);
    }
    return 0;
}