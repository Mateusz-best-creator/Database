#include <gtest/gtest.h>
#include <sstream> // for stringstream

#include "../include/database.h"
#include "../include/student.h"

class DatabaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any common setup code goes here
    }

    void TearDown() override {
        // Any common teardown code goes here
    }

    // Declare any member variables you need for your tests
    Database db;
};

TEST_F(DatabaseTest, CanAddPersonToDatabase)
{
  Student temp{"Mateusz", "Kowalski", "ul. Prosta 100, 00-123 Warszawa", 1234, "11223344556", Gender::MALE};
  EXPECT_TRUE(db.add(temp));
  EXPECT_FALSE(db.add(temp)); // we should not be able to add the same student twice
}

TEST_F(DatabaseTest, CanDisplayDatabaseRecords)
{
  Student temp{"Mateusz", "Kowalski", "ul. Prosta 100, 00-123 Warszawa", 1234, "11223344556", Gender::MALE};
  EXPECT_TRUE(db.add(temp));
  
  std::stringstream expected_output;
  expected_output << "Students Database:\n\n";
  expected_output << "ID: " << temp.get_id() << std::endl;
  expected_output << "Student fullname: " << temp.get_name() << " " << temp.get_surname() << std::endl;
  expected_output << "Street: " << temp.get_street() << std::endl;
  expected_output << "Pesel: " << temp.get_pesel() << std::endl;
  expected_output << "\n===================\n";

  // Redirect cout to a stringstream
  std::stringstream captured_output;
  std::streambuf* cout_buffer = std::cout.rdbuf();
  std::cout.rdbuf(captured_output.rdbuf());

  // Call the display function
  db.display();

  // Restore cout
  std::cout.rdbuf(cout_buffer);

  // Compare the expected output with the captured output
  EXPECT_EQ(captured_output.str(), expected_output.str());
}

TEST_F(DatabaseTest, DatabaseEmptyWhenNoStudentsAdded)
{
  // Redirect cout to a stringstream to capture the output
  std::stringstream captured_output;
  std::streambuf* cout_buffer = std::cout.rdbuf();
  std::cout.rdbuf(captured_output.rdbuf());

  // Call the display function
  db.display();

  // Restore cout
  std::cout.rdbuf(cout_buffer);

  // Check if the captured output indicates an empty database
  EXPECT_EQ(captured_output.str(), "Students Database:\n\nDatabase is empty\n");
}

TEST_F(DatabaseTest, DatabaseCanSearchBySurname)
{
  Student temp1{"Mateusz", "Kowalski", "ul. Prosta 100, 00-123 Warszawa", 1234, "11223344556", Gender::MALE};
  Student temp2{"Jan", "Nowak", "ul. Prosta 100, 00-123 Warszawa", 1234, "11223344556", Gender::MALE};  
  Student temp3{"Andrzej", "Krajnik", "ul. Prosta 100, 00-123 Warszawa", 1234, "11223344556", Gender::MALE};

  db.add(temp1);
  db.add(temp2);
  db.add(temp3);

  EXPECT_TRUE(db.search_by_surname("Nowak"));
  EXPECT_FALSE(db.search_by_surname("Nowosielski"));
}

