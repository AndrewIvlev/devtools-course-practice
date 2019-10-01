// Copyright 2019 Ivlev Andrey

#ifndef MODULES_DIJCKSTRA_ALGORITHM_INCLUDE_DIJCKSTRA_H_
#define MODULES_DIJCKSTRA_ALGORITHM_INCLUDE_DIJCKSTRA_H_

#include <vector>

using graph_weights_matrix = std::vector<std::vector<int>>;

class Dijckstra {
 private:
    graph_weights_matrix a_;
    int count_;  // count of vertex
 public:
    Dijckstra();
    Dijckstra(graph_weights_matrix && a, int _n) noexcept;
    Dijckstra(const Dijckstra& g);
    Dijckstra& operator=(const Dijckstra& g);
	std::vector<int> AllShortestPathsFrom(int vertex);
	std::vector<int> GetShortestPathBetween(int vertex1, int vertex2);
    void PrintMatrix();
	void InitVertexAndDist();
};
#endif  // MODULES_DIJCKSTRA_ALGORITHM_INCLUDE_DIJCKSTRA_H_
