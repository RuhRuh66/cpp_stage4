#include <gtest/gtest.h>
#include <iostream>

struct Patient {
    int age;
    double fev;
};

class PatientTest: public ::testing::Test {
protected:
    Patient patient1;
    Patient patient2;

    void SetUp() override {
        std::cout << "setup called\n";

        patient1 = {65, 1.82};
        patient2 = {72, 2.56};
    }
    void TearDown() override {
        std::cout << "TearDown called\n";
    }
};

TEST_F(PatientTest, CheckAge) {
    EXPECT_EQ(patient1.age, 35);
    EXPECT_EQ(patient2.age, 48);
}

TEST_F(PatientTest, CompareFev) {
    EXPECT_LT(patient1.fev, patient2.fev);
}
