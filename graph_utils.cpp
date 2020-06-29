#include <ctime>
#include <iostream>
#include <math.h>

#include <random>

#include "graph_utils.h"

GraphUtils::GraphUtils()
{
    generator = new std::default_random_engine(static_cast<unsigned int>(time(nullptr)));
}

GraphUtils::~GraphUtils()
{
    delete generator;
}

void GraphUtils::GenerateRandomEdges(Graph &graph, double dens,
        double low_dist_lim, double high_dist_lim)
{
    const double kMaxDistance = 100.0, kMinDistance = 0;
    const double kMaxDensity = 1.0, kMinDensity = 0.0;

    // check all input parametrs
    if (dens > kMaxDensity) {
        dens = kMaxDensity;
    } else if (dens < kMinDensity){
        dens = kMinDensity;
    }

    if (low_dist_lim > kMaxDistance) {
        low_dist_lim = kMaxDistance;
    } else if (low_dist_lim < kMinDistance){
        low_dist_lim = kMinDistance;
    }

    if (high_dist_lim > kMaxDistance) {
        high_dist_lim = kMaxDistance;
    } else if (high_dist_lim < kMinDistance){
        high_dist_lim = kMinDistance;
    }

    // low distance limit can`t be greater then high
    if (low_dist_lim > high_dist_lim) {
        double tmp = low_dist_lim;
        low_dist_lim  = high_dist_lim;
        high_dist_lim = tmp;
    }

    unsigned int size_graph = graph.V();

    // generate random edges
    for (unsigned int i = 0; i < size_graph; i++) {
        for (unsigned int j = i + 1; j < size_graph; j++) {
            // will there be an edge
            if (prob() < dens) {
                // get a random distance
                double distance = prob(low_dist_lim, high_dist_lim);
                graph.set_edge_value(i, j, distance);
            }
        }
    }
}

double GraphUtils::prob(void)
{
    // random number with uniform distribution from 0.0 to 1.0
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    double probability = distribution(*generator);
    return probability;
}

double GraphUtils::prob(double low_range, double high_range)
{
    // random number with uniform distribution from low_range to high_range
    std::uniform_real_distribution<double> distribution(low_range, high_range);

    double probability = distribution(*generator);
    return probability;
}
