all:
	gcc -o liblogger.o -c logger.c
	gcc -shared -o liblogger.so liblogger.o
clean:
	rm -rf *.o *.so
