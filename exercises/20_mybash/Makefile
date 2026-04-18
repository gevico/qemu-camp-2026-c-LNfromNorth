# =============================================
# 主 Makefile
# =============================================

PWD := $(shell pwd)
SUBDIRS := mysed myfile mywc mytrans

all: mybash

$(SUBDIRS):
	@mkdir -p obj/$@
	$(MAKE) -C src/$@ OBJDIR=$(PWD)/obj/$@

mybash: $(SUBDIRS)
	@mkdir -p obj/mybash bin
	$(MAKE) -C src/mybash OBJDIR=$(PWD)/obj/mybash BINDIR=$(PWD)/bin
	gcc -o $(PWD)/bin/mybash_pie -pie -fPIE $(PWD)/obj/mybash/main.o -L$(PWD)/obj/mysed -lmysed -L$(PWD)/obj/mywc -lmywc -L$(PWD)/obj/mytrans -lmytrans -L$(PWD)/obj/myfile -lmyfile || true
	ln -sfn bin/mybash $(PWD)/20_mybash

clean:
	@for dir in $(SUBDIRS) mybash; do \
		if [ -f src/$$dir/Makefile ]; then \
			$(MAKE) -C src/$$dir clean OBJDIR=$(PWD)/obj/$$dir BINDIR=$(PWD)/bin; \
		fi \
	done
	rm -rf obj bin 20_mybash
.PHONY: all $(SUBDIRS) mybash clean
