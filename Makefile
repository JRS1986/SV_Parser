#-- CCOPTS	= -D_REENTRANT -D_GNU_SOURCE -DDEBIAN -fno-strict-aliasing -pipe -fstack-protector -I/usr/local/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64  -I/usr/lib/perl/5.12/CORE  
CCOPTS	= `perl -MExtUtils::Embed -e ccopts`
#-- LDOPTS	=-Wl,-E  -fstack-protector -L/usr/local/lib  -L/usr/lib/perl/5.12/CORE -lperl -ldl -lm -lpthread -lc -lcrypt
LDOPTS	= `perl -MExtUtils::Embed -e ldopts`


all:
	g++ -c $(CCOPTS) -O0 -ggdb My_Parser.cpp
	g++ $(CCOPTS) Main.cpp My_Parser.o VFileLine.cpp VFileLineParseXs.cpp VParse.cpp Parser_cleaned.c VParseLex.cpp VParseBison.cpp VSymTable.cpp VAst.cpp -fpermissive -o My_Parser $(LDOPTS) -O0 -ggdb
