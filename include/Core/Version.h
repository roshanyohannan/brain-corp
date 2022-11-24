#ifndef SPEEDY_VERSION_H
#define SPEEDY_VERSION_H

#include <sstream>

#define SPEEDY_MAJOR_VERSION 0      //!< Major version of Speedy library 
#define SPEEDY_MINOR_VERSION 1      //!< Minor version of Speedy library
#define SPEEDY_PATCH_VERSION 0      //!< Patch version of Speedy library

namespace Speedy
{

//! \brief  Returns a string containing version in the Major.Minor.Patch format
std::string version()
{
    std::ostringstream stream;
    stream  << SPEEDY_MAJOR_VERSION << "."
            << SPEEDY_MINOR_VERSION << "."
            << SPEEDY_PATCH_VERSION;

    return stream.str();
}

} //namespace 
#endif