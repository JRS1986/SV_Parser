//#include "My_Parser.h"
#include "VFileLineParseXs.h"
#include "My_PreProc.h"

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
  
  ifstream dut ("files/htoc_item_t.sv");
  if (dut.is_open()) {
    std::cout << "htoc_item_t.sv opened correctly" << std::endl;
  } else {
    std::cout << "error while opening htoc_item_t.sv" << std::endl; return 0;
  }
    
  ifstream scoreboard ("files/htax_bridge_scoreboard.sv");
  if (scoreboard.is_open()) {
    std::cout << "htax_bridge_scoreboard.sv opened correctly" << std::endl;
  } else {
    std::cout << "error while opening htax_bridge_scoreboard.sv" << std::endl; return 0;
  }
  
   filelinep->create("files/htoc_item_t.sv", 0);

   std::cout << "filelinep created" << std::endl;

   My_Parser *parser = new My_Parser(filelinep, symsp, 1, 0);
   parser->set_cb_use();

   My_PreProc *preproc = new My_PreProc();

   filelinep->setParser(parser);

   std::cout << "htoc_item_t.sv start parsing" << std::endl;

   while(!dut.eof()){
	   dut.getline(fileline, 4096);
	   parser->VParse::parse(fileline);
   }
  
   //parser->VParse::setEof();

   std::cout << "htoc_item_t.sv in buffer" << std::endl;
   dut.close();

   //-- parsing des Scoreboards
   filelinep->create("files/htax_bridge_scoreboard.sv", 0);

      std::cout << "filelinep created" << std::endl;

      filelinep->setParser(parser);

      std::cout << "htax_bridge_scoreboard.sv start parsing" << std::endl;

      while(!scoreboard.eof()){
    	  scoreboard.getline(fileline, 8182);
   	   parser->VParse::parse(fileline);
      }

      parser->VParse::setEof();

      std::cout << "htax_bridge_scoreboard.sv parsed" << std::endl;
      scoreboard.close();

  //-- Perl stuff ----------------------------------------
  perl_destruct(my_perl);
  perl_free(my_perl);
  PERL_SYS_TERM();
  //------------------------------------------------------
}

