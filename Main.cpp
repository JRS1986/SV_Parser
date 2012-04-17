//#include "My_Parser.h"
#include "VFileLineParseXs.h"

	// ---------------------------Perl stuff---------------------------------------------
	static PerlInterpreter *my_perl;
	//-----------------------------------------------------------------------------------

// Entry Point
int main(int argc, char **argv, char **env) {
	//-- Perl stuff --------------------------------------
	char *embedding[] = { "", "-e", "0" };

	PERL_SYS_INIT3(&argc,&argv,&env);
	my_perl = perl_alloc();
	perl_construct(my_perl);

	perl_parse(my_perl, NULL, 3, embedding, NULL);
	PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
	perl_run(my_perl);
	std::cout << "Perl init done" << std::endl;
	//-----------------------------------------------------

  VFileLineParseXs* filelinep = new VFileLineParseXs(NULL);
  AV* symsp;
  char fileline[4096];
  std::cout << "init done" << std::endl;

  symsp = newAV();
  //XS(Verilog_parse){
  //symsp = (AV*)SvRV(ST(2));
  //};
  // open file
  
  ifstream dut ("files/dut.sv");
  if (dut.is_open()) {
    std::cout << "dut.sv opened correctly" << std::endl;
  } else {
    std::cout << "error while opening dut.sv" << std::endl; return 0;
  }
    
  ifstream scoreboard ("files/htax_bridge_scoreboard.sv");
  if (scoreboard.is_open()) {
    std::cout << "htax_bridge_scoreboard.sv opened correctly" << std::endl;
  } else {
    std::cout << "error while opening htax_bridge_scoreboard.sv" << std::endl; return 0;
  }
  
   filelinep->create("files/dut.sv", 0);

   std::cout << "filelinep created" << std::endl;

   My_Parser *parser = new My_Parser(filelinep, symsp, 0, 0);

   filelinep->setParser(parser);
   dut.getline(fileline, 4096);

   while(!dut.eof()){
	   parser->VParse::parse(fileline);
   }
  
  dut.close();
  scoreboard.close();

  //-- Perl stuff ----------------------------------------
  perl_destruct(my_perl);
  perl_free(my_perl);
  PERL_SYS_TERM();
  //------------------------------------------------------
}

