#include <iostream>
#include "graph.h"
#include "graph_utils.h"
#include "shortest_path.h"


using namespace std;

int main(void)
{
    const unsigned int      kGraphSize = 50;
    const double            kGraphDist1 = 0.2;
    const double            kGraphDist2 = 0.4;
    const double            kLowEdgeCost = 1.0;
    const double            kHighEdgeCost = 10.0;

    // Creates graphs with number of edges kGraphSize
    Graph           graph1(kGraphSize), graph2(kGraphSize);
    GraphUtils      utils1, utils2;
    ShortestPath    sh_path;
    double          av_path_lengt = 0.0;
    unsigned int    used_nodes = 0;

    // Generate Random Edges for graphs
    utils1.GenerateRandomEdges(graph1, kGraphDist1, kLowEdgeCost, kHighEdgeCost);
    utils2.GenerateRandomEdges(graph2, kGraphDist2, kLowEdgeCost, kHighEdgeCost);

    // calculate average path from first node to next, until last
    for (unsigned int i = 0; i < graph1.V(); i++) {
        double path_length = sh_path.path_size(graph1, 0, i);
        if (path_length < 0)
            continue;
        av_path_lengt += path_length;
        used_nodes++;
    }
    av_path_lengt /= used_nodes;

    cout << "Graph1 with characteristics \n"
         << "Vertexes = " + std::to_string(graph1.V()) << "\n"
         << "Edges = "  + std::to_string(graph1.E()) << "\n"
         << "Avarage Distribution = " + std::to_string(kGraphDist1) << "\n"
         << "Avarage path length = " + std::to_string(av_path_lengt) << "\n"
         << "Connected Nodes = " << used_nodes << "\n"
         << endl;

    // calculate average path from first node to next, until last
    used_nodes = 0;
    for (unsigned int i = 0; i < graph1.V(); i++) {
        double path_length = sh_path.path_size(graph2, 0, i);
        if (path_length < 0)
            continue;
        av_path_lengt += path_length;
        used_nodes++;
    }
    av_path_lengt /= used_nodes;

    cout << "Graph2 with characteristics \n"
         << "Vertexes = " + std::to_string(graph2.V()) << "\n"
         << "Edges = "  + std::to_string(graph2.E()) << "\n"
         << "Avarage Distribution = " + std::to_string(kGraphDist2) << "\n"
         << "Avarage path length = " + std::to_string(av_path_lengt) << "\n"
         << "Connected Nodes = " << used_nodes << "\n"
         << endl;

    cout << "Successful! Press any key to continue..." << endl;
    cin.get();

    return 0;
}
