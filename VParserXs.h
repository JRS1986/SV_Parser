#include "VParse.h"
#include "VSymTable.h"
#include "VAst.h"
#include <cstring>
#include <deque>

# include <EXTERN.h>
# include <perl.h>
# include <XSUB.h>

class VParserXs : public VParse {
public:
    SV*		m_self;	// Class called from (the hash, not SV pointing to the hash)
    VFileLine*	m_cbFilelinep;	///< Last callback's starting point
    deque<VFileLineParseXs*> m_filelineps;

    // CALLBACKGEN_H_MEMBERS
    // CALLBACKGEN_GENERATED_BEGIN - GENERATED AUTOMATICALLY by callbackgen
    struct {  // Bit packed to help the cache
        bool m_useCb_attribute:1;
        bool m_useCb_class:1;
        bool m_useCb_comment:1;
        bool m_useCb_contassign:1;
        bool m_useCb_covergroup:1;
        bool m_useCb_defparam:1;
        bool m_useCb_endcell:1;
        bool m_useCb_endclass:1;
        bool m_useCb_endgroup:1;
        bool m_useCb_endinterface:1;
        bool m_useCb_endmodport:1;
        bool m_useCb_endmodule:1;
        bool m_useCb_endpackage:1;
        bool m_useCb_endparse:1;
        bool m_useCb_endprogram:1;
        bool m_useCb_endtaskfunc:1;
        bool m_useCb_function:1;
        bool m_useCb_import:1;
        bool m_useCb_instant:1;
        bool m_useCb_interface:1;
        bool m_useCb_keyword:1;
        bool m_useCb_modport:1;
        bool m_useCb_module:1;
        bool m_useCb_number:1;
        bool m_useCb_operator:1;
        bool m_useCb_package:1;
        bool m_useCb_parampin:1;
        bool m_useCb_pin:1;
        bool m_useCb_port:1;
        bool m_useCb_preproc:1;
        bool m_useCb_program:1;
        bool m_useCb_string:1;
        bool m_useCb_symbol:1;
        bool m_useCb_sysfunc:1;
        bool m_useCb_task:1;
        bool m_useCb_var:1;
    };
    // CALLBACKGEN_GENERATED_END - GENERATED AUTOMATICALLY by callbackgen

    VFileLine* cbFilelinep() const { return m_cbFilelinep; }
    void cbFileline(VFileLine* filelinep) { m_cbFilelinep = filelinep; }

    VParserXs(VFileLine* filelinep, av* symsp, bool sigparser, bool useUnreadback)
	: VParse(filelinep, symsp, sigparser, useUnreadback)
	, m_cbFilelinep(filelinep)
	{ set_cb_use(); }
    virtual ~VParserXs();

    // CALLBACKGEN_CB_USE
    // CALLBACKGEN_GENERATED_BEGIN - GENERATED AUTOMATICALLY by callbackgen
    void set_cb_use() {
       m_useCb_attribute = true;
       m_useCb_class = true;
       m_useCb_comment = true;
       m_useCb_contassign = true;
       m_useCb_covergroup = true;
       m_useCb_defparam = true;
       m_useCb_endcell = true;
       m_useCb_endclass = true;
       m_useCb_endgroup = true;
       m_useCb_endinterface = true;
       m_useCb_endmodport = true;
       m_useCb_endmodule = true;
       m_useCb_endpackage = true;
       m_useCb_endparse = true;
       m_useCb_endprogram = true;
       m_useCb_endtaskfunc = true;
       m_useCb_function = true;
       m_useCb_import = true;
       m_useCb_instant = true;
       m_useCb_interface = true;
       m_useCb_keyword = true;
       m_useCb_modport = true;
       m_useCb_module = true;
       m_useCb_number = true;
       m_useCb_operator = true;
       m_useCb_package = true;
       m_useCb_parampin = true;
       m_useCb_pin = true;
       m_useCb_port = true;
       m_useCb_preproc = true;
       m_useCb_program = true;
       m_useCb_string = true;
       m_useCb_symbol = true;
       m_useCb_sysfunc = true;
       m_useCb_task = true;
       m_useCb_var = true;
   }
    // CALLBACKGEN_GENERATED_END - GENERATED AUTOMATICALLY by callbackgen
    // CALLBACKGEN_H_VIRTUAL
    // CALLBACKGEN_GENERATED_BEGIN - GENERATED AUTOMATICALLY by callbackgen
    // Verilog::Parser Callback methods
    virtual void attributeCb(VFileLine* fl, const string& text);
    virtual void commentCb(VFileLine* fl, const string& text);
    virtual void endparseCb(VFileLine* fl, const string& text);
    virtual void keywordCb(VFileLine* fl, const string& text);
    virtual void numberCb(VFileLine* fl, const string& text);
    virtual void operatorCb(VFileLine* fl, const string& text);
    virtual void preprocCb(VFileLine* fl, const string& text);
    virtual void stringCb(VFileLine* fl, const string& text);
    virtual void symbolCb(VFileLine* fl, const string& text);
    virtual void sysfuncCb(VFileLine* fl, const string& text);
    // Verilog::SigParser Callback methods
    virtual void classCb(VFileLine* fl, const string& kwd, const string& name, const string& virt);
    virtual void contassignCb(VFileLine* fl, const string& kwd, const string& lhs, const string& rhs);
    virtual void covergroupCb(VFileLine* fl, const string& kwd, const string& name);
    virtual void defparamCb(VFileLine* fl, const string& kwd, const string& lhs, const string& rhs);
    virtual void endcellCb(VFileLine* fl, const string& kwd);
    virtual void endclassCb(VFileLine* fl, const string& kwd);
    virtual void endgroupCb(VFileLine* fl, const string& kwd);
    virtual void endinterfaceCb(VFileLine* fl, const string& kwd);
    virtual void endmodportCb(VFileLine* fl, const string& kwd);
    virtual void endmoduleCb(VFileLine* fl, const string& kwd);
    virtual void endpackageCb(VFileLine* fl, const string& kwd);
    virtual void endprogramCb(VFileLine* fl, const string& kwd);
    virtual void endtaskfuncCb(VFileLine* fl, const string& kwd);
    virtual void functionCb(VFileLine* fl, const string& kwd, const string& name, const string& data_type);
    virtual void importCb(VFileLine* fl, const string& package, const string& id);
    virtual void instantCb(VFileLine* fl, const string& mod, const string& cell, const string& range);
    virtual void interfaceCb(VFileLine* fl, const string& kwd, const string& name);
    virtual void modportCb(VFileLine* fl, const string& kwd, const string& name);
    virtual void moduleCb(VFileLine* fl, const string& kwd, const string& name, bool, bool celldefine);
    virtual void packageCb(VFileLine* fl, const string& kwd, const string& name);
    virtual void parampinCb(VFileLine* fl, const string& name, const string& conn, int index);
    virtual void pinCb(VFileLine* fl, const string& name, const string& conn, int index);
    virtual void portCb(VFileLine* fl, const string& name, const string& objof, const string& direction, const string& data_type
	, const string& array, int index);
    virtual void programCb(VFileLine* fl, const string& kwd, const string& name);
    virtual void taskCb(VFileLine* fl, const string& kwd, const string& name);
    virtual void varCb(VFileLine* fl, const string& kwd, const string& name, const string& objof, const string& net
	, const string& data_type, const string& array, const string& value);
    // CALLBACKGEN_GENERATED_END - GENERATED AUTOMATICALLY by callbackgen

    void useCbEna(const char* name, bool flag);
    void call(string* rtnStrp, int params, const char* method, ...);
};
