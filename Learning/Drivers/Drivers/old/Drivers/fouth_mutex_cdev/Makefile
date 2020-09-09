obj-m := fouth_mutex_cdev.o

all: user
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean: user_clean
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


user:
	make -C `pwd`/user_space all

user_clean:
	make -C `pwd`/user_space clean
