#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    vector<char> belong(graph.size(), 2);
    queue<int> Q;
    for (int i = 0; i != graph.size(); ++i)
    {
        if (belong[i] != 2)
            continue;
        Q.push(i);
        belong[i] = 0;
        while(!Q.empty())
        {
            int j = Q.front();
            Q.pop();
            for (int k = 0; k != graph[j].size();k++)
            {
                int v = graph[j][k];
                if(belong[j] == belong[v])
                    return false;
                if(belong[v] == 2)
                {
                    belong[v] = 1^belong[j];
                    Q.push(v);
                }
            }
        }
    }
    return true;
}


int main()
{
    vector<vector<int>> graph{{1, 2, 3}, {0, 1}, {0, 1, 3}, {0, 2}};
    cout << isBipartite(graph) << endl;
}