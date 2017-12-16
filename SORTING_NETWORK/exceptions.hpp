//
//  exceptions.hpp
//  SORTING_NETWORK
//
//  Created by Galambos Mihály on 2017. 12. 08..
//  Copyright © 2017. Galambos Mihály. All rights reserved.
//

#ifndef exceptions_h
#define exceptions_h

#include <exception>

class invalid_size : public std::exception
{
public:
    const char* what() const throw() { return "Nem kettőhatvány méretű a kapott tömb"; }
};


#endif /* exceptions_h */
