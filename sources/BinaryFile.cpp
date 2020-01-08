#include "../include/BinaryFile.hpp"

BinaryFile* CreateOutputBinaryFile(const char* name)
{
    BinaryFile *bfile = (BinaryFile*)calloc(1, sizeof(BinaryFile));
    bfile->file = fopen(name, "wb");
    bfile->rack = 0;
    bfile->mask = 0x80;
    bfile->pacifier_counter = 0;
    return bfile;
}

BinaryFile* OpenInputBinaryFile(const char* name)
{
    BinaryFile *bfile = (BinaryFile*)calloc(1, sizeof(BinaryFile));
    bfile->file = fopen(name, "rb");
    bfile->rack = 0;
    bfile->mask = 0x80;
    bfile->pacifier_counter = 0;
    return bfile;
}

void CloseOutputBFile(BinaryFile* bfile)
{
    if (bfile->mask != 0x80)
        putc(bfile->rack, bfile->file);
    fclose (bfile->file);
    free((char*)bfile);
}

void CloseInputBFile (BinaryFile* bfile)
{
    fclose (bfile->file);
    free ((char*)bfile);
}

void WriteBit(BinaryFile* bfile, int bit)
{
    if (bit)
        bfile->rack |= bfile->mask;
    bfile->mask >>= 1;
    if (bfile->mask == 0)
    {
        putc(bfile->rack, bfile->file);
        if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
            putc('.', stdout);
        bfile->rack = 0;
        bfile->mask = 0x80;
    }
}

void WriteBits(BinaryFile* bfile, ulong code, int count)
{
    ulong mask;

    mask = 1L << (count - 1);
    while (mask != 0)
    {
        if (mask & code)
            bfile->rack |= bfile->mask;
        bfile->mask >>= 1;
        if (bfile->mask == 0)
        {
            putc(bfile->rack, bfile->file);
            if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
                putc('.', stdout);
            bfile->rack = 0;
            bfile->mask = 0x80;
        }
        mask >>= 1;
    }
}

int ReadBit(BinaryFile* bfile)
{
    int value;

    if (bfile->mask == 0x80)
    {
        bfile->rack = getc(bfile->file);
        if (bfile->rack == EOF)
            throw std::invalid_argument("Error in function ReadBit!\n");

        if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
            putc('.', stdout);
    }

    value = bfile->rack & bfile->mask;
    bfile->mask >>= 1;
    if (bfile->mask == 0)
        bfile->mask = 0x80;
    return (value ? 1 : 0 );
}

ulong ReadBits(BinaryFile* bfile, int bit_count)
{
    ulong mask;
    ulong return_value;

    mask = 1L << (bit_count - 1);
    return_value = 0;
    while (mask != 0)
    {
        if (bfile->mask == 0x80)
        {
            bfile->rack = getc(bfile->file);
            if (bfile->rack == EOF)
                throw std::invalid_argument("Error in function ReadBits!\n");

            if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
                putc('.', stdout);
        }
        if (bfile->rack & bfile->mask)
            return_value |= mask;
        mask >>= 1;
        bfile->mask >>= 1;
        if (bfile->mask == 0)
            bfile->mask = 0x80;
    }

    return return_value;
}

long file_size(const char* name)
{
    long eof_ftell;
    FILE *file;

    file = fopen(name, "r");
    if (file == nullptr)
        return(0L);
    fseek(file, 0L, SEEK_END);
    eof_ftell = ftell(file);
    fclose(file);
    return eof_ftell;
}

void find_compression_ratio(const char* input, const char* output)
{
    long input_size;
    long output_size;
    int ratio;

    input_size = file_size(input);
    if ( input_size == 0 )
        input_size = 1;
    output_size = file_size(output);
    ratio = 100 - (int)(output_size * 100L / input_size);
    printf("\nInput size:        %ld bytes\n", input_size);
    printf("Output size:       %ld bytes\n", output_size);
    if (output_size == 0)
        output_size = 1;
    printf("Ratio: %d%%\n", ratio);
}
