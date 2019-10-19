// Copyright 2019 Ivlev Andrey

#include <gtest/gtest.h>

#include <vector>

#include "include/dijckstra.h"

using list = std::initializer_list<std::initializer_list<int>>;

class DijckstraTest : public ::testing::Test {
 protected:
    int n = 6;
    graph_weights_matrix a;
    list l;
    void init() {
        a.resize(n);
        int i = 0;
        for (auto it : l) {
            a[i].insert(a[i].end(), it.begin(), it.end());
            i++;
        }
    }
};

TEST_F(DijckstraTest, check_correctness_of_Dijckstra_algorithm) {
    // Arrange
    l = {
        { 0, 7, 9, 0, 0, 14 },
        { 7, 0, 10, 15, 0, 0 },
        { 9, 10, 0, 11, 0, 2 },
        { 0, 15, 11, 0, 6, 0 },
        { 0, 0, 0, 6, 0, 9 },
        { 14, 0, 2, 0, 9, 0 }
    };
    init();
    Dijckstra g(std::move(a), n);

    // Act
    std::vector<int> expected{ 1, 3, 6, 5 };
    std::vector<int> actual = g.GetShortestPathBetween(0, 5);

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST_F(DijckstraTest,
    check_correctness_of_Dijckstra_algorithm_from_other_vertex) {
    // Arrange
    l = {
        { 0, 7, 9, 0, 0, 14 },
        { 7, 0, 10, 15, 0, 0 },
        { 9, 10, 0, 11, 0, 2 },
        { 0, 15, 11, 0, 6, 0 },
        { 0, 0, 0, 6, 0, 9 },
        { 14, 0, 2, 0, 9, 0 }
    };
    init();
    Dijckstra g(std::move(a), n);

    // Act
    std::vector<int> expected{ 1, 3, 6, 5 };
    std::vector<int> actual = g.GetShortestPathBetween(5, 0);

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST_F(DijckstraTest,
    can_print_matrix_weights) {
    // Arrange
    bool expected = true;
    l = {
        { 0, 7, 9, 0, 0, 14 },
        { 7, 0, 10, 15, 0, 0 },
        { 9, 10, 0, 11, 0, 2 },
        { 0, 15, 11, 0, 6, 0 },
        { 0, 0, 0, 6, 0, 9 },
        { 14, 0, 2, 0, 9, 0 }
    };
    init();
    Dijckstra g(std::move(a), n);

    // Act
    bool actual = g.PrintMatrix();

    // Assert
    EXPECT_EQ(expected, actual);
}
