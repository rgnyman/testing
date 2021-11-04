#include <gtest/gtest.h>
#include "Customer.h"
#include "Movie.h"
#include "Rental.h"
#include "SimpleUi.h"

using namespace MovieDB;


class CustomerTest: public testing::Test {

protected:
	Customer customer1;
	Movie movie1, movie2, movie3;

	virtual void SetUp() {
		std::string s = "David";
		customer1 = Customer("David");
		movie1 = Movie("Gone with the Wind", Movie::REGULAR);
		movie2 = Movie("Australia", Movie::NEW_RELEASE);
		movie3 = Movie("Madagascar", Movie::CHILDRENS);
	}
};

TEST_F(CustomerTest, addRentalWith3Days) {
	Customer *testObj = new Customer("Sally");
	Movie *movie1 = new Movie("Gone with the Wind", Movie::REGULAR);
	Rental *rental1 = new Rental(*movie1, 3); // 3 day rental
	testObj->addRental(*rental1);
	ASSERT_EQ(1,testObj->getNumberRentals());
};

TEST_F (CustomerTest, TestCustomerName){
		EXPECT_EQ("David", customer1.getName());
	}

TEST_F (CustomerTest, TestStatementForRegularMovie) {
		Rental rental1(movie1, 3); // 3 day rental
		customer1.addRental(rental1);
		std::string expected = "Rental Record for David\n";
		expected += "\tGone with the Wind\t3.5\n";
		expected += "Amount owed is 3.5\n";
		expected += "You earned 1 frequent renter points";
		std::string statement = customer1.statement();
		EXPECT_EQ(expected, customer1.statement());
	}

TEST_F (CustomerTest, TestStatementForNewReleaseMovie) {
		Rental rental1(movie2, 3); // 3 day rental
		customer1.addRental(rental1);
		std::string expected = "Rental Record for David\n";
		expected += "\tAustralia\t9\n";
		expected += "Amount owed is 9\n";
		expected += "You earned 2 frequent renter points";
		std::string statement = customer1.statement();
		EXPECT_EQ(expected, customer1.statement());
	}

TEST_F (CustomerTest, TestStatementForChildrenMovie) {
		Rental rental1(movie3, 3); // 3 day rental
		customer1.addRental(rental1);
		std::string expected = "Rental Record for David\n";
		expected += "\tMadagascar\t1.5\n";
		expected += "Amount owed is 1.5\n";
		expected += "You earned 1 frequent renter points";
		std::string statement = customer1.statement();
	}

TEST_F (CustomerTest, TestStatementFor3Movies) {
	customer1.addRental(Rental(movie3, 6));
	customer1.addRental(Rental(movie2, 2));
	customer1.addRental(Rental(movie1, 8));
	std::string expected = "Rental Record for David\n";
	expected += "\tMadagascar\t6\n";
	expected += "\tAustralia\t6\n";
	expected += "\tGone with the Wind\t11\n";
	expected += "Amount owed is 23\n";
	expected += "You earned 4 frequent renter points";
	EXPECT_EQ(expected, customer1.statement());
}

TEST_F(CustomerTest, Ui) {
    SimpleUi ui;
}

