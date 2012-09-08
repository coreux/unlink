/*
 * Copyright 2012 Mo McRoberts.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
 
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_ERRNO_H
# include <errno.h>
#endif
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#ifdef HAVE_LOCALE_H
# include <locale.h>
#endif
#ifdef HAVE_NL_TYPES_H
# include <nl_types.h>
#endif

#define UNLINK_MSG_USAGE                  1

static const char *short_program_name = "unlink";

#ifndef EXIT_FAILURE
# define EXIT_FAILURE                   1
#endif

#ifdef ENABLE_NLS
static nl_catd msgcat;
#endif

#undef _
#ifdef ENABLE_NLS
# define _(i,x)                         catgets(msgcat, NL_SETD, i, x)
#else
# define _(i,x)                         (x)
#endif

static void
usage(void)
{
	fprintf(stderr, _(UNLINK_MSG_USAGE, "Usage: %s file"), short_program_name);
	fputc('\n', stderr);
}

int
main(int argc, char **argv)
{	
	int ch;
	const char *t;

#ifdef ENABLE_NLS
	setlocale(LC_ALL, "");
	msgcat = catopen("UXunlink", NL_CAT_LOCALE);
#endif
	if(argv[0])
	{
		if(NULL != (t = strrchr(argv[0], '/')))
		{
			short_program_name = t + 1;
		}
		else
		{
			short_program_name = argv[0];
		}
		argv[0] = (char *) short_program_name;
	}
	while(-1 != (ch = getopt(argc, argv, "")))
	{
		/* No options are permitted */
		usage();
		exit(EXIT_FAILURE);
	}
	if(argc - optind != 1)
	{
		usage();
		exit(EXIT_FAILURE);
	}
	if(unlink(argv[optind]))
	{
		perror(argv[optind]);
		exit(EXIT_FAILURE);
	}
#ifdef ENABLE_NLS
	if(msgcat)
	{
		catclose(msgcat);
	}
#endif
	return 0;
}
