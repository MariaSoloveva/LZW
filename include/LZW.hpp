#ifndef LZW_LZW_HPP
#define LZW_LZW_HPP

#define BITS                       12
#define MAX_CODE                   (1 << BITS ) - 1
#define END_OF_STREAM              256
#define FIRST_CODE                 257


#include <string>
#include <unordered_map>
#include <vector>

#include "BinaryFile.hpp"

class LZW {
    std::unordered_map<std::string, uint> dictionaryStoU;
    std::unordered_map<uint, std::string> dictionaryUToS;
public:
    LZW() = default;
    ~LZW() = default;

///@brief Функция инициализации словаря ключами строка - биты
    void create_default_dictionary_string_to_ulong();

///@brief Функция инициализации словаря ключами биты - строка,
    void create_default_dictionary_ulong_to_string();

///@brief Функция сжатия файла
    void Compress(const std::string& input, const std::string& output);


///@brief Функция декодирования сжатого файла
    void Decompress(const std::string&, const std::string&);
};


#endif //LZW_LZW_HPP
