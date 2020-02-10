
all:

release: clean
	gcc .c -o socketpair.bin -lm
debug:
	gcc server.c -o server.bin -lpthread -l sqlite3
	gcc client.c -o client.bin -lpthread
run1:
	./server.bin
run2:
	./client.bin 127.0.0.1 2910
gdb: debug
	gdb ./socketpair.bin
clean:
	rm socketpair.bin || echo -n ''

