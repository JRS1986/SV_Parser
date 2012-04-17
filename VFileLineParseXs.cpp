#include "VFileLineParseXs.h"

VFileLineParseXs::~VFileLineParseXs() {

};

void VFileLineParseXs::error(const string& msg) {
	static string holdmsg; holdmsg = msg;
	//m_vParserp->cbFileline(this);
	// Call always, not just if callbacks enabled
	//m_vParserp->call(NULL, 1,"error",holdmsg.c_str());
};
