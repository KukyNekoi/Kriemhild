# build helloworld executable when user executes "make"
connector: connector.o
	$(CC) $(LDFLAGS) connector.o -o connector -lssh
# CC is for the gcc compiler and LDFLAGS is for arguments

connector.o: connector.c
	$(CC) $(CFLAGS) -c connector.c

# remove object files and executable when user executes "make clean"
clean:
	rm *.o connector
