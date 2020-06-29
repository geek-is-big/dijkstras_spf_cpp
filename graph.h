#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

// Graph class
class Graph
{
public:
    // Graph (nodes): creates a graph with determinate number of nodes
    Graph(unsigned int nodes);

    // V (Graph): returns the number of vertices in the graph
    unsigned int V();

    // E (Graph): returns the number of edges in the graph
    unsigned int E();

    // adjacent (Graph, x, y): tests whether there is an edge from node x to node y.
    bool adjacent(unsigned int x, unsigned int y);

    // get_neighbors (Graph, x): lists all nodes y such that there is an edge from x to y.
    void get_neighbors(unsigned int x, std::vector<unsigned int> &neighbors_to_x);

    // add (Graph, x, y): adds to Graph the edge from x to y, if it is not there.
    void add(unsigned int x, unsigned int y);

    // delete_edge (Graph, x, y): removes the edge from x to y, if it is there.
    void delete_edge(unsigned int x, unsigned int y);

    // get_edge_value( Graph, x, y): returns the value associated to the edge (x,y).
    double get_edge_value(unsigned int x, unsigned int y);

    // set_edge_value (Graph, x, y, v): sets the value associated to the edge (x,y) to v.
    void set_edge_value(unsigned int x, unsigned int y, double v);

private:
    double				**graph_data;
    unsigned int		nodes;

};

#endif
