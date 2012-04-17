#include "VParse.h"
#include "VSymTable.h"
#include "VAst.h"
#include "My_Parser.h"
#include <cstring>
#include <deque>

/* Perl */
# include <EXTERN.h>
# include <perl.h>
# include <XSUB.h>

class VFileLineParseXs : public VFileLine {
    My_Parser*	m_vParserp;		// Parser handling the errors

public:
    VFileLineParseXs(My_Parser* pp) : VFileLine(true), m_vParserp(pp) { if (pp) pushFl(); };

    virtual ~VFileLineParseXs();

    virtual VFileLine* create(const string& filename, int lineno){
    	VFileLineParseXs* filelp = new VFileLineParseXs(m_vParserp);
    	filelp->init(filename, lineno);
    	return filelp;
    };

    virtual void error(const string& msg);	// Report a error at given location

    void setParser(My_Parser* pp){
    	m_vParserp=pp;
    	pushFl(); // The very first construction used pp=NULL, as pp wasn't created yet so make it now
    };
    // Record the structure so we can delete it later
    void pushFl(){
    	m_vParserp->m_filelineps.push_back(this);
    };
};
