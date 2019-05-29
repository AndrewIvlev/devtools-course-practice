// Copyright 2019 Zolotareva Olesya

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/quick-sort-application.h"

using ::testing::internal::RE;

class QuickSortApplicationTest : public ::testing::Test {
 protected:
      void Act(std::vector<std::string> args_) {
         std::vector<const char*> options;

          options.push_back("appname");
         for (size_t i = 0; i < args_.size(); ++i) {
             options.push_back(args_[i].c_str());
         }

          const char** argv = &options.front();
          int argc = static_cast<int>(args_.size()) + 1;

          output_ = app_(argc, argv);
          std::cout << std::endl << output_ << std::endl;
     }

      void Assert(std::string expected) {
         EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
     }

 private:
     QuickSortApplication app_;
     std::string output_;
};

TEST_F(QuickSortApplicationTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

     Act(args);

     Assert("This is a quick sort application\\..*");
}

TEST_F(QuickSortApplicationTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"1"};

    Act(args);

    Assert("ERROR: Check count of arguments and size of entered array\\..*");
}

TEST_F(QuickSortApplicationTest, Can_Detect_Wrong_Number_Format) {
    std::vector<std::string> args = {"e", "pi"};

    Act(args);

    Assert("Wrong number format in size!.*");
}


TEST_F(QuickSortApplicationTest, Can_Detect_Wrong_Size_Of_Array) {
    std::vector<std::string> args = {"0", "2"};

    Act(args);

    Assert("ERROR: Size must be >= 1.*");
}
