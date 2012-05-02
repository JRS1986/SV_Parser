/*
 * My_PreProc.cpp
 *
 *  Created on: 30.04.2012
 *      Author: jseyler
 */
#include "My_PreProc.h"

My_PreProc::~My_PreProc() {
    for (deque<VFileLineXs*>::iterator it=m_filelineps.begin(); it!=m_filelineps.end(); ++it) {
	delete *it;
    }
}

#//**********************************************************************
#// Overrides of virtual functions to invoke callbacks

void My_PreProc::comment(string cmt) {
    static string holdcmt; holdcmt = cmt;
    call(NULL, 1,"comment",holdcmt.c_str());
}
void My_PreProc::include(string filename) {
    static string holdfilename; holdfilename = filename;
    call(NULL, 1,"include",holdfilename.c_str());
}
void My_PreProc::undef(string define) {
    static string holddefine; holddefine = define;
    call(NULL, 1,"undef", holddefine.c_str());
}
void My_PreProc::undefineall() {
    call(NULL, 0,"undefineall");
}
void My_PreProc::define(string define, string value, string params) {
    static string holddefine; holddefine = define;
    static string holdvalue; holdvalue = value;
    static string holdparams; holdparams = params;
    // 4th argument is cmdline; always undef from here
    call(NULL, 3,"define", holddefine.c_str(), holdvalue.c_str(), holdparams.c_str());
}
bool My_PreProc::defExists(string define) {
    return defParams(define)!="";
}
string My_PreProc::defParams(string define) {
    static string holddefine; holddefine = define;
    string paramStr;
    call(&paramStr, 1,"def_params", holddefine.c_str());
    return paramStr;
}
string My_PreProc::defValue(string define) {
    static string holddefine; holddefine = define;
    string valueStr;
    call(&valueStr, 1,"def_value", holddefine.c_str());
    return valueStr;
}
string My_PreProc::defSubstitute(string subs) {
    static string holdsubs; holdsubs = subs;
    string outStr;
    call(&outStr, 1, "def_substitute", holdsubs.c_str());
    return outStr;
}

void My_PreProc::call (
    string* rtnStrp,	/* If non-null, load return value here */
    int params,		/* Number of parameters.  Negative frees the parameters */
    const char* method,	/* Name of method to call */
    ...)		/* Arguments to pass to method's @_ */
{
    // Call $perlself->method (passedparam1, parsedparam2)
    va_list ap;
    va_start(ap, method);
    {
	dSP;				/* Initialize stack pointer */
	ENTER;				/* everything created after here */
	SAVETMPS;			/* ...is a temporary variable. */
	PUSHMARK(SP);			/* remember the stack pointer */
	SV* selfsv = newRV_inc(m_self);	/* $self-> */
	XPUSHs(sv_2mortal(selfsv));

	while (params--) {
	    char* text = va_arg(ap, char *);
	    SV* sv;
	    if (text) {
		sv = sv_2mortal(newSVpv (text, 0));
	    } else {
		sv = &PL_sv_undef;
	    }
	    XPUSHs(sv);			/* token */
	}

	PUTBACK;			/* make local stack pointer global */

	if (rtnStrp) {
	    int rtnCount = perl_call_method ((char*)method, G_SCALAR);
	    SPAGAIN;			/* refresh stack pointer */
	    if (rtnCount > 0) {
		SV* sv = POPs;
		//printf("RTN %ld %d %s\n", SvTYPE(sv),SvTRUE(sv),SvPV_nolen(sv));
#ifdef SvPV_nolen	// Perl 5.6 and later
		*rtnStrp = SvPV_nolen(sv);
#else
		*rtnStrp = SvPV(sv,PL_na);
#endif
	    }
	    PUTBACK;
	} else {
	    perl_call_method ((char*)method, G_DISCARD | G_VOID);
	}

	FREETMPS;			/* free that return value */
	LEAVE;				/* ...and the XPUSHed "mortal" args.*/
    }
    va_end(ap);
}


