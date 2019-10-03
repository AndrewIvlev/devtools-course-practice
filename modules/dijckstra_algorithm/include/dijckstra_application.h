// Copyright 2019 Ivlev Andrey

#ifndef MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIJCKSTRA_APPLICATION_H_
#define MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIJCKSTRA_APPLICATION_H_

#include <string>
#include "include/dijckstra.h"

class DijckstraApplication {
 public:
    DijckstraApplication() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string Info();
};

#endif  // MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIJCKSTRA_APPLICATION_H_
