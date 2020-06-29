#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "graph.h"
#include <random>

class GraphUtils
{
public:
    GraphUtils();
    ~GraphUtils();

    // GenerateRandomEdges - generates random edges with density < dens
    // and distance range between low_dist_lim and high_dist_lim
    // Graph &graph - referance to graph
    // dens - density, must be between 0.0 and 1.0
    // low_dist_lim - low limit distance range must be between 0.0 and 100.
    // high_dist_lim - high limit distance range must be between 0.0 and 100.
    void GenerateRandomEdges(Graph &graph, double dens,
        double low_dist_lim = 1.0, double high_dist_lim = 1.0);

    // returns random number with uniform distribution from 0.0 to 1.0
    double prob(void);

    // return random number with uniform distribution from low_range to high_range
    double prob(double low_range, double high_range);
private:
    std::default_random_engine      *generator;
};

#endif
