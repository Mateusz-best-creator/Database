// Cmake will download it so it's ok to leave this error
#include <gtest/gtest.h>

#include "../include/database.h"
#include "../include/student.h"

TEST(CheckStructure, CanAddPersonToDatabase)
{
  Student temp{"Mateusz", "Kowalski", "ul. Prosta 100, 00-123 Warszawa", 1234, "11223344556", Gender::MALE};
  Database db;
  EXPECT_TRUE(db.add(temp));
  EXPECT_FALSE(db.add(temp)); // we should not be able to add the same student twice
}