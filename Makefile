CC=egcc
CFLAGS_TESTBIN=-O3 -Wfatal-errors -Wall -Werror -Wextra -g -Wpedantic -std=c99
CFLAGS=-O3 -flto -march=native -DNDEBUG -fomit-frame-pointer -s -std=gnu99
TARGET1=s_linkedlist
TARGET2=d_linkedlist
TARGET3=cs_linkedlist
TESTTARGET1=s_linkedlist-t
TESTTARGET2=d_linkedlist-t
TESTTARGET3=cs_linkedlist-t
INSTALL_DIRECTORY=/usr/local/bin
MAKEFLAGS += -s
SRCSL=s_linkedlist.c
SRCDL=d_linkedlist.c
SRCCSL=cs_linkedlist.c

all: release
clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3)
	rm -f test/$(TESTTARGET1) test/$(TESTTARGET2) test/$(TESTTARGET3)

tests:
	
	$(CC) $(CFLAGS_TESTBIN) $(SRCSL) -o test/$(TESTTARGET1)
	$(CC) $(CFLAGS_TESTBIN) $(SRCDL) -o test/$(TESTTARGET2)
	$(CC) $(CFLAGS_TESTBIN) $(SRCCSL) -o test/$(TESTTARGET3)	
	

release:
	
	$(CC) $(CFLAGS) $(SRCSL) -o $(TARGET1)
	$(CC) $(CFLAGS) $(SRCDL) -o $(TARGET2)
	$(CC) $(CFLAGS) $(SRCCSL) -o $(TARGET3)
	
	

	
