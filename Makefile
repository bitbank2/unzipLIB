CFLAGS=-D__LINUX__ -Wall -O2 
LIBS = 

all: unziptest

unziptest: main.o unzip.o adler32.o crc32.o infback.o inffast.o inflate.o inftrees.o zutil.o
	$(CC) main.o unzip.o adler32.o crc32.o infback.o inffast.o inflate.o inftrees.o zutil.o $(LIBS) -o unziptest 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

unzip.o: unzip.c unzip.h
	$(CC) $(CFLAGS) -c unzip.c

adler32.o: adler32.c
	$(CC) $(CFLAGS) -c adler32.c

crc32.o: crc32.c
	$(CC) $(CFLAGS) -c crc32.c

infback.o: infback.c
	$(CC) $(CFLAGS) -c infback.c

inffast.o: inffast.c
	$(CC) $(CFLAGS) -c inffast.c

inflate.o: inflate.c
	$(CC) $(CFLAGS) -c inflate.c

inftrees.o: inftrees.c
	$(CC) $(CFLAGS) -c inftrees.c

zutil.o: zutil.c
	$(CC) $(CFLAGS) -c zutil.c

clean:
	rm -rf *.o unziptest
