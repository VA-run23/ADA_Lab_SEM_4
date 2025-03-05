//TIME COMPLEXITY: O(N+E) where N is the number of nodes and E is the number of edges.

//Limitations at last
//If you can get the topological sort of a graph , then it is a cyclic graph
//Topological sort is only possible in a DAG(Directed Acyclic Graph)
//Topological sort is a linear ordering of vertices such that for every directed edge u->v, vertex u comes before v in the ordering

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;//n: Number of nodes, m : number of edges 
    cin>>n>>m;
    int cnt = 0;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);//initialising indegree of each node to zero
    for(int i =0; i< m; i++){
        int u, v;
        cin>>u>>v;
        //u-->v
        adj[u].push_back(v);//since adj is a vector of vector, it holds the list of elements(v) connected to node(u)
        //adj[u].push_back(v); indicates that there is a directed edge from node u to node v. This means u is the starting point and v is the endpoint of the edge, representing a connection where u leads to v.
        //When you push v into the adjacency list of u, you are effectively saying that there is a path from u to v.
        indeg[v]++;//
    }
    queue<int> pq;
    for(int i = 0; i< n; i++){//Pushing the nodes with indegree 0 into the queue
        if(indeg[i] == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;//what is the use of counting here?
        //
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        //x --> v;//here x is same as u
        for(auto i : adj[x]) { // adj[x] represents a vector (list) containing the nodes that are adjacent to the node x.
                        // These are the nodes that x points to in a directed graph.
                        // The loop iterates through each of these adjacent nodes (children of x), represented as i.
            indeg[i]--;        // If any node other than the leaf nodes has a child node, subtract 1 from its in-degree.
                        // This checks if the child can now become a leaf node (i.e., its in-degree becomes 0).
            if(indeg[i] == 0)  // If the in-degree of the child node becomes 0, it means it is ready to be processed,
                        // as it is no longer dependent on any other node.
            pq.push(i);    // Push this newly independent node (now a leaf node) into the priority queue for further processing.
        }

    }
    return 0;
}
// //Input
// 4 3//Number of nodes and edges
// 0 1 
// 1 2 
// 2 3

// Representation of the above graph
//           0 
//         /
//        1
//       /
//     2
//    /
//   3

// //Output
// 0 1 2 3 



////////Next input
// Representation of the above graph
// 3 3///Number of nodes and edges
// 0 1 
// 1 2 
// 2 0

//           0 
//         /  |
//        1   |
//       /    |
//     2______|

////Output
//(EMPTY)//Because the graph is cyclic.



//////Limitations
// //input
// 9 9
// 7 8
// 8 3 
// 3 5

// // representation
//       7 
//        \
//         8
//          \
//           3
//            \
//             5


// //Output
// 0 1 2 4 6 7 8 3 5 

//Reason    
//Nodes 0, 1, 2, 4, and 6 are isolated and not connected in this specific input, so they don't appear in this visual representation


//NOTE THIS
// is this input correct: 
// 4 3 //4 nodes and 3 edges
// 7 8
// 8 3 
// 3 5
// No, the input is not correct. The first value, 4, indicates that there are 4 nodes, but the edges provided (7 8, 8 3, 3 5) involve nodes numbered 7 and above. This conflicts with the number of nodes specified.

// Correct Input Structure:
// The number of nodes (n) should be greater than or equal to the highest numbered node in your edge list.

// The edges should involve nodes within the specified range of n.

// Corrected Example:
// If you want to include nodes 7, 8, 3, and 5, the number of nodes (n) should be at least 9 to accommodate the highest node number, 8:

// 9 3
// 7 8
// 8 3
// 3 5