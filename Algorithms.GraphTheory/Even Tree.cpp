#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
/*
https://www.hackerrank.com/challenges/even-tree

Assume node 1 is root.
$tree: i+1 's parent node is tree[i-1]
$count: node i+1 's child nodes count including self

	  1
 2    3   6
7 5   4   8 
         9 10

$tree:  0  1 1 3 2 1 2 6 8 8 
$count: 10 3 2 1 1 4 1 3 1 1 
*/
int main()
{   
	//std::ifstream cin("input.txt");
    int V,E,i,x,y,root;
    cin >> V >> E;
    
    std::vector<int> tree(V,0);
    std::vector<int> count(V,1);

    for(i=0;i<E;i++)
    {
        cin >> x >> y;

        tree[x-1] = y;
        count[y-1] += count[x-1];
       
        root = tree[y-1];
        
        while(root != 0)
        {
            count[root-1] += count[x-1];
            root = tree[root-1];
        }
    }

    root = -1;
    for(i=0;i<V;i++)
        if((count[i] & 1) ==0)
            root++;  
    printf("%d\n",root);

	//cin.close();
    return 0;
}
