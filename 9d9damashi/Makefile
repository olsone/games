XDT99=/cygdrive/c/ti99/xdt99

ASM=$(XDT99)/xas99.py
DM=$(XDT99)/xdm99.py
CP=cp -p

all: k2

SRCS= \
    9d9damashi.a99 \
    hoonos.a99 \
    k2.a99 \
    kscan.a99 \
    magellan.a99 \
    maze.a99 \
    music.a99 \
    sprites.a99 \
	title.a99 \
    fugue.a99 \
    coda.a99 \

MAIN=k2.a99
LIST=k2.lst
DISK=k2.dsk

k2: k2.obj $(DISK)
	$(CP)  $< $@
	$(DM)  -a $@ -f df80 $(DISK)

k2.obj: $(SRCS)
	$(ASM) $(MAIN) -R -L $(LIST)

$(DISK):
	$(DM)  --initialize 360 $(DISK)

