SOURCES = $(wildcard *.md)
EXECS = $(SOURCES:.md=.pdf)

default:all

all: $(EXECS)

%.pdf: %.md
	pandoc -f markdown -V geometry:margin=0.5in $< -o $@

clean:
	rm $(EXECS)
