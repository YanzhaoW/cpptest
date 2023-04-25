#include "class1.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(ProductTest, test1)
{
    auto pro = Product{ 1, 2.9 };
    auto res = pro.Get();
    ASSERT_EQ(res, 2.9);
}

TEST(ProductTest, test2)
{
    auto pro = Product{ 1, 2.9 };
    auto res = pro.Get();
    ASSERT_EQ(res, 2.9);
}

class ProdTest : public ::testing::Test
{
  protected:
    ProdTest() { std::cout << "protest is created" << std::endl; }
    void SetUp() override { std::cout << "protest is setup" << std::endl;};
    void TearDown() override { std::cout << "protest is torndown" << std::endl;};
    ~ProdTest() override { std::cout << "protest is deleted" << std::endl; }
    double a = 4;
  private:
};

void TestTry(double fac1, double fac2, double ProdRes) { auto pro = Product{ fac1, fac2 };
    EXPECT_DOUBLE_EQ(pro.Get(), ProdRes);
}

TEST_F(ProdTest, test3)
{
    {
        SCOPED_TRACE("");
        TestTry(1.6, a, 6.4);
    }
}

TEST_F(ProdTest, test5)
{
    {
        SCOPED_TRACE("");
        TestTry(1.6, 2, 3.2);
    }
}

auto main(int argc, char** argv) -> int
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
