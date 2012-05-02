/*
 * VFileLineXs.cpp
 *
 *  Created on: 30.04.2012
 *      Author: jseyler
 */

#include "VFileLineXs.h"

VFileLineXs::~VFileLineXs() {
	// TODO Auto-generated destructor stub
}

void VFileLineXs::error(const string& msg) {
    static string holdmsg; holdmsg = msg;
    m_vPreprocp->call(NULL, 1,"error",holdmsg.c_str());
}



