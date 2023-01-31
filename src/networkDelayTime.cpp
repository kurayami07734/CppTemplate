#include <vector>
#include <queue>
#pragma once

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> edges(n);
        vector<bool> visit(n, false);
        priority_queue<pair<int, int>,
         vector<pair<int, int>>,
          greater<pair<int, int>>> pq;
        int t = 0;
        for(auto triple : times) {
            int u = triple[0], v = triple[1], w = triple[2];
            edges[u].push_back({v, w});
        }
        pq.push({0, k});
        while(!pq.empty()) {
            auto [curTime, cur] = pq.top();
            pq.pop();
            if(visit[cur]) continue;
            t = curTime;
            visit[cur] = true;
            for(auto [neig, neigTime] : edges[cur]) {
                if (!visit[neig]) {
                    pq.push({neigTime + curTime, cur});
                }
            }
        }
        for(auto v : visit) {
            if(!v) return -1;
        }
        return t;
    }