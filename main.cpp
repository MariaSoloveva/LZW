#include <stdexcept>

#include "include/LZW.hpp"

///@brief Основная функция
int main(int argc, char* argv[])
{
    LZW lzw;
    if (argv[2] == "compress") {
        lzw.Compress(argv[0], argv[1]);
    } else if (argv[2] == "decompress") {
        lzw.Compress(argv[0], argv[1]);
    }
    return 0;
}