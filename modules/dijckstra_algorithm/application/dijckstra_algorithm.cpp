// Copyright 2019 Ivlev Andrey

#include <iostream>
#include "include/dijckstra_application.h"

int main(int argc, const char** argv) {
    DijckstraApplication app;
    std::cout << app(argc, argv);
    return 0;
}
