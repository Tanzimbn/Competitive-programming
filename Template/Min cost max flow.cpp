/**
 * Description: Minimum-cost maximum flow, assumes no negative cycles. 
 	* It is possible to choose negative edge costs such that the first 
 	* run of Dijkstra is slow, but this hasn't been an issue in the past. 
 	* Edge weights $\ge 0$ for every subsequent run. To get flow through 
 	* original edges, assign ID's during \texttt{ae}.
 	* 0-indexed node
 * Time: Ignoring first run of Dijkstra, $O(FM\log M)$ 
 * Source: 
 * https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/graphs%20(12)/Flows%20(12.3)/MCMF.h
 */

struct MCMF { 
	using F = ll; using C = ll; // flow type, cost type
	struct Edge { int to; F flo, cap; C cost; };
	int N; vector<C> p, dist; vector<int> pre; vector<Edge> eds; vector<vector<int> > adj;
	void init(int _N) { N = _N;
		p.resize(N), dist.resize(N), pre.resize(N), adj.resize(N); }
	void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
		adj[u].PB(eds.size()); eds.PB({v,0,cap,cost}); 
		adj[v].PB(eds.size()); eds.PB({u,0,0,-cost});
	} // use asserts, don't try smth dumb
	bool path(int s, int t) { // find lowest cost path to send flow through
		const C inf = numeric_limits<C>::max(); for(int i = 0; i < N; i++) dist[i] = inf;
		using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
		todo.push({dist[s] = 0,s}); 
		while (todo.size()) { // Dijkstra
			T x = todo.top(); todo.pop(); if (x.fi > dist[x.se]) continue;
			for(auto &e : adj[x.se]) { const Edge& E = eds[e]; // all weights should be non-negative
				if (E.flo < E.cap && dist[E.to] > x.fi + E.cost + p[x.se] - p[E.to])
					pre[E.to] = e, dist[E.to] = x.fi + E.cost + p[x.se] - p[E.to], todo.push({dist[E.to],E.to});
			}
		} // if costs are doubles, add some EPS so you 
		// don't traverse ~0-weight cycle repeatedly
		return dist[t] != inf; // return flow
	}
	pair<F,C> calc(int s, int t, ll k = numeric_limits<F>::max()) { assert(s != t);
		for(int i = 0; i < N; i++) 
			for(int e = 0; e < eds.size(); e++) { 
				const Edge& E = eds[e]; // Bellman-Ford
				if (E.cap) p[E.to] = min(p[E.to],p[eds[e^1].to]+E.cost); 
			}
		F totFlow = 0; C totCost = 0;
		while (path(s,t)) { // p -> potentials for Dijkstra
			for(int i = 0; i < N; i++) p[i] += dist[i]; // don't matter for unreachable nodes
			F df = k;
			for (int x = t; x != s; x = eds[pre[x]^1].to) {
				const Edge& E = eds[pre[x]]; df = min(df,E.cap-E.flo); }
			totFlow += df; totCost += (p[t]-p[s])*df;
			for (int x = t; x != s; x = eds[pre[x]^1].to)
				eds[pre[x]].flo += df, eds[pre[x]^1].flo -= df;
			if(k != numeric_limits<F>::max()) { // check if it is MCF or MCMF
				k -= df;
				if(k <= 0) break;	
			}
		} // get max flow you can send along path
		return {totFlow,totCost};
	}
};
