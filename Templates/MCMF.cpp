template <class Flow = ll, class Cost = ll> 
struct MCMF {
    
    struct Edge {
        int u, v;
        Flow cap, flow;
        Cost cost;
    };
    
    vector<Edge> edges;
    vector<vector<int> > adjlist;
    vector<int> p;
    vector<Cost> dist;
    vector<Flow> pushed;
    
    MCMF(int N) {
        adjlist.resize(N);
        p.resize(N);
        dist.resize(N);
        pushed.resize(N);
    }
    
    void AddEdge(int u, int v, Flow cap, Cost cost) {
        Edge f = { u, v, cap, 0, cost }, b = { v, u, 0, 0, -cost };
        adjlist[u].push_back((int) edges.size()); edges.push_back(f);
        adjlist[v].push_back((int) edges.size()); edges.push_back(b);
    }
    
    bool Dijkstra(int s, int t) {
        fill(p.begin(), p.end(), -1);
        fill(dist.begin(), dist.end(), INF); 
        dist[s] = 0;
        pushed[s] = INF;
        priority_queue<pair<Cost, int> > q; q.push(make_pair(0, s));
        while (!q.empty()) {
            pair<Cost, int> front = q.top(); q.pop();
            Cost d = -front.first; int u = front.second;
            if (d > dist[u]) continue;
            for (int i = 0; i < (int) adjlist[u].size(); i++) {
                int id = adjlist[u][i], to = edges[id].v;
                Cost cost = edges[id].cost;
                if (dist[u] + cost < dist[to] && edges[id].flow < edges[id].cap) {
                    dist[to] = dist[u] + cost;
                    p[to] = id;
                    pushed[to] = min(pushed[u], edges[id].cap - edges[id].flow);
                    q.push(make_pair(-dist[to], to));
                }
            }
        }
        if (p[t] == -1) return false;
        for (int k = p[t]; k != -1; k = p[edges[k].u]) {
            edges[k].flow += pushed[t];
            edges[k^1].flow -= pushed[t];
        }
        return true;
    }
    
    pair<Flow, Cost> Get(int s, int t) {
        for (int i = 0; i < (int) edges.size(); i++)
            edges[i].flow = 0;
        int totalFlow = 0; int totalCost = 0;
        while (Dijkstra(s, t)) {
            totalFlow += pushed[t];
            totalCost += dist[t] * pushed[t];
        }
        return make_pair(totalFlow, totalCost);
    }
};