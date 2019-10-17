// Copyright 2019 Ivlev Andrey

#include <algorithm>
#include <vector>
#include <iostream>

#include "../include/dijckstra.h"

Dijckstra::Dijckstra(graph_weights_matrix && aa, int _n) noexcept : a_(std::move(aa)), count_(_n) {}

Dijckstra::Dijckstra():count_(10) {
    a_.resize(count_);
    for (int i = 0; i < count_; ++i) {
        a_[i].resize(count_);
        for (int j = 0; j < count_; ++j) a_[i][j] = 0;
    }
}

Dijckstra::Dijckstra(const Dijckstra& g): count_(g.count_) {
    a_.resize(count_);
    for (int i = 0; i < count_; ++i)
        for (unsigned int j = 0; j < g.a_[i].size(); ++j)
            a_[i].push_back(g.a_[i][j]);
}

void Dijckstra::PrintMatrix() {
    for (int i = 0; i < count_; ++i) {
        for (int j = 0; j < count_; ++j)
            std::cout << a_[i][j] << " ";
        std::cout << '\n';
    }
}

void Dijckstra::InitVertexAndDist() {
	int temp;

	for (int i = 0; i<count_; i++) {
		a_[i][i] = 0;
		for (int j = i + 1; j<count_; j++) {
			std::cout << "Input distance %d" << i + 1 << " - %d: " << j + 1;
			std::cin >> temp;
			a_[i][j] = temp;
			a_[j][i] = temp;
		}
	}
}

std::vector<int> Dijckstra::AllShortestPathsFrom(int vertex) {
	std::vector<int> d_(count_, 10000);
	std::vector<int> v_(count_, 1);
	d_[vertex] = 0;

	int min_index;
	do {
		min_index = 10000;
	    int min = 10000;
		for (int i = 0; i < count_; i++) {
			if (v_[i] == 1 && d_[i] < min) {
				min = d_[i];
				min_index = i;
			}
		}
	    if (min_index != 10000) {
	    	for (int i = 0; i < count_; i++) {
	    		if (a_[min_index][i] > 0)
				{
	    			int temp = min + a_[min_index][i];
	    			if (temp < d_[i]) {
	    				d_[i] = temp;
	    			}
				}
	    	}
	    	v_[min_index] = 0;
	    }
	} while (min_index < 10000);

	std::cout << "The shortest distance:" << '\n';
	for (size_t i = 0; i < d_.size(); i++) {
		std::cout << d_[i] << " ";
	}
    std::cout << '\n';
	return d_;
}

std::vector<int> Dijckstra::GetShortestPathBetween(int vertex1, int vertex2)
{
	std::vector<int> result;
	if (vertex1 > vertex2) {
		std::swap(vertex1, vertex2);
	}
	if (vertex1 == vertex2) {
		result.push_back(0);
		return result;
	}
	std::vector<int> d_ = AllShortestPathsFrom(vertex1);
	std::vector<int> ver(count_, 0);
	int end = vertex2 - 1;
	ver[0] = end + 1;
	int k = 1;
	int weight = d_[end];

	while (end != vertex1) {
		for (int i = 0; i < count_; i++) {
			if (a_[end][i] != 0) {
				int temp = weight - a_[end][i];
				if (temp == d_[i])
				{
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
		}
	}

	std::cout << "The shortest path:" << '\n';
	for (int i = k - 1; i >= 0; i--) {
	    std::cout << ver[i] << " ";
		result.push_back(ver[i]);
	}
    std::cout << '\n';
	return result;
}

Dijckstra& Dijckstra::operator=(const Dijckstra& g) {
    count_ = g.count_;
    a_ = g.a_;
    return *this;
}
