#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        int count = 0;
        vector<int>Indegree(numCourses, 0);
        queue<int> S;
        for (int i = 0; i < prerequisites.size(); ++i)
            ++Indegree[prerequisites[i][1]];
        for (int i = 0; i < Indegree.size(); ++i)
            if (Indegree[i] == 0)
                S.push(i);
        while(!S.empty())
        {
            int j = S.front();
            S.pop();
            count++;
            for (int i = 0; i< prerequisites.size(); ++i)
                if (prerequisites[i][0] == j) {
                    int k = prerequisites[i][1];
                    if (--Indegree[k] == 0)
                        S.push(k);
                }
        }
        if (count < numCourses) return false;
        else return true;
    }
