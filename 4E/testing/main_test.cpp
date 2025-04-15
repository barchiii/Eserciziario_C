#include <gtest/gtest.h>
extern "C" {
    #include "calcolatrice.h"
}

// Test per la calcolatrice
TEST(CalcolatriceTest, Somma) {
    EXPECT_DOUBLE_EQ(somma(3, 4), 7);
}

TEST(CalcolatriceTest, Sottrazione) {
    EXPECT_DOUBLE_EQ(sottrazione(10, 4), 6);
}

TEST(CalcolatriceTest, Moltiplicazione) {
    EXPECT_DOUBLE_EQ(moltiplicazione(3, 5), 15);
}

TEST(CalcolatriceTest, Divisione) {
    EXPECT_DOUBLE_EQ(divisione(8, 2), 4);
}

TEST(CalcolatriceTest, DivisionePerZero) {
    EXPECT_DOUBLE_EQ(divisione(5, 0), 0);  // Gestione errore: ritorna 0
}

TEST(CalcolatriceTest, Potenza) {
    EXPECT_DOUBLE_EQ(potenza(2, 3), 8);
}

TEST(CalcolatriceTest, Radice) {
    EXPECT_DOUBLE_EQ(radice(16), 4);
}

TEST(CalcolatriceTest, RadiceNegativa) {
    EXPECT_DOUBLE_EQ(radice(-4), 0);  // Gestione errore: ritorna 0
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
