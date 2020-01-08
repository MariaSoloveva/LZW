#include <iostream>
#include "../include/LZW.hpp"

void LZW::create_default_dictionary_string_to_ulong() {
    for (std::size_t i = 0; i < 256; ++i) {
        dictionaryStoU[std::string(1,i)] = i;
    }
}

void LZW::create_default_dictionary_ulong_to_string() {
    for (std::size_t i = 0; i < 256; ++i) {
        dictionaryUToS[i] = std::string(1, i);
    }
}


void LZW::Compress(const std::string& input, const std::string& output)
{
    BinaryFile* output_file;
    FILE* input_file;

    input_file = fopen(input.c_str(), "rb");
    output_file = CreateOutputBinaryFile(output.c_str());
    if (input_file != nullptr && output_file != nullptr) {
        std::cout << "Compression " + input + " in " + output << std::endl;
        if (file_size(input.c_str()) > 0) {

            unsigned int next_code = FIRST_CODE;
            std::string fraze = "";
            char character = 0;
            create_default_dictionary_string_to_ulong();

            while ((character = getc(input_file)) != EOF) {
                std::string word = fraze + character;

                if (dictionaryStoU.find(word) != dictionaryStoU.end()) {
                    fraze = word;
                } else {
                    WriteBits(output_file, (ulong)dictionaryStoU[fraze], BITS);
                    if (next_code < MAX_CODE) {
                        dictionaryStoU[word] = next_code++;
                    }
                    fraze = character;
                }
            }

            WriteBits(output_file, (uint) END_OF_STREAM, BITS);

            // закрытие файлов
            CloseOutputBFile(output_file);
            fclose(input_file);

            // вывод коэффициента сжатия
            find_compression_ratio(input.c_str(), output.c_str());
        }
        std::cout << "Compression complete." << std::endl;
    } else {
        throw std::invalid_argument("Ошибка при открытии файла для ввода\n");
    }
}

void LZW::Decompress(const std::string& input, const std::string& output)
{
    BinaryFile* input_file;
    FILE* output_file;

    // открытие входного файла для чтения
    input_file = OpenInputBinaryFile(input.c_str());

    // открытие выходного файла для записи
    output_file = fopen(output.c_str(), "wb");

    if (input_file != nullptr && output_file != nullptr) {
        printf("\nDecompression %s into %s\n", input.c_str(), output.c_str());
        if (file_size(input.c_str()) > 0) {
            uint new_code;
            uint old_code;
            char character;
            create_default_dictionary_ulong_to_string();

            uint next_code = FIRST_CODE;
            old_code = (uint)ReadBits(input_file, BITS);
            if (old_code == END_OF_STREAM)
                return;

            character = (char)old_code;
            putc(character, output_file);
            std::cout << character << std::endl;

            std::string word;
            word += character;
            std::string entry;

            while ((new_code = (uint) ReadBits(input_file, BITS)) != END_OF_STREAM) {
                if (dictionaryUToS.count(new_code)) {
                    entry = dictionaryUToS[new_code];
                } else {
                    if (new_code == next_code) {
                        entry = word + word[0];
                    } else {
                        throw std::invalid_argument("Error");
                    }
                }

                for (auto &c : entry)
                    putc(c, output_file);

                if (next_code < MAX_CODE)
                    dictionaryUToS[next_code++] = word + entry[0];
                word = entry;
            }

            // закрытие файлов
            CloseInputBFile(input_file);
            fclose(output_file);
        }
        printf("\nDecompression complete.");

    } else {
        throw std::invalid_argument("Ошибка при открытии argv3 для ввода\\n\"");
    }
}