build:
	@cc src/main.c -o randomhashtags -lncurses 

install:
	@echo "copying binary into /usr/local/bin/"
	@sudo cp randomhashtags /usr/local/bin/

clean:
	@rm -rf /build

uninstall:
	@sudo rm  /usr/local/bin/randomhashtags
