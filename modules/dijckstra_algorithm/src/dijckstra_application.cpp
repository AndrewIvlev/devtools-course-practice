// Copyright 2019 Ivlev Andrey

#include <cstring>
#include <string>
#include <vector>
#include <stdexcept>
#include "include/dijckstra_application.h"

std::string DijckstraApplication::Info() {
    std::string res = "Dijckstra's Algorithm.\n";
    res += "Please, enter distance between vertex in the following format:";
    res += "$ <appname> init graph <number of vertex>\n";
    res += "$ <appname> add <index first vertex>";
    res += " <index second vertex> <weight>\n";
    res += "For show shortest path between two vertex:\n";
    res += "$ <appname> sp <index first vertex> <index second vertex>\n";
    res += "For start calculation:\n";
    res += "$ <appname> start calculation\n";
    return res;
}
std::string DijckstraApplication::operator()(int argc, const char** argv) {
    if (argc <= 1) {
        return Info();
    }

    if (argc == 2) {
        if (strcmp(argv[1], "help") == 0) {
            return Info();
        }
        return "Incorrect input.";
    }

    if (argc == 3) {
        if (strcmp(argv[1], "start") == 0 &&
            strcmp(argv[2], "calculation") == 0) {
            return Info();
        }
        return "Incorrect input.";
    }

    if (argc == 4) {
        if (strcmp(argv[1], "init") == 0 && strcmp(argv[2], "graph") == 0) {
            try {
                vertex_num = CastNumber(argv[3]);
                m.resize(vertex_num);
                for (int i = 0; i < vertex_num; ++i) {
                    m[i].resize(vertex_num);
                    for (int j = 0; j < vertex_num; ++j) m[i][j] = 0;
                }
            }
            catch(const std::runtime_error& re) {
                return "Error with argument " +
                    std::to_string(2) + ": " + re.what();
            }
        } else if (strcmp(argv[1], "sp") == 0) {
            try {
            Dijckstra g(std::move(m), vertex_num);
                int vertex1 = CastNumber(argv[2]);
                int vertex2 = CastNumber(argv[3]);
                if (vertex1 < 0 || vertex2 < 0 ||
                    vertex1 > vertex_num - 1 || vertex2 > vertex_num - 1) {
                    return "Incorrect input.";
                }
                std::vector<int> sp = g.GetShortestPathBetween(
                    vertex1, vertex2);
                std::string res = "";
                for (size_t i = 0; i < sp.size(); i++) {
                    res += std::to_string(sp[i]);
                    if ( i != sp.size() - 1) res += " ";
                }
                return res;
            }
            catch(const std::runtime_error& re) {
                return "Error with argument " +
                    std::to_string(2) + ": " + re.what();
            }
        } else {
            return "Incorrect input.";
        }
    }

    if (strcmp(argv[1], "add") == 0) {
        try {
            m[CastNumber(argv[2])][CastNumber(argv[3])] = CastNumber(argv[4]);
            m[CastNumber(argv[3])][CastNumber(argv[2])] = CastNumber(argv[4]);
            return "";
        }
        catch(const std::runtime_error& re) {
            return "Error with argument " +
                std::to_string(2) + ": " + re.what();
        }
    }

    return "Incorrect input.";
}

int DijckstraApplication::CastNumber(const char* num) {
    unsigned i = 0;
    int x;
    while (num[i] != '\0') {
        if (!isdigit(num[i]))
            throw std::runtime_error("not a number");
        ++i;
    }
    try {
        x = std::stoi(num);
    }
    catch (std::out_of_range& err) {
        throw std::runtime_error("too big number");
    }
    if (x > 50)
        throw std::runtime_error("too big number");
    return x;
}
