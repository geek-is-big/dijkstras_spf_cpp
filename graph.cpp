#include <math.h>
#include <iostream>
#include "graph.h"

Graph::Graph(unsigned int nodes)
{
    this->nodes = nodes;

    graph_data = new double *[nodes];
    for(unsigned int i = 0; i < nodes; i++) {
        graph_data[i] = new double[nodes];
        for(unsigned int j = 0; j < nodes; j++) {
            graph_data[i][j] = 0.0;
        }
    }
}

void Graph::add(unsigned int x, unsigned int y)
{
    unsigned int		sz_graph = V();

    // check argument correctness
    if( (x >= sz_graph) || (y >= sz_graph) ) {
        return;
    }
    set_edge_value(x, y, 1.0);
    set_edge_value(y, x, 1.0);
}

void Graph::delete_edge(unsigned int x, unsigned int y)
{
    unsigned int		sz_graph = V();

    // check argument correctness
    if( (x >= sz_graph) || (y >= sz_graph) ) {
        return;
    }
    set_edge_value(x, y, 0.0);
    set_edge_value(y, x, 0.0);
}

double Graph::get_edge_value(unsigned int x, unsigned int y)
{
    unsigned int		sz_graph = V();

    // check argument correctness
    if( (x >= sz_graph) || (y >= sz_graph) ) {
        return 0.0;
    }
    return this->graph_data[x][y];
}

void Graph::set_edge_value(unsigned int x, unsigned int y, double v)
{
    unsigned int		sz_graph = V();

    // check argument correctness
    if( (x >= sz_graph) || (y >= sz_graph) )
        return;
    this->graph_data[x][y] = this->graph_data[y][x] = fabs(v);
}

bool Graph::adjacent(unsigned int x, unsigned int y)
{
    unsigned int		sz_graph = V();

    // check argument correctness
    if( (x >= sz_graph) || (y >= sz_graph) )
        return false;

    // if edge exist
    if ((get_edge_value(x, y) > 0.0) ||
        (get_edge_value(y, x) > 0.0))
        return true;
    else
        return false;
}

unsigned int Graph::V()
{
    return this->nodes;
}

unsigned int Graph::E()
{
    unsigned int	sz_graph = V();
    unsigned int	edges = 0;

    // calc all edges (undirected graph)
    for(unsigned int i = 0; i < sz_graph; i++) {
        if (get_edge_value(i, i) > 0.0) {
            edges++;
        }
        for (unsigned int j = i + 1; j < sz_graph; j++) {
            if (get_edge_value(i, j) > 0.0) {
                edges++;
            }
        }
    }
    std::cout << std::endl;
    return edges;
}

void Graph::get_neighbors(unsigned int x, std::vector<unsigned int> &neighbors_to_x)
{
    unsigned int	sz_graph = V();

    // chech if graph contains node x
    if (x >= sz_graph)
        return;

    // clear vecotr if it contains elements
    if (neighbors_to_x.size() > 0) {
        neighbors_to_x.clear();
    }

    // find all neighbors to x node
    for (unsigned int i = 0; i < sz_graph; i++) {
        // same node can`t be neighbor
        if (i == x)
            continue;

        // if nodes has edge - they are neighbors
        if (adjacent(x, i)) {
            neighbors_to_x.push_back(i);
        }
    }
}
