
#ifndef PRACT_1_WRONGNOTATIONEXCEPTION_H
#define PRACT_1_WRONGNOTATIONEXCEPTION_H

#include <exception>

class WrongNotationException: public std::exception{
    const char *what() const noexcept override;
};

#endif //PRACT_1_WRONGNOTATIONEXCEPTION_H
