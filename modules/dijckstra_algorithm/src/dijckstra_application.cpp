// Copyright 2019 Ivlev Andrey

#include <string>
#include <stdexcept>
#include "include/dijckstra_application.h"

std::string DijckstraApplication::Info() {
    std::string res = "Dijckstra's Algorithm.\n";
    res += "Please, enter distance between vertex in the following format:";
	res += "$ <appname> init graph <number of veterx>\n";
    res += "$ <appname> add <index first vertex> <index second vertex> <weight>\n";
    res += "For show shortest path between two vertex:\n";
	res += "$ <appname> sp <index first vertex> <index second vertex>\n";
    res += "For start calculation:\n";
	res += "$ <appname> start calculation\n";
    return res;
}
std::string DijckstraApplication::operator()(int argc, const char** argv) {
    if (argc == 2) {
        if (std::string(argv[1]) == "help") {
            return Info();
        }
    }
	
	if (argc == 3) {
        if (std::string(argv[1]) == "start" && std::string(argv[2]) == "calculation") {
            return Info();
        }
    }
	int n = 0;
	if (argc == 4) {
        if (std::string(argv[1]) == "init" && std::string(argv[2]) == "graph") {
            n = (int)argv[3];
        }
    }

	graph_weights_matrix m;
	if (std::string(argv[1]) == "add") {
		m[(int)argv[2]][(int)argv[3]] = (int)argv[4];
		m[(int)argv[3]][(int)argv[2]] = (int)argv[4];
	}
	
	if (std::string(argv[1]) == "sp") {
		Dijckstra g(std::move(m), n);
		std::vector<int> sp = g.GetShortestPathBetween((int)argv[3], (int)argv[4]);
		std::string res;
		for (int i : sp) {
			res += char(i);
		}
		return res;
	}
	
	return "Incorrect input.";
}
