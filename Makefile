obj-m := workq.o
workq-objs := main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=`pwd` modules
