/*
 * VFileLineXs.h
 *
 *  Created on: 30.04.2012
 *      Author: jseyler
 */

#ifndef VFILELINEXS_H_
#define VFILELINEXS_H_
#include "VFileLine.h"
#include "My_PreProc.h"

class VFileLineXs : public VFileLine {
    My_PreProc*	m_vPreprocp;		// Parser handling the errors
public:
    VFileLineXs(My_PreProc* pp) : VFileLine(true), m_vPreprocp(pp) { if (pp) pushFl(); }
    virtual ~VFileLineXs() { }
    virtual VFileLine* create(const string& filename, int lineno) {
	VFileLineXs* filelp = new VFileLineXs(m_vPreprocp);
	filelp->init(filename, lineno);
	return filelp;
    }
    virtual void error(const string& msg);	// Report a error at given location
    void setPreproc(My_PreProc* pp) {
	m_vPreprocp=pp;
	pushFl(); // The very first construction used pp=NULL, as pp wasn't created yet so make it now
    }
    // Record the structure so we can delete it later
    void pushFl() { m_vPreprocp->m_filelineps.push_back(this); }
};

#endif /* VFILELINEXS_H_ */
