DEVICE     = attiny85
CLOCK      = 8000000
PROGRAMMER = usbasp
FILENAME   = main
COMPILE    = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

.PHONY: all build upload clean

all: build upload

build:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -U flash:w:$(FILENAME).hex:i 

clean:
	rm -f main.o
	rm -f main.elf
	rm -f main.hex