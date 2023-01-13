cmake_minimum_required(VERSION 3.5)

idf_component_register(SRCS src/adler32.c src/crc32.c src/inflate.c src/unzip.c
                            src/infback.c src/zutil.c src/inftrees.c src/inffast.c
                       INCLUDE_DIRS "src")

project(unzipLIB)
