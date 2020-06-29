#include <ostream>
#include <vector>
#include "shortest_path.h"

using namespace std;

double ShortestPath::path_size(Graph &graph, unsigned int src, unsigned int dst)
{
    unsigned int size_graph = graph.V();

    if ((src >= size_graph) || (dst >= size_graph)) {
        return -1;
    }

    // create two sets and vector for neighbors
    std::vector<path_set> closed_set;
    vector<path_set> open_set;
    vector<unsigned int>neighbors;

    double          distance = 0.0;
    size_t          num_of_neighbors;
    double          path_to_neighbor, old_path;
    unsigned int    way_src = src;
    unsigned int    delete_num, next_node;

    while (1) {
        add_to_set(closed_set, way_src, distance);

        // check if all nodes in closed set - path find
        if (closed_set.size() >= size_graph) {
            return get_from_set(closed_set, dst);
        }

        // find all neighbors for node
        graph.get_neighbors(way_src, neighbors);
        num_of_neighbors = neighbors.size();

        for (size_t i = 0; i < num_of_neighbors; i++) {

            path_to_neighbor = graph.get_edge_value(way_src, neighbors[i]) + distance;
            old_path = get_from_set(closed_set, neighbors[i]);

            // chech if node already in closed set
            if (old_path >= 0) {
                // if path longer - no sense to add node
                if (path_to_neighbor < old_path) {
                    set_new_path(closed_set, neighbors[i], path_to_neighbor);
                }
            } else {
                // add to open set
                add_to_set(open_set, neighbors[i], path_to_neighbor);
            }
        }
        while (2) {
            // find a node number with least path
            double least_cost_path = get_least_path(open_set, next_node, delete_num);
            if (least_cost_path > 0) {
                // if node already in closed set
                if (get_from_set(closed_set, next_node) > 0) {
                    delete_from_set(open_set, delete_num);
                } else {
                    distance = least_cost_path;
                    way_src = next_node;
                    delete_from_set(open_set, delete_num);
                    break;
                }
            } else {
                // open set is clear
                return get_from_set(closed_set, dst);
            }
        }
    }
}

void ShortestPath::add_to_set(std::vector<path_set> &set, unsigned int &node, double &path)
{
    path_set        pair;

    pair.node = node;
    pair.path_value = path;
    set.push_back(pair);
}

double ShortestPath::get_from_set(std::vector<path_set> &set, const unsigned int &node)
{
    size_t      set_size = set.size();

    for(size_t i = 0; i < set_size; i++) {
        if (set[i].node == node) {
            return set[i].path_value;
        }
    }
    return -1.0;
}

double ShortestPath::get_least_path(std::vector<path_set> &set, unsigned int &node, unsigned int &num)
{
    size_t              set_size = set.size();

    if (set_size > 0) {
        double least_path            = set[0].path_value;
        unsigned int node_least_path = set[0].node;
        unsigned int num_element     = 0;

        for(size_t i = 1; i < set_size; i++) {
            if (set[i].path_value < least_path) {
                least_path      = set[i].path_value;
                node_least_path = set[i].node;
                num_element     = static_cast<unsigned int>(i);
            }
        }
        num  = num_element;
        node = node_least_path;
        return least_path;
    }
    else {
        num  = 0;
        node = 0;
        return -1.0;
    }
}

void ShortestPath::delete_from_set(std::vector<path_set> &set, const unsigned int &num)
{
    size_t              set_size = set.size();

    if (set_size <= num) {
        return;
    }
    else {
        set.erase(set.begin() + static_cast<int>(num));
    }
}

void ShortestPath::set_new_path(std::vector<path_set> &set, const unsigned int &node, const double &path)
{
    size_t              set_size = set.size();

    for(size_t i = 0; i < set_size; i++) {
        if (set[i].node == node) {
            set[i].path_value = path;
            return;
        }
    }
}
