/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 1997,2008 Oracle.  All rights reserved.
 *
 * $Id: os_mkdir.c,v 1.6 2008/01/08 20:58:44 bostic Exp $
 */

#include "db_config.h"

#include "db_int.h"

/*
 * __os_mkdir --
 *	Create a directory.
 */
int
__os_mkdir(env, name, mode)
	ENV *env;
	const char *name;
	int mode;
{
	IFileMgr *ifmp;
	int ret;

	COMPQUIET(mode, 0);

	FILE_MANAGER_CREATE(env, ifmp, ret);
	if (ret != 0)
		return (ret);

	if (IFILEMGR_MkDir(ifmp, name) == SUCCESS)
		ret = 0;
	else
		FILE_MANAGER_ERR(env, ifmp, name, "IFILEMGR_MkDir", ret);

	IFILEMGR_Release(ifmp);

	return (ret);
}
