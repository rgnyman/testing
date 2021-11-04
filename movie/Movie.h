
#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
#include <iostream>

namespace MovieDB {

class Movie {
public:

  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;

  Movie();
  Movie( const std::string& title, int priceCode = REGULAR );
  virtual ~Movie();

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;

    friend std::ostream & operator << (std::ostream &out, const Movie & o)
    {
        out << o._title;
        out << std::endl;
        out << ((int)o._priceCode);
        out << std::endl;
        return out;
    }

    friend std::istream & operator >> (std::istream &in,  Movie &o)
    {
        in >> o._title;
        in >> o._priceCode;
        return in;
    }

private:
  std::string _title;
  int _priceCode;
};

}

#endif /* MOVIE_H_ */
