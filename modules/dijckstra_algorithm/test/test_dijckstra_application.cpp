// Copyright 2019 Ivlev Andrey

#include <gtest/gtest.h>

#include <vector>

#include "include/dijckstra_application.h"

class DijckstraApplicationTest : public ::testing::Test {
 private:
    std::string res_;
    DijckstraApplication dijckstra_app;

 protected:
    void Act(std::vector<std::string> argv_) {
        std::vector<const char*> new_argv_;
		new_argv_.push_back("appname");

    	std::vector<const char*> vec_arg = {"appname", "add", "0", "1", "7"};
        const char** argv = &new_argv_.front();
        int argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "0", "2", "9"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "0", "5", "14"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "1", "2", "10"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "1", "3", "15"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "2", "3", "11"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "2", "5", "2"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "3", "4", "6"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);

    	vec_arg = {"appname", "add", "4", "5", "9"};
        argv = &new_argv_.front();
        argc = static_cast<int>(argv_.size()) + 1;
        res_ = dijckstra_app(argc, argv);
    	
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

TEST_F(DijckstraApplicationTest, Shortest_path_between_two_vertex) {
    // Arrange
    DijckstraApplication calc;
    std::string actual_result = "1 3 6 5";
	std::vector<std::string> vec_arg = {"sp", "0", "5"};
	
	Act(vec_arg);

    Assert(actual_result);
}

TEST_F(DijckstraApplicationTest, Validation_incorrect_input) {
    // Arrange
    DijckstraApplication calc;
    std::string actual_result = "Incorrect input.";
	std::vector<std::string> vec_arg = {"sdsfp", "02", "asd5"};
	
	Act(vec_arg);

    Assert(actual_result);
}

TEST_F(DijckstraApplicationTest, Shortest_path_between_two_vertex_which_equals) {
    // Arrange
    DijckstraApplication calc;
    std::string actual_result = "0";
	std::vector<std::string> vec_arg = {"sp", "2", "2"};
	
	Act(vec_arg);

    Assert(actual_result);
}
