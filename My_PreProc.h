/*
 * My_PreProc.h
 *
 *  Created on: 30.04.2012
 *      Author: jseyler
 */

#ifndef MY_PREPROC_H_
#define MY_PREPROC_H_
#include "VPreProc.h"
#include "VFileLine.h"
#include <deque>

# include <EXTERN.h>
# include <perl.h>
# include <XSUB.h>


class VFileLineXs;

class My_PreProc : public VPreProc{
public:
    SV*		m_self;	// Class called from (the hash, not SV pointing to the hash)
    deque<VFileLineXs*> m_filelineps;

    My_PreProc() : VPreProc() {}
    virtual ~My_PreProc();

    // Callback methods
    virtual void comment(string filename);	// Comment for keepComments=>sub
    virtual void include(string filename);	// Request a include file be processed
    virtual void define(string name, string value, string params); // `define with parameters
    virtual void undef(string name);		// Remove a definition
    virtual void undefineall();			// Remove all non-command-line definitions
    virtual bool defExists(string name);	// Return true if define exists
    virtual string defParams(string name);	// Return parameter list if define exists
    virtual string defValue(string name);	// Return value of given define (should exist)
    virtual string defSubstitute(string substitute);	// Return value to substitute for given post-parameter value

    void call(string* rtnStrp, int params, const char* method, ...);
    void unreadback(char* text);
};


#endif /* MY_PREPROC_H_ */
