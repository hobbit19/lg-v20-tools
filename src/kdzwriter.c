/* **********************************************************************
* Copyright (C) 2017 Elliott Mitchell					*
*									*
*	This program is free software: you can redistribute it and/or	*
*	modify it under the terms of the GNU General Public License as	*
*	published by the Free Software Foundation, either version 3 of	*
*	the License, or (at your option) any later version.		*
*									*
*	This program is distributed in the hope that it will be useful,	*
*	but WITHOUT ANY WARRANTY; without even the implied warranty of	*
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	*
*	GNU General Public License for more details.			*
*									*
*	You should have received a copy of the GNU General Public	*
*	License along with this program.  If not, see			*
*	<http://www.gnu.org/licenses/>.					*
*************************************************************************
*$Id$		*
************************************************************************/


#include <stdio.h>

#include "kdz.h"
#include "md5.h"


int main(int argc, char **argv)
{
	struct kdz_file *kdz;
	int ret=0;

	if(argc!=2) {
		fprintf(stderr, "%s <KDZ file>\n", argv[0]);
		return 1;
	}

/*

-v verbose
-q quiet

-t test
-b write bootloader
-B set blocksize
-s write system

*/

	md5_start();

	if(!(kdz=open_kdzfile(argv[1]))) {
		fprintf(stderr, "Failed to open KDZ file \"%s\", abortting\n", argv[1]);
		ret=1;
		goto abort;
	}


abort:
	if(kdz) close_kdzfile(kdz);

	md5_stop();

	return ret;
}
