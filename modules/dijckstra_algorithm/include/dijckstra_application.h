// Copyright 2019 Ivlev Andrey

#ifndef MODULES_DIJCKSTRA_ALGORITHM_INCLUDE_DIJCKSTRA_APPLICATION_H_
#define MODULES_DIJCKSTRA_ALGORITHM_INCLUDE_DIJCKSTRA_APPLICATION_H_

#include <string>
#include "include/dijckstra.h"

class DijckstraApplication {
 public:
    DijckstraApplication() = default;
    std::string operator()(int argc, const char** argv);
 private:
	graph_weights_matrix m;
	int vertex_num;
    std::string Info();
    int CastNumber(const char* num);
};

#endif  // MODULES_DIJCKSTRA_ALGORITHM_INCLUDE_DIJCKSTRA_APPLICATION_H_
