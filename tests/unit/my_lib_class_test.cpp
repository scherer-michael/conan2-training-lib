#include "../../src/my_lib_class.h"

#include <gtest/gtest.h>

namespace
{
    TEST(TrainingLibTest, BasicConstructor)
    {
        MyLibClass myLibClass;
        EXPECT_EQ(0, myLibClass.member());
        EXPECT_NE(5, myLibClass.member());
    }
}