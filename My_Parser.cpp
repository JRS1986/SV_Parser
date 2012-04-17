#include "VParse.h"
#include "VSymTable.h"
#include "VAst.h"
#include "My_Parser.h"
#include <cstring>
#include <deque>
#include <stdio.h>
#include <iostream>
// #include <fstream>

My_Parser::~My_Parser() { }

void My_Parser::attributeCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_attribute) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "attribute", hold1.c_str());
    }*/
    std::cout << "My_Parser::attributeCb called" << std::endl; 
}

void My_Parser::commentCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_comment) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "comment", hold1.c_str());
    }*/
    std::cout << "My_Parser::commentCb called" << std::endl;
}

void My_Parser::endparseCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_endparse) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "endparse", hold1.c_str());
    }*/
    std::cout << "My_Parser::endparseCb called" << std::endl;
}

void My_Parser::keywordCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_keyword) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "keyword", hold1.c_str());
    }*/
    std::cout << "My_Parser::keywordCb called" << fl << ";" << text << std::endl;
}

void My_Parser::numberCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_number) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "number", hold1.c_str());
    }*/
    std::cout << "My_Parser::numberCb called" << fl << ";" << text << std::endl;
}

void My_Parser::operatorCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_operator) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "operator", hold1.c_str());
    }*/
    std::cout << "My_Parser::operatorCb called" << fl << ";" << text << std::endl;
}

void My_Parser::preprocCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_preproc) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "preproc", hold1.c_str());
    }*/
    std::cout << "My_Parser::preprocCb called" << fl << ";" << text << std::endl;
}

void My_Parser::stringCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_string) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "string", hold1.c_str());
    }*/
    std::cout << "My_Parser::stringCb called" << fl << ";" << text << std::endl;
}

void My_Parser::symbolCb(VFileLine* fl, const string& text) {
    /*if (callbackMasterEna() && m_useCb_symbol) {
        cbFileline(fl);
        static string hold1; hold1 = text;
        call(NULL, 1, "symbol", hold1.c_str());
    }*/
    std::cout << "My_Parser::symbolCb called" << fl << ";" << text << std::endl;
}

void My_Parser::sysfuncCb(VFileLine* fl, const string& text) {
//     if (callbackMasterEna() && m_useCb_sysfunc) {
//         cbFileline(fl);
//         static string hold1; hold1 = text;
//         call(NULL, 1, "sysfunc", hold1.c_str());
//     }
    std::cout << "My_Parser::sysfuncCb called" << std::endl;
}

void My_Parser::classCb(VFileLine* fl, const string& kwd, const string& name, const string& virt) {
//     if (callbackMasterEna() && m_useCb_class) {
//      cbFileline(fl);
        static string hold1; hold1 = kwd;
        static string hold2; hold2 = name;
        static string hold3; hold3 = virt;
//         call(NULL, 3, "class", hold1.c_str(), hold2.c_str(), hold3.c_str());
//     }
    std::cout << "My_Parser::classCb called kwd " << kwd << " name: " << name << " virt: " << virt << std::endl;
}

void My_Parser::contassignCb(VFileLine* fl, const string& kwd, const string& lhs, const string& rhs) {
//     if (callbackMasterEna() && m_useCb_contassign) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = lhs;
//         static string hold3; hold3 = rhs;
//         call(NULL, 3, "contassign", hold1.c_str(), hold2.c_str(), hold3.c_str());
//     }
    std::cout << "My_Parser::contassignCb called" << std::endl;
}

void My_Parser::covergroupCb(VFileLine* fl, const string& kwd, const string& name) {
//     if (callbackMasterEna() && m_useCb_covergroup) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = name;
//         call(NULL, 2, "covergroup", hold1.c_str(), hold2.c_str());
//     }
    std::cout << "My_Parser::covergroupCb called" << std::endl;
}

void My_Parser::defparamCb(VFileLine* fl, const string& kwd, const string& lhs, const string& rhs) {
//     if (callbackMasterEna() && m_useCb_defparam) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = lhs;
//         static string hold3; hold3 = rhs;
//         call(NULL, 3, "defparam", hold1.c_str(), hold2.c_str(), hold3.c_str());
//     }
    std::cout << "My_Parser::defparamCb called" << std::endl;
}

