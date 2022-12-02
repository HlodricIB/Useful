#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

template <typename T>
class SimpleTest : public testing::Test
{
protected:

};

using testing::Types;

using Implementations = Types<int, float, double>;

TYPED_TEST_SUITE(SimpleTest, Implementations);

TYPED_TEST(SimpleTest, Test)
{
    ASSERT_EQ(5, 5);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
