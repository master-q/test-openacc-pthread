all: a.out libtestacc.so

a.out: main.c
	gcc main.c -ldl -pthread

libtestacc.so: acc.c
	/opt/pgi/linux86-64/17.10/bin/pgcc -shared -fpic -fast -acc -ta=tesla,cc60,nordc -o libtestacc.so acc.c

run: a.out
	LD_LIBRARY_PATH=./ ACC_DEVICE_TYPE=NVIDIA ACC_DEVICE_NUM=1 PGI_ACC_NOTIFY=1 ./a.out

clean:
	rm -f *.so *.o a.out

.PHONY: all run clean
