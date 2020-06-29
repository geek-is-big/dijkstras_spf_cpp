#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <list>
#include <vector>

#include "graph.h"

struct path_set{
    double          path_value;
    unsigned int    node;
};

class ShortestPath
{
public:
    ShortestPath(){}

    // path_size(u, w): return the path cost associated with the shortest path or -1 if path not exist
    double path_size(Graph &graph, unsigned int src, unsigned int dst);

    // return least path for node from set
    double get_least_path(std::vector<path_set> &set, unsigned int &node, unsigned int &num);

    // add elements pair node-path to set
    void add_to_set(std::vector<path_set> &set, unsigned int &node, double &path);

    // return path for first node "node" from set
    double get_from_set(std::vector<path_set> &set, const unsigned int &node);

    // set new value for path_value in set for the the first node "node" in set
    void set_new_path(std::vector<path_set> &set, const unsigned int &node, const double &path);

    // delete elements pair node-path from set by node value
    void delete_from_set(std::vector<path_set> &set, const unsigned int &num);
};

#endif
