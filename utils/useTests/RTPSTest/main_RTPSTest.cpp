﻿/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastCdr is licensed to you under the terms described in the
 * fastrtps_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/



#include <stdio.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <cstdint>
#include <sstream>

#include "fastrtps/utils/RTPSLog.h"
#include "fastrtps/rtps/RTPSDomain.h"

#include "TestWriter.h"
#include "TestReader.h"

using namespace eprosima;
using namespace fastrtps;
using namespace rtps;
using namespace std;


int main(int argc, char** argv){
	Log::setVerbosity(VERB_ERROR);

	logUser("Starting");
	int type;
	if(argc > 1)
	{
		if(strcmp(argv[1],"writer")==0)
			type = 1;
		else if(strcmp(argv[1],"reader")==0)
			type = 2;
		else
		{
			cout << "NEEDS writer OR reader as first argument"<<endl;
			return 0;
		}
	}
	else
	{
		cout << "NEEDS writer OR reader ARGUMENT"<<endl;
		cout << "RTPSTest writer"<<endl;
		cout << "RTPSTest reader" <<endl;
		return 0;
	}
	switch (type)
	{
	case 1:
	{
		TestWriter TW;
		if(TW.init())
			TW.run();
		break;
	}
	case 2:
	{
		TestReader TR;
		if(TR.init())
			TR.run();
		break;
	}
	}

	RTPSDomain::stopAll();
	cout << "EVERYTHING STOPPED FINE"<<endl;

	return 0;
}



