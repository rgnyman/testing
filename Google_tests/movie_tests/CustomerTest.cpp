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

TEST_F (CustomerTest, TestCustomerName){
	ASSERT_EQ("David", customer1.getName());
}

