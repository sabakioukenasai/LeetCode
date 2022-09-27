#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int FindParent(int n, int v, const vector<vector<int> >& edges){
        vector<bool> visited(n, 0);
        int i, parent = v;
        for (i = 0; i != edges.size(); i++)
        {
            if (edges[i][0] == v && visited[edges[i][1]] == 0){
                if (parent == v)
                    parent = edges[i][1];
                else
                    return -1;
            }
            if (edges[i][1] == v && visited[edges[i][0]] == 0){
                if (parent == v)
                    parent = edges[i][0];
                else
                    return -1;
            }
        }
        return parent;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        vector<int> answer, degrees(n, 0);
        vector<bool> visited(n, 0);
        if (n == 1){
            answer.push_back(0);
            return answer;
        }
        for (int i = 0; i != edges.size(); i++){
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        for (int i = 0; i != n; i++)
            if (degrees[i] == 1){
                answer.push_back(i);
                visited[i] = 1;
            }
        do {
            n -= answer.size();
            int parent;
            for (int i = 0; i != answer.size(); i++){
                parent = FindParent(n, answer[i], edges);
                answer[i] = parent;
            }
            sort(answer.begin(), answer.end());
            answer.erase(unique(answer.begin(), answer.end()), answer.end());
            if (answer[0] == -1)
                answer.erase(answer.begin(), ++answer.begin());
            for (int i = 0; i != answer.size(); i++)
                visited[answer[i]] = 1;
        }while(n > 2);

        return answer;
    }
};