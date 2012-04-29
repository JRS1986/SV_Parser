PERL_INC = /usr/lib/perl/5.12/CORE

#-- CCOPTS	= -D_REENTRANT -D_GNU_SOURCE -DDEBIAN -fno-strict-aliasing -pipe -fstack-protector -I/usr/local/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64  -I/usr/lib/perl/5.12/CORE  
CCOPTS	= `perl -MExtUtils::Embed -e ccopts`
#-- LDOPTS	=-Wl,-E  -fstack-protector -L/usr/local/lib  -L/usr/lib/perl/5.12/CORE -lperl -ldl -lm -lpthread -lc -lcrypt
LDOPTS	= `perl -MExtUtils::Embed -e ldopts`
OPTIMIZE = -O2 -g
USEGDB = -O0 -ggdb

OBJECT = VFileLine.o VParseLex.o VParse.o VParseBison.o VSymTable.o VAst.o
VHEADERS = VParseLex.h VParseGrammar.h VParse.h VFileLine.h VParseBison.h \
	VSymTable.h VAst.h Parser_callbackgen.cpp

XS_FILES = Parser.xs
C_FILES  = Parser.c \
	Parser_callbackgen.cpp \
	Parser_cleaned.c \
	VAst.cpp \
	VParse.cpp \
	VParseBison.cpp \
	VParseLex.cpp \
	VParseLex_pretmp.cpp \
	VSymTable.cpp
O_FILES  = Parser.o \
	Parser_callbackgen.o \
	Parser_cleaned.o \
	VAst.o \
	VParse.o \
	VParseBison.o \
	VParseLex.o \
	VParseLex_pretmp.o \
	VSymTable.o
H_FILES  = VAst.h \
	VParse.h \
	VParseBison.h \
	VParseGrammar.h \
	VParseLex.h \
	VSymTable.h
	
create_objs:
	cc -c $(CCOPTS) $(USEGDB) -fPIC "-I$(PERL_INC)" VParse.cpp
	cc -c $(CCOPTS) $(OPTIMIZE) -fPIC "-I$(PERL_INC)" VFileLineParseXs.cpp
	cc -c $(CCOPTS) $(OPTIMIZE) -fPIC "-I$(PERL_INC)" Parser_cleaned.c
	cc -c $(CCOPTS) $(OPTIMIZE) -fPIC "-I$(PERL_INC)" VParseLex.cpp
	cc -c $(CCOPTS) $(OPTIMIZE) -fPIC "-I$(PERL_INC)" VParseBison.cpp
	cc -c $(CCOPTS) $(OPTIMIZE) -fPIC "-I$(PERL_INC)" VSymTable.cpp
	cc -c $(CCOPTS) $(OPTIMIZE) -fPIC "-I$(PERL_INC)" VAst.cpp
	

VFileLine.cpp:
	cc -c $(CCOPTS) $(OPTIMIZE) -fPIC "-I$(PERL_INC)" VFileLine.cpp

VParseLex_pretmp.cpp: VParseLex.l
	-flex --version
	/usr/bin/perl ../Preproc/toolhash --verbose --in $< --out $@ --cmd flex -d -o$@ $<

VParseLex.cpp: ../Preproc/flexfix VParseLex_pretmp.cpp
	/usr/bin/perl ../Preproc/flexfix VParseLex < VParseLex_pretmp.cpp > $@
	
VParseBison.cpp:	VParseBison.y bisonpre 
	-rm -rf VParseBison.c VParseBison.cpp 
	-bison --version | head -1
	/usr/bin/perl ../Preproc/toolhash --verbose --name bisonpre --vercmd bison --skip-cmd 1 \
		--in VParseBison.y bisonpre \
		--out VParseBison.c VParseBison.h \
		--cmd /usr/bin/perl bisonpre --yacc bison --debug --verbose --d -p VParseBison -k VParseBison.y -o VParseBison.c
	mv VParseBison.c VParseBison.cpp
	
Parser_callbackgen.cpp: callbackgen
	/usr/lib/perl callbackgen
	
Parser_cleaned.c: Parser.c $(VHEADERS)
	/usr/lib/perl ../Preproc/xsubppfix < Parser.c > Parser_cleaned.c

My_Parser:
	g++ -c $(CCOPTS) $(USEGDB) My_Parser.cpp
	g++ $(CCOPTS) Main.cpp My_Parser.o VFileLine.o VFileLineParseXs.o VParse.o VParseLex.o VParseBison.o VSymTable.o VAst.o -fpermissive -o My_Parser $(LDOPTS) $(USEGDB)