void My_Parser::endcellCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endcell) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endcell", hold1.c_str());
//     }
    std::cout << "My_Parser::endcellCb called" << std::endl;
}

void My_Parser::endclassCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endclass) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endclass", hold1.c_str());
//     }
    std::cout << "My_Parser::endclassCb called" << std::endl;
}

void My_Parser::endgroupCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endgroup) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endgroup", hold1.c_str());
//     }
    std::cout << "My_Parser::endgroupCb called" << std::endl;
}

void My_Parser::endinterfaceCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endinterface) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endinterface", hold1.c_str());
//     }
    std::cout << "My_Parser::endinterfaceCb called" << std::endl;
}

void My_Parser::endmodportCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endmodport) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endmodport", hold1.c_str());
//     }
    std::cout << "My_Parser::endmodportCb called" << std::endl;
}

void My_Parser::endmoduleCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endmodule) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endmodule", hold1.c_str());
//     }
    std::cout << "My_Parser::endmoduleCb called" << std::endl;
}

void My_Parser::endpackageCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endpackage) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endpackage", hold1.c_str());
//     }
    std::cout << "My_Parser::endpackageCb called" << std::endl;
}

void My_Parser::endprogramCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endprogram) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endprogram", hold1.c_str());
//     }
    std::cout << "My_Parser::endprogramCb called" << std::endl;
}

void My_Parser::endtaskfuncCb(VFileLine* fl, const string& kwd) {
//     if (callbackMasterEna() && m_useCb_endtaskfunc) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         call(NULL, 1, "endtaskfunc", hold1.c_str());
//     }
    std::cout << "My_Parser::endtaskfuncCb called" << std::endl;
}

void My_Parser::functionCb(VFileLine* fl, const string& kwd, const string& name, const string& data_type) {
//     if (callbackMasterEna() && m_useCb_function) {
//      cbFileline(fl);
        static string hold1; hold1 = kwd;
        static string hold2; hold2 = name;
        static string hold3; hold3 = data_type;
//         call(NULL, 3, "function", hold1.c_str(), hold2.c_str(), hold3.c_str());
//     }
    std::cout << "My_Parser::functionCb called, name: " << name << " data_type: " << data_type << std::endl;	
}

void My_Parser::importCb(VFileLine* fl, const string& package, const string& id) {
//     if (callbackMasterEna() && m_useCb_import) {
//         cbFileline(fl);
//         static string hold1; hold1 = package;
//         static string hold2; hold2 = id;
//         call(NULL, 2, "import", hold1.c_str(), hold2.c_str());
//     }
    std::cout << "My_Parser::importCb called" << std::endl;
}

void My_Parser::instantCb(VFileLine* fl, const string& mod, const string& cell, const string& range) {
//     if (callbackMasterEna() && m_useCb_instant) {
//         cbFileline(fl);
//         static string hold1; hold1 = mod;
//         static string hold2; hold2 = cell;
//         static string hold3; hold3 = range;
//         call(NULL, 3, "instant", hold1.c_str(), hold2.c_str(), hold3.c_str());
//     }
    std::cout << "My_Parser::instantCb called" << std::endl;
}

void My_Parser::interfaceCb(VFileLine* fl, const string& kwd, const string& name) {
//     if (callbackMasterEna() && m_useCb_interface) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = name;
//         call(NULL, 2, "interface", hold1.c_str(), hold2.c_str());
//     }
    std::cout << "My_Parser::interfaceCb called" << std::endl;
}

void My_Parser::modportCb(VFileLine* fl, const string& kwd, const string& name) {
//     if (callbackMasterEna() && m_useCb_modport) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = name;
//         call(NULL, 2, "modport", hold1.c_str(), hold2.c_str());
//     }
    std::cout << "My_Parser::modportCb called" << std::endl;
}

void My_Parser::moduleCb(VFileLine* fl, const string& kwd, const string& name, bool, bool celldefine) {
//     if (callbackMasterEna() && m_useCb_module) {
//      cbFileline(fl);
        static string hold1; hold1 = kwd;
        static string hold2; hold2 = name;
        static string hold4; hold4 = celldefine ? "1":"0";
//         call(NULL, 4, "module", hold1.c_str(), hold2.c_str(), NULL, hold4.c_str());
//     }
	std::cout << "My_Parser::moduleCb called, name: " << name << std::endl;
}

