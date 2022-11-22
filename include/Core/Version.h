#include <sstream>

#ifndef SPEEDY_VERSION_H
#define SPEEDY_VERSION_H

#define SPEEDY_MAJOR_VERSION 0
#define SPEEDY_MINOR_VERSION 1
#define SPEEDY_PATCH_VERSION 0

namespace Speedy
{

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