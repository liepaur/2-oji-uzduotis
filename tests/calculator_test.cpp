#include "gtest/gtest.h"
#include "calculator.h" // Dar neturime šio failo, bet TDD metu jį nurodome

// TEST_F galima naudoti sudėtingesniems scenarijams, bet paprastai
// funkcijai pakanka TEST.

// 1. Testas: Patikriname, ar teisingai sudedami du teigiami skaičiai
TEST(CalculatorTest, AddTwoPositiveNumbers) {
    Calculator calc;
    // Tikimės 5 (Expected) iš 2 + 3 (Actual)
    ASSERT_EQ(5, calc.Add(2, 3));
}

// 2. Testas: Patikriname, ar teisingai atimami du teigiami skaičiai
TEST(CalculatorTest, SubtractTwoPositiveNumbers) {
    Calculator calc;
    // Tikimės 10 (Expected) iš 20 - 10 (Actual)
    ASSERT_EQ(10, calc.Subtract(20, 10));
}

// 3. Testas: Patikriname, ar sudėtis veikia su neigiamais skaičiais
TEST(CalculatorTest, AddPositiveAndNegativeNumber) {
    Calculator calc;
    // Tikimės -1 (Expected) iš 5 + (-6) (Actual)
    ASSERT_EQ(-1, calc.Add(5, -6));
}

// 4. Testas: Kraštutinis atvejis - Atimame iš nulio
TEST(CalculatorTest, SubtractFromZero) {
    Calculator calc;
    // Tikimės -5 (Expected) iš 0 - 5 (Actual)
    ASSERT_EQ(-5, calc.Subtract(0, 5));
}

// Pagrindinė funkcija, reikalinga Google Test paleidimui
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}