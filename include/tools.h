#pragma once 

#include <string>
#include <string.h>
#include <iostream>

typedef unsigned char u_char;

namespace TOOLS{
    const std::string BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string base64encode(const std::string & data);
    std::string base64decode(const std::string & data);
    u_char charDecodeBase64(char c);
    // char BASE64(int i);
}