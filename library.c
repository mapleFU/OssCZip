#include "library.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <zlib.h>


bool oss_remove(const char* filename) {
    if (filename == '\0') {
        return false;
    }
    // c
    if( access( filename, F_OK ) != -1 ) {
        // file exists
        remove(filename);
        return true;
    } else {
        // file doesn't exist
        return false;
    }
}

/// compress file from src to dest
void oss_decompress(const char* src, const char* dest)  {
    char buf[1024];
    gzFile *fi = (gzFile *)gzopen(src, "rb");
    gzrewind(fi);
    int dest_fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0766);
    if (dest_fd <= 0) {
        printf("error: %s", strerror(errno));
    }
    while(!gzeof(fi))
    {
        int len = gzread(fi,buf,sizeof(buf));
        //buf contains len bytes of decompressed data
        write(dest_fd, buf, len);
    }
    gzclose(fi);
    close(dest_fd);
}

/// decompress file from src to dest
void oss_compress(const char *src, const char* dest) {
    gzFile *fi = (gzFile *)gzopen(dest, "wb");
    int src_fd = open(src, O_RDONLY , 0766);
    char buf[1024];
    lseek(src_fd, SEEK_SET, 0);
    ssize_t len;
    while ((len = read(src_fd, buf, sizeof(buf)))) {
        if (len <= 0) {
            break;
        }
        gzwrite(fi, buf, len);
    }
//    gzwrite(fi,"my decompressed data", strlen("my decompressed data"));
    close(src_fd);
    gzclose(fi);
}