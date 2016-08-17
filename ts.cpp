// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
#include <vector>
#include <iterator>
using namespace std;

vector<vector<int>> g;

stack<int> sorted;

vector<bool> visited(6,false);

void dfs(int now)
{
    visited[now] = true;
    vector<int>::iterator it;
    
        for(it=g[now].begin();it!=g[now].end();it++)
        {
            if(!visited[*it])
            {
                dfs(*it);
            }
        }
        
    sorted.push(now);   
    
}

void tp()
{
    int i,j,k; int now = 0;
    
    for(i=0;i<6;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    g.resize(6);
    
    g[0].push_back(1);
    g[0].push_back(2);
	g[1].push_back(4);
	g[2].push_back(4);
	g[3].push_back(5);
	g[3].push_back(2);

	cout << "Following is a Topological Sort of the given graph \n";
	
	tp();
	
	cout<<"gay\n";
	
	while(!sorted.empty())
    {
        cout<<sorted.top()<<endl;    
        sorted.pop();
    }
    
	return 0;
}
