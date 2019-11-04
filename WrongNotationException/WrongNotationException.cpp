//
// Created by staket on 11/4/19.
//

#include "WrongNotationException.h"

const char *WrongNotationException::what() const noexcept {
    return "Error: wrong notation";
}
