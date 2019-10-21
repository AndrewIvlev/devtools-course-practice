// Copyright 2019 Ivlev Andrey

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/dijckstra_application.h"

class DijckstraApplicationTest : public ::testing::Test {
 private:
    std::string res_;
    DijckstraApplication dijckstra_app;

 protected:
    void Act(std::vector<std::string> argv_) {
        std::vector<const char*> new_argv_;
        std::vector<std::string> vec_arg = { "init", "graph", "6"};
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        const char** argv = &new_argv_.front();
        int argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "0", "1", "7"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "0", "2", "9"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "0", "5", "14"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "1", "2", "10"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "1", "3", "15"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "2", "3", "11"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "2", "5", "2"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "3", "4", "6"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        vec_arg = {"add", "4", "5", "9"};
        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < vec_arg.size(); i++) {
            new_argv_.push_back(vec_arg[i].c_str());
        }
        argv = &new_argv_.front();
        argc = static_cast<int>(vec_arg.size() + 1);
        res_ = dijckstra_app(argc, argv);

        new_argv_.clear();
        new_argv_.push_back("appname");
        for (size_t i = 0; i < argv_.size(); i++) {
            new_argv_.push_back(argv_[i].c_str());
        }

        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;

        res_ = dijckstra_app(argc, argv);
    }

    void Act2(std::vector<std::string> argv_) {
        std::vector<const char*> new_argv_;
        new_argv_.push_back("appname");
        for (size_t i = 0; i < argv_.size(); i++) {
            new_argv_.push_back(argv_[i].c_str());
        }
        const char** argv = &new_argv_.front();
        int argc = static_cast<int>(argv_.size() + 1);
        res_ = dijckstra_app(argc, argv);
    }

    void Assert(std::string exp) {
        EXPECT_EQ(exp, res_);
    }
};

TEST_F(DijckstraApplicationTest, Validation_incorrect_input) {
    // Arrange
    std::string expected_result = "Incorrect input.";
    std::vector<std::string> vec_arg = {"sdsfp", "02", "asd5"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validate_less_arguments) {
    // Arrange
    std::string expected_result = "Incorrect input.";
    std::vector<std::string> vec_arg = {"sp"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validation_many_arguments) {
    // Arrange
    std::string expected_result = "Incorrect input.";
    std::vector<std::string> vec_arg = {"sp", "02", "asd5", "2", "32", "13"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validation_when_first_vertex_is_incorrect) {
    // Arrange
    std::string expected_result = "Error with argument 1: not a number";
    std::vector<std::string> vec_arg = {"sp", "-9", "3"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validation_when_first_vertex_is_too_big) {
    // Arrange
    std::string expected_result = "Error with argument 1: too big number";
    std::vector<std::string> vec_arg = {"sp", "101", "3"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validation_when_second_vertex_is_incorrect) {
    // Arrange
    std::string expected_result = "Error with argument 2: not a number";
    std::vector<std::string> vec_arg = {"sp", "1", "-7"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validation_when_second_vertex_is_too_big) {
    // Arrange
    std::string expected_result = "Error with argument 2: too big number";
    std::vector<std::string> vec_arg = {"sp", "2", "101"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validation_when_both_vertex_is_incorrect) {
    // Arrange
    std::string expected_result = "Error with argument 1: not a number";
    std::vector<std::string> vec_arg = {"sp", "-99", "-7"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest, Validation_help_information) {
    // Arrange
    std::string expected_result = "Dijckstra's Algorithm.\n";
    expected_result += "Please, enter distance between";
    expected_result += " vertex in the following format:";
    expected_result += "$ <appname> init graph <number of vertex>\n";
    expected_result += "$ <appname> add <index first vertex>";
    expected_result += " <index second vertex> <weight>\n";
    expected_result += "For show shortest path between two vertex:\n";
    expected_result += "$ <appname> sp <index first vertex>";
    expected_result += " <index second vertex>\n";
    std::vector<std::string> vec_arg = {"help"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Validation_help_information_after_main_command_without_arguments) {
    // Arrange
    DijckstraApplication app;
    std::vector<const char*> new_argv_;
    new_argv_.push_back("appname");
    const char** argv = &new_argv_.front();
    std::string expected_result = "Dijckstra's Algorithm.\n";
    expected_result += "Please, enter distance between";
    expected_result += " vertex in the following format:";
    expected_result += "$ <appname> init graph <number of vertex>\n";
    expected_result += "$ <appname> add <index first vertex>";
    expected_result += " <index second vertex> <weight>\n";
    expected_result += "For show shortest path between two vertex:\n";
    expected_result += "$ <appname> sp <index first vertex>";
    expected_result += " <index second vertex>\n";

    // Act
    std::string actual_result = app(1, argv);

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}

TEST_F(DijckstraApplicationTest,
    Shortest_path_between_two_vertex_which_equals) {
    // Arrange
    std::string expected_result = "0";
    std::vector<std::string> vec_arg = {"sp", "2", "2"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Shortest_path_between_two_close_vertex) {
    // Arrange
    std::string expected_result = "4 5";
    std::vector<std::string> vec_arg = {"sp", "3", "5"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Shortest_path_between_two_vertex_front_direction) {
    // Arrange
    std::string expected_result = "1 3 6 5";
    std::vector<std::string> vec_arg = {"sp", "5", "0"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Shortest_path_between_two_vertex_reverse_direction) {
    // Arrange
    std::string expected_result = "1 3 6 5";
    std::vector<std::string> vec_arg = {"sp", "0", "5"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Cant_do_work_without_vertexes) {
    // Arrange
    std::string expected_result = "Error: graph has no vertexes";
    std::vector<std::string> vec_arg = {"init", "graph", "0"};

    Act2(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Can_init_very_big_graph) {
    // Arrange
    std::string expected_result = "Graph successfully initialized";
    std::vector<std::string> vec_arg = {"init", "graph", "100"};

    Act2(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Cant_init_very_big_graph_threshold) {
    // Arrange
    std::string expected_result = "Error with argument 2: too big number";
    std::vector<std::string> vec_arg = {"init", "graph", "101"};

    Act2(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Cant_add_weight_of_unexisting_first_vertex) {
    // Arrange
    std::string expected_result = "Error with argument 1: not a vertex";
    std::vector<std::string> vec_arg = {"init", "graph", "10"};

    Act2(vec_arg);
    vec_arg = {"add", "13", "2", "99"};
    Act2(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Cant_add_weight_of_unexisting_first_vertex_less_null) {
    // Arrange
    std::string expected_result = "Error with argument 1: not a number";
    std::vector<std::string> vec_arg = {"init", "graph", "10"};

    Act2(vec_arg);
    vec_arg = {"add", "-1", "2", "99"};
    Act2(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Cant_add_weight_of_unexisting_second_vertex) {
    // Arrange
    std::string expected_result = "Error with argument 2: not a vertex";
    std::vector<std::string> vec_arg = {"init", "graph", "10"};

    Act2(vec_arg);
    vec_arg = {"add", "2", "13", "99"};
    Act2(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Cant_add_weight_of_unexisting_second_vertex_less_null) {
    // Arrange
    std::string expected_result = "Error with argument 2: not a number";
    std::vector<std::string> vec_arg = {"init", "graph", "10"};

    Act2(vec_arg);
    vec_arg = {"add", "2", "-13", "99"};
    Act2(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Cant_add_too_big_weight) {
    // Arrange
    std::string expected_result = "Error with argument 3: too big number";
    std::vector<std::string> vec_arg = {"init", "graph", "10"};

    Act2(vec_arg);
    vec_arg = {"add", "2", "3", "12121"};
    Act2(vec_arg);

    Assert(expected_result);
}
