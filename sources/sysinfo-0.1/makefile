CC = gcc
TARGET = sysinfo

sysinfo:
	$(CC) -g -o $(TARGET) sysinfo.c

clean:
	rm $(TARGET)

install:
	mkdir -p $(DESTDIR)/usr/bin
	install -m 0755 $(TARGET) $(DESTDIR)/usr/bin/sysinfo