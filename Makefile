# Uncomment lines below if you have problems with $PATH
#SHELL := /bin/bash
#PATH := /usr/local/bin:$(PATH)

all:
	pio -f -c vim run

upload:
	pio -f -c vim run --target upload

clean:
	pio -f -c vim run --target clean

compiledb:
	pio -f -c vim run --target compiledb

program:
	pio -f -c vim run --target program

uploadfs:
	pio -f -c vim run --target uploadfs

update:
	pio -f -c vim update

virtual-serial:
	tmux new-window -n socat-pio \
	  "socat -d -d pty,raw,echo=0,link=/tmp/ttyS1 pty,raw,echo=0,link=/tmp/ttyS2" \;
	tmux split-window -v -p 93 -t socat-pio \
	  "sleep 1; pio device monitor --port /tmp/ttyS1 --baud 9600 --echo --filter time" \;
	tmux select-pane -U -t socat-pio
