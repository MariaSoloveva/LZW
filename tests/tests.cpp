#include <fstream>
#include "gtest/gtest.h"
#include "../include/LZW.hpp"

bool compare_files(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1, std::ios::binary);
    std::ifstream f2(file2, std::ios::binary);
    bool flag1 = (f1.peek() == std::ifstream::traits_type::eof());
    bool flag2 = (f2.peek() == std::ifstream::traits_type::eof());
    if (flag1) {
        if (flag2) {
            return true;
        }
    }
    if (f1.is_open() && f2.is_open())
    {
        char ch1 = 0, ch2 = 0;
        while (f1.get(ch1) && f2.get(ch2))
        {
            if (ch1 != ch2)
            {
                f1.close();
                f2.close();
                return false;
            }
        }
    } else {
        f1.close();
        f2.close();
        return false;
    }
    f1.close();
    f2.close();
    return true;
}


TEST(empty_file, empty_file_test) {
    std::string file_to_compress = "../tests/Test1/Test1.dat";
    std::string compressed = "../tests/Test1/Test1.lzw";
    std::string decompressed_file = "../tests/Test1/Test1.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(text_file, text_file_test) {
    std::string file_to_compress = "../tests/Test2/Test2.dat";
    std::string compressed = "../tests/Test2/Test2.lzw";
    std::string decompressed_file = "../tests/Test2/Test2.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(Joeyn, Joeyn_test) {
    std::string file_to_compress = "../tests/Test3/Test3.dat";
    std::string compressed = "../tests/Test3/Test3.lzw";
    std::string decompressed_file = "../tests/Test3/Test3.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(Cpp_file, Cpp_file_test) {
    std::string file_to_compress = "../tests/Test4/Test4.dat";
    std::string compressed = "../tests/Test4/Test4.lzw";
    std::string decompressed_file = "../tests/Test4/Test4.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(JPG_file, JPG_file_test) {
    std::string file_to_compress = "../tests/Test5/Test5.dat";
    std::string compressed = "../tests/Test5/Test5.lzw";
    std::string decompressed_file = "../tests/Test5/Test5.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(PNG_file, PNG_file_test) {
    std::string file_to_compress = "../tests/Test6/Test6.dat";
    std::string compressed = "../tests/Test6/Test6.lzw";
    std::string decompressed_file = "../tests/Test6/Test6.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(TAR_GZ_file, TAR_GZ_file_test) {
    std::string file_to_compress = "../tests/Test7/Test7.dat";
    std::string compressed = "../tests/Test7/Test7.lzw";
    std::string decompressed_file = "../tests/Test7/Test7.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(RAR_file, RAR_file_test) {
    std::string file_to_compress = "../tests/Test8/Test8.dat";
    std::string compressed = "../tests/Test8/Test8.lzw";
    std::string decompressed_file = "../tests/Test8/Test8.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(TIFF_file, TIFF_file_test) {
    std::string file_to_compress = "../tests/Test9/Test9.dat";
    std::string compressed = "../tests/Test9/Test9.lzw";
    std::string decompressed_file = "../tests/Test9/Test9.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(GIF_file, GIF_file_test) {
    std::string file_to_compress = "../tests/Test10/Test10.dat";
    std::string compressed = "../tests/Test10/Test10.lzw";
    std::string decompressed_file = "../tests/Test10/Test10.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(HTML_file, HTML_file_test) {
    std::string file_to_compress = "../tests/Test11/Test11.dat";
    std::string compressed = "../tests/Test11/Test11.lzw";
    std::string decompressed_file = "../tests/Test11/Test11.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(MP4_file, MP4_file_test) {
    std::string file_to_compress = "../tests/Test12/Test12.dat";
    std::string compressed = "../tests/Test12/Test12.lzw";
    std::string decompressed_file = "../tests/Test12/Test12.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(PDF_file, PDF_file_test) {
    std::string file_to_compress = "../tests/Test13/Test13.dat";
    std::string compressed = "../tests/Test13/Test13.lzw";
    std::string decompressed_file = "../tests/Test13/Test13.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(PAT_file, PAT_file_test) {
    std::string file_to_compress = "../tests/Test14/Test14.dat";
    std::string compressed = "../tests/Test14/Test14.lzw";
    std::string decompressed_file = "../tests/Test14/Test14.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(BMP_file, BMP_file_test) {
    std::string file_to_compress = "../tests/Test15/Test15.dat";
    std::string compressed = "../tests/Test15/Test15.lzw";
    std::string decompressed_file = "../tests/Test15/Test15.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(PPTX_file, PPTX_file_test) {
    std::string file_to_compress = "../tests/Test16/Test16.dat";
    std::string compressed = "../tests/Test16/Test16.lzw";
    std::string decompressed_file = "../tests/Test16/Test16.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(MSI_file, MSI_file_test) {
    std::string file_to_compress = "../tests/Test17/Test17.dat";
    std::string compressed = "../tests/Test17/Test17.lzw";
    std::string decompressed_file = "../tests/Test17/Test17.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(MSI12_file, MSI12_file_test) {
    std::string file_to_compress = "../tests/Test18/Test18.dat";
    std::string compressed = "../tests/Test18/Test18.lzw";
    std::string decompressed_file = "../tests/Test18/Test18.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(STL_file, STL_file_test) {
    std::string file_to_compress = "../tests/Test19/Test19.dat";
    std::string compressed = "../tests/Test19/Test19.lzw";
    std::string decompressed_file = "../tests/Test19/Test19.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}

TEST(GPSS_file, GPSS_file_test) {
    std::string file_to_compress = "../tests/Test20/Test20.dat";
    std::string compressed = "../tests/Test20/Test20.lzw";
    std::string decompressed_file = "../tests/Test20/Test20.ans";

    LZW lzw;
    lzw.Compress(file_to_compress, compressed);
    lzw.Decompress(compressed, decompressed_file);

    EXPECT_EQ(compare_files(file_to_compress, decompressed_file),1);
}