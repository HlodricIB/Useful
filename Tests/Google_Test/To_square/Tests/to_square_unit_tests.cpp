#include "tst_to_square_unit_tests.h"

TEST_F(To_square_unit_test, Size)
{
    EXPECT_EQ(static_cast<size_t>(0), t_s.size());
    EXPECT_EQ(non_squared.size(), t_s2.size());
}

TEST_F(To_square_unit_test, Default_ctor)
{
    EXPECT_EQ(static_cast<size_t>(0), t_s.size());
}

TEST_F(To_square_unit_test, From_vector_ctor)
{
    ASSERT_EQ(non_squared.size(), t_s2.size());
    checking_elements(t_s2);
}

TEST_F(To_square_unit_test, Index_operator)
{
    index_opeator(t_s2);
    t_s2[0] = 1000;
    t_s2[size_for_checking - 1] = 5000;
    EXPECT_EQ(1000, t_s2[0]);
    EXPECT_EQ(5000, t_s2[size_for_checking - 1]);
}

TEST_F(To_square_unit_test, Index_operator_const)
{
    index_opeator(t_s_const);
}

TEST_F(To_square_unit_test, Push_more)
{
    for (int i = 10, s = 1; i != 100; i += 10, ++s)
    {
        t_s2.push_more(i);
        ASSERT_EQ(size_for_checking + s, t_s2.size());
        EXPECT_EQ(i * i, t_s2[size_for_checking - 1 + s]);
    }
}
