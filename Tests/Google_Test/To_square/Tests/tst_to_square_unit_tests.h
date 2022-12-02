#ifndef TST_TO_SQUARE_UNIT_TESTS_H
#define TST_TO_SQUARE_UNIT_TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "to_square.h"

using namespace testing;

class To_square_unit_test : public testing::Test
{
protected:
    void SetUp() override
    {
        size_for_checking = non_squared.size();
    }
    std::vector<int> non_squared { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    size_t size_for_checking;
    To_square t_s;
    To_square t_s2{non_squared};
    const To_square t_s_const{ non_squared };
    void checking_elements(const To_square& t_s)
    {
        for (size_t i = 0; i != t_s.size(); ++i)
        {
            int temp = non_squared[i] * non_squared[i];
            EXPECT_EQ(temp, t_s[i]);
        }
    }

    void index_opeator(const To_square& t_s)
    {
        EXPECT_EQ(1, t_s[0]);
        EXPECT_EQ(16, t_s[3]);
        EXPECT_EQ(100, t_s[9]);
    }
};

#endif // TST_TO_SQUARE_UNIT_TESTS_H
