CFLAGS=-D__LINUX__ -Wall -O2 -ggdb -I../src
LIBS = 

all: libunzipLIB.a

libunzipLIB.a: unzipLIB.o unzip.o adler32.o crc32.o infback.o inffast.o inflate.o inftrees.o zutil.o
	ar -rc libunzipLIB.a unzipLIB.o unzip.o adler32.o crc32.o infback.o inffast.o inflate.o inftrees.o zutil.o ;\
	sudo cp libunzipLIB.a /usr/local/lib ;\
	sudo cp ../src/unzipLIB.h /usr/local/include

unzipLIB.o: ../src/unzipLIB.cpp
	$(CXX) $(CFLAGS) -c ../src/unzipLIB.cpp

unzip.o: ../src/unzip.c ../src/unzip.h
	$(CC) $(CFLAGS) -c ../src/unzip.c

adler32.o: ../src/adler32.c
	$(CC) $(CFLAGS) -c ../src/adler32.c

crc32.o: ../src/crc32.c
	$(CC) $(CFLAGS) -c ../src/crc32.c

infback.o: ../src/infback.c
	$(CC) $(CFLAGS) -c ../src/infback.c

inffast.o: ../src/inffast.c
	$(CC) $(CFLAGS) -c ../src/inffast.c

inflate.o: ../src/inflate.c
	$(CC) $(CFLAGS) -c ../src/inflate.c

inftrees.o: ../src/inftrees.c
	$(CC) $(CFLAGS) -c ../src/inftrees.c

zutil.o: ../src/zutil.c
	$(CC) $(CFLAGS) -c ../src/zutil.c

clean:
	rm -rf *.o libunzipLIB.a
