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
        l = {
            { 0, 7, 9, 0, 0, 14 },
            { 7, 0, 10, 15, 0, 0 },
            { 9, 10, 0, 11, 0, 2 },
            { 0, 15, 11, 0, 6, 0 },
            { 0, 0, 0, 6, 0, 9 },
            { 14, 0, 2, 0, 9, 0 }
        };
        for (auto it : l) {
            a[i].insert(a[i].end(), it.begin(), it.end());
            i++;
        }
    }
};

TEST_F(DijckstraTest, check_correctness_of_Dijckstra_algorithm) {
    // Arrange
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
    init();
    Dijckstra g(std::move(a), n);

    // Act
    bool actual = g.PrintMatrix();

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST_F(DijckstraTest,
    equals_result_of_equals_dijckstra_objects) {
    // Arrange
    init();
    Dijckstra g(std::move(a), n);
    Dijckstra g_copy(g);

    // Act
    std::vector<int> path_g = g.GetShortestPathBetween(5, 0);
    std::vector<int> path_g_copy = g_copy.GetShortestPathBetween(5, 0);

    // Assert
    EXPECT_EQ(path_g, path_g_copy);
}

TEST_F(DijckstraTest,
    equals_result_of_equals_dijckstra_objects_by_operator_equality) {
    // Arrange
    init();
    Dijckstra g(std::move(a), n);
    Dijckstra g_copy(std::move(a), n);

    // Act
    g_copy = g;
    std::vector<int> path_g = g.GetShortestPathBetween(5, 0);
    std::vector<int> path_g_copy = g_copy.GetShortestPathBetween(5, 0);

    // Assert
    EXPECT_EQ(path_g, path_g_copy);
}

TEST_F(DijckstraTest,
    validate_invalid_input_for_get_all_shortest_path) {
    // Arrange
    init();
    Dijckstra g(std::move(a), n);
    std::vector<int> expected_v(n, 1);

    // Act
    std::vector<int> actual_v = g.AllShortestPathsFrom(-2);

    // Assert
    EXPECT_EQ(expected_v, actual_v);
}

TEST_F(DijckstraTest,
    validate_all_shortest_path_from_one_vertex) {
    // Arrange
    init();
    Dijckstra g(std::move(a), n);
    std::vector<int> expected_v { 11, 12, 2, 13, 9, 0 };

    // Act
    std::vector<int> actual_v = g.AllShortestPathsFrom(5);

    // Assert
    EXPECT_EQ(expected_v, actual_v);
}

TEST_F(DijckstraTest,
    validate_all_shortest_path_from_equal_vertex) {
    // Arrange
    init();
    Dijckstra g(std::move(a), n);
    std::vector<int> expected_v { 20, 15, 11, 0, 6, 13 };

    // Act
    std::vector<int> actual_v = g.AllShortestPathsFrom(3);

    // Assert
    EXPECT_EQ(expected_v, actual_v);
}

TEST_F(DijckstraTest,
    validate_all_shortest_path_from_anouther_vertex) {
    // Arrange
    init();
    Dijckstra g(std::move(a), n);
    std::vector<int> expected_v { 20, 21, 11, 6, 0, 9 };

    // Act
    std::vector<int> actual_v = g.AllShortestPathsFrom(4);

    // Assert
    EXPECT_EQ(expected_v, actual_v);
}

TEST_F(DijckstraTest,
    validate_all_shortest_path_from_first_vertex) {
    // Arrange
    init();
    Dijckstra g(std::move(a), n);
    std::vector<int> expected_v { 0, 7, 9, 20, 20, 11 };

    // Act
    std::vector<int> actual_v = g.AllShortestPathsFrom(0);

    // Assert
    EXPECT_EQ(expected_v, actual_v);
}
