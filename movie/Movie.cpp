
#include "Movie.h"

namespace MovieDB {

Movie::Movie()
  : _title( "" )
  , _priceCode( REGULAR )
{}


Movie::Movie( const std::string& title, int priceCode )
  : _title( title )
  , _priceCode( priceCode )
{}

Movie::~Movie() {
	// TODO Auto-generated destructor stub
}

int Movie:: getPriceCode() const {
	return _priceCode; }

void Movie::setPriceCode( int arg ) {
	_priceCode = arg; }

std::string Movie::getTitle() const {
	return _title; }




}