void My_Parser::packageCb(VFileLine* fl, const string& kwd, const string& name) {
//     if (callbackMasterEna() && m_useCb_package) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = name;
//         call(NULL, 2, "package", hold1.c_str(), hold2.c_str());
//     }
    std::cout << "My_Parser::packageCb called" << std::endl;
}

void My_Parser::parampinCb(VFileLine* fl, const string& name, const string& conn, int index) {
//     if (callbackMasterEna() && m_useCb_parampin) {
//         cbFileline(fl);
//         static string hold1; hold1 = name;
//         static string hold2; hold2 = conn;
//         static string hold3; static char num3[30]; sprintf(num3,"%d",index); hold3=num3;
//         call(NULL, 3, "parampin", hold1.c_str(), hold2.c_str(), hold3.c_str());
//     }
    std::cout << "My_Parser::parampinCb called" << std::endl;
}

void My_Parser::pinCb(VFileLine* fl, const string& name, const string& conn, int index) {
//     if (callbackMasterEna() && m_useCb_pin) {
//         cbFileline(fl);
//         static string hold1; hold1 = name;
//         static string hold2; hold2 = conn;
//         static string hold3; static char num3[30]; sprintf(num3,"%d",index); hold3=num3;
//         call(NULL, 3, "pin", hold1.c_str(), hold2.c_str(), hold3.c_str());
//     }
    std::cout << "My_Parser::pinCb called" << std::endl;
}

void My_Parser::portCb(VFileLine* fl, const string& name, const string& objof, const string& direction, const string& data_type
	, const string& array, int index) {
//     if (callbackMasterEna() && m_useCb_port) {
//      cbFileline(fl);
        static string hold1; hold1 = name;
        static string hold2; hold2 = objof;
        static string hold3; hold3 = direction;
        static string hold4; hold4 = data_type;
        static string hold5; hold5 = array;
        static string hold6; static char num6[30]; sprintf(num6,"%d",index); hold6=num6;
//         call(NULL, 6, "port", hold1.c_str(), hold2.c_str(), hold3.c_str(), hold4.c_str(), hold5.c_str(), hold6.c_str());
//     }
    std::cout << "My_Parser::portCb called" << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "object of: " << objof << std::endl;
    std::cout << "direction: " << direction << std::endl;
    std::cout << "data_type: " << data_type << std::endl;
}

void My_Parser::programCb(VFileLine* fl, const string& kwd, const string& name) {
//     if (callbackMasterEna() && m_useCb_program) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = name;
//         call(NULL, 2, "program", hold1.c_str(), hold2.c_str());
//     }
    std::cout << "My_Parser::programCb called" << std::endl;
}

void My_Parser::taskCb(VFileLine* fl, const string& kwd, const string& name) {
//     if (callbackMasterEna() && m_useCb_task) {
//         cbFileline(fl);
//         static string hold1; hold1 = kwd;
//         static string hold2; hold2 = name;
//         call(NULL, 2, "task", hold1.c_str(), hold2.c_str());
//     }
    std::cout << "My_Parser::taskCb called" << std::endl;
}

void My_Parser::varCb(VFileLine* fl, const string& kwd, const string& name, const string& objof, const string& net
	, const string& data_type, const string& array, const string& value) {
//     if (callbackMasterEna() && m_useCb_var) {
//      cbFileline(fl);
        static string hold1; hold1 = kwd;
        static string hold2; hold2 = name;
        static string hold3; hold3 = objof;
        static string hold4; hold4 = net;
        static string hold5; hold5 = data_type;
        static string hold6; hold6 = array;
        static string hold7; hold7 = value;
//         call(NULL, 7, "var", hold1.c_str(), hold2.c_str(), hold3.c_str(), hold4.c_str(), hold5.c_str(), hold6.c_str(), hold7.c_str());
//     }
    std::cout << "My_Parser::varCb called" << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "object of: " << objof << std::endl;
    std::cout << "net: " << net << std::endl;
    std::cout << "data_type: " << data_type << std::endl;
    std::cout << "value: " << value << std::endl;
}

