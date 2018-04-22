# test-openacc-gcc

```
$ make
gcc main.c -ldl
/opt/pgi/linux86-64/17.10/bin/pgcc -shared -fpic -fast -acc -ta=tesla,cc60 -o libtestacc.so acc.c
$ make run
LD_LIBRARY_PATH=./ ACC_DEVICE_TYPE=NVIDIA ACC_DEVICE_NUM=1 PGI_ACC_NOTIFY=1 ./a.out
*** acc_init called!
```
