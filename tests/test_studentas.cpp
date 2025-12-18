#include <gtest/gtest.h>
#include "studentas.h"
#include <sstream>

TEST(StudentasTest, Vidurkis) {
    std::stringstream ss("Jonas Jonaitis 8 9 10 9");
    Studentas s(ss);
    EXPECT_DOUBLE_EQ(s.skaiciuotiVidurki(), 9.0);
}

TEST(StudentasTest, Mediana) {
    std::vector<int> v = {5, 10, 7};
    EXPECT_DOUBLE_EQ(mediana(v), 7);
}
