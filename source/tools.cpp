#include "tools.h"

std::string TOOLS::base64encode(const std::string & data){
    int blocks = (data.size() + 2) / 3;
    const u_char * raw = reinterpret_cast<const u_char *>(&data);
    std::string result (blocks * 4, 0);
    for(int i = 0; i < blocks; ++i){
        result[4 * i] = (data[3 * i] & 0xfc) >> 2;
        result[4 * i + 1] = (data[3 * i] & 0x03) << 4;
        if (i * 3 + 1 >= data.size()) break;
        result[4 * i + 1] += (data[3 * i + 1] & 0xf0) >> 4;
        result[4 * i + 2] = (data[3 * i + 1] & 0x0f) << 2;
        if (i * 3 + 2 >= data.size()) break;
        result[4 * i + 2] += (data[3 * i + 2] & 0xc0) >> 6;
        result[4 * i + 3] = (data[3 * i + 2] & 0x3f);
    }
    
    for(int i = 0; i < result.size(); ++i){
        result[i] = BASE64[result[i]];
    }
    if (data.size() % 3 == 1){
        result[result.size() - 1] = '=';
        result[result.size() - 2] = '=';
    }
    if (data.size() % 3 == 2){
        result[result.size() - 1] = '=';
    }
    return result;
}

std::string TOOLS::base64decode(const std::string & data){
    int blocks = (data.size() + 3) / 4;
    int length = blocks * 3;
    if (data[data.size() - 1] == '=') --length;
    if (data[data.size() - 2] == '=') --length;

    std::string result (length, 0);
    u_char * raw = reinterpret_cast<u_char *> (&result[0]);
    

    for(int i = 0 ; i < blocks; ++i){
        raw [3 * i] = (charDecodeBase64(data[4 * i]) << 2 );
        raw [3 * i] += (charDecodeBase64(data[4 * i + 1]) & 0x30) >> 4;

        raw[3 * i + 1] = (charDecodeBase64(data[4 * i + 1]) & 0x0f) << 4;
        if (data[4 * i + 2] == '=') break;
        raw[3 * i + 1] += (charDecodeBase64(data[4 * i + 2]) & 0x3c) >> 2;
        raw[3 * i + 2] = (charDecodeBase64(data[4 * i + 2]) & 0x03) << 6;
        if (data[4 * i + 3] == '=') break;
        raw[3 * i + 2] += charDecodeBase64(data[4 * i + 3]);       
    }

    return result;
}

u_char TOOLS::charDecodeBase64(char c){
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c + 26 - 'a';
    if (c >= '0' && c <= '9') return c + 52 - '0';
    if (c == '+') return 62u;
    if (c == '/') return 63u;
    return 64u;

}