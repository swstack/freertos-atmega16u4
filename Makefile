PORT=/dev/tty.usb*
MCU=atmega32u4
CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) -Os -std=c99 -I./src/ -I./src/hal/ -I./src/FreeRTOS/include/
LDFLAGS=-Wl,-gc-sections -Wl,-relax
CC=avr-gcc
TARGET=main
SOURCES=$(wildcard src/*.c src/hal/*.c src/FreeRTOS/*.c)
OBJECT_FILES=$(patsubst %.c, %.o, $(SOURCES))

all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	avr-objcopy -R .eeprom -O ihex $< $@

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	avrdude -p $(MCU) -c avr109 -P $(PORT) -U flash:w:$(TARGET).hex
