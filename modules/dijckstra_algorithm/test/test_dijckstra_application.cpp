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

    void Assert(std::string exp) {
        EXPECT_EQ(exp, res_);
    }
};

TEST_F(DijckstraApplicationTest, Validation_incorrect_input) {
    // Arrange
    DijckstraApplication calc;
    std::string expected_result = "Incorrect input.";
    std::vector<std::string> vec_arg = {"sdsfp", "02", "asd5"};

    Act(vec_arg);

    Assert(expected_result);
}

TEST_F(DijckstraApplicationTest,
    Shortest_path_between_two_vertex_which_equals) {
    // Arrange
    DijckstraApplication calc;
    std::string expected_result = "0";
    std::vector<std::string> vec_arg = {"sp", "2", "2"};

    Act(vec_arg);

    Assert(expected_result);
}
