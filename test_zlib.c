//
// Created by 付旭炜 on 2019/6/24.
//
#include "library.h"

const static char* path = "/Users/fuasahi/ClionProjects/OssCZipLib/data/03的副本.png";
const static char* dest = "/Users/fuasahi/ClionProjects/OssCZipLib/data/03的副本.png.zip";
const static char* dest2 = "/Users/fuasahi/ClionProjects/OssCZipLib/data/03的副本n2.png";

int main() {
    oss_compress(path, dest);
    oss_decompress(dest, dest2);
}
