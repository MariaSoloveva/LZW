#ifndef LZW_2017_VERSION_BINARYFILE_HPP
#define LZW_2017_VERSION_BINARYFILE_HPP

#define PACIFIER_COUNT 2047

#include <exception>
#include <stdexcept>

typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;

///@brief Структура хранящая указатель на бинарный файл и информацию о нём
struct BinaryFile {
public:
    FILE* file;
    uchar mask;
    int rack;
    int pacifier_counter;
};

///@brief Функция создания бинарного файла
BinaryFile* CreateOutputBinaryFile(const char*);

///@brief Функция открытия файла для побитового чтения
BinaryFile* OpenInputBinaryFile(const char*);

///@brief Функция закрытия файла для побитовой записи
void CloseOutputBFile (BinaryFile*);

///@brief Функция закрытия файла для побитового чтения
void CloseInputBFile (BinaryFile*);

///@brief Функция вывода одного бита
void WriteBit(BinaryFile*, int);

///@brief Функция вывода нескольких битов
void WriteBits(BinaryFile*, ulong, int);

///@brief Функция ввода одного бита
int ReadBit(BinaryFile*);

///@brief Функция ввода нескольких битов
ulong ReadBits(BinaryFile*, int);

///@brief Функция измерения размера файла
long file_size (const char*);

///@brief Функция вывода сообщения о соотношении размеров файлов
void find_compression_ratio(const char*, const char*);


#endif
