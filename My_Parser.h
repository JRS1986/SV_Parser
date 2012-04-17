#include "VParse.h"
#include "VSymTable.h"
#include "VAst.h"
#include <cstring>
#include <deque>
#include <stdio.h>
#include <iostream>
#include <fstream>

class VFileLineParseXs;

class My_Parser : public VParse {
public:
  VFileLine*	m_cbFilelinep;
   deque<VFileLineParseXs*> m_filelineps;
  
  VFileLine* cbFilelinep() const { return m_cbFilelinep; }
    //void cbFileline(VFileLine* filelinep) { m_cbFilelinep = filelinep; }
  
    My_Parser(VFileLine* filelinep, av* symsp, bool sigparser, bool useUnreadback)
	: VParse(filelinep, symsp, sigparser, useUnreadback)
	, m_cbFilelinep(filelinep)
	{ /*set_cb_use();*/ }
    My_Parser(const My_Parser &mp);
    virtual ~My_Parser();
    
    void attributeCb(VFileLine* fl, const string& text);
    void commentCb(VFileLine* fl, const string& text);
    void endparseCb(VFileLine* fl, const string& text);
    void keywordCb(VFileLine* fl, const string& text);
    void numberCb(VFileLine* fl, const string& text);
    void operatorCb(VFileLine* fl, const string& text);
    void preprocCb(VFileLine* fl, const string& text);
    void stringCb(VFileLine* fl, const string& text);
    void symbolCb(VFileLine* fl, const string& text);
    void sysfuncCb(VFileLine* fl, const string& text);
    // Verilog::SigParser Callback methods
    void classCb(VFileLine* fl, const string& kwd, const string& name, const string& virt);
    void contassignCb(VFileLine* fl, const string& kwd, const string& lhs, const string& rhs);
    void covergroupCb(VFileLine* fl, const string& kwd, const string& name);
    void defparamCb(VFileLine* fl, const string& kwd, const string& lhs, const string& rhs);
    void endcellCb(VFileLine* fl, const string& kwd);
    void endclassCb(VFileLine* fl, const string& kwd);
    void endgroupCb(VFileLine* fl, const string& kwd);
    void endinterfaceCb(VFileLine* fl, const string& kwd);
    void endmodportCb(VFileLine* fl, const string& kwd);
    void endmoduleCb(VFileLine* fl, const string& kwd);
    void endpackageCb(VFileLine* fl, const string& kwd);
    void endprogramCb(VFileLine* fl, const string& kwd);
    void endtaskfuncCb(VFileLine* fl, const string& kwd);
    void functionCb(VFileLine* fl, const string& kwd, const string& name, const string& data_type);
    void importCb(VFileLine* fl, const string& package, const string& id);
    void instantCb(VFileLine* fl, const string& mod, const string& cell, const string& range);
    void interfaceCb(VFileLine* fl, const string& kwd, const string& name);
    void modportCb(VFileLine* fl, const string& kwd, const string& name);
    void moduleCb(VFileLine* fl, const string& kwd, const string& name, bool, bool celldefine);
    void packageCb(VFileLine* fl, const string& kwd, const string& name);
    void parampinCb(VFileLine* fl, const string& name, const string& conn, int index);
    void pinCb(VFileLine* fl, const string& name, const string& conn, int index);
    void portCb(VFileLine* fl, const string& name, const string& objof, const string& direction, const string& data_type
    , const string& array, int index);
    void programCb(VFileLine* fl, const string& kwd, const string& name);
    void taskCb(VFileLine* fl, const string& kwd, const string& name);
    void varCb(VFileLine* fl, const string& kwd, const string& name, const string& objof, const string& net
    , const string& data_type, const string& array, const string& value);
    
};
