#ifndef OSSCZIPLIB_LIBRARY_H
#define OSSCZIPLIB_LIBRARY_H

#include <stdbool.h>
#include <zip.h>

bool oss_remove(const char* filename);

/// compress file from src to dest
void oss_compress(const char* src, const char* dest);

/// decompress file from src to dest
void oss_decompress(const char *src, const char* dest);

#endif