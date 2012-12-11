/* Copyright (C) 2011 Intel Corporation
   Author: Andi Kleen
   Set 2.6.x personality

   mcelog is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; version
   2.

   mcelog is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should find a copy of v2 of the GNU General Public License somewhere
   on your Linux system; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <sys/personality.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define UNAME26 0x0020000

int main(int ac, char **av)
{
	if (!av[1]) {
		fprintf(stderr, "Usage: uname26 program ...\n"
				"Run program with the uname 2.6 personality\n");
		exit(1);
	}
	if (personality(PER_LINUX | UNAME26) < 0)
		perror("personality"), exit(1);

	execvp(av[1], av + 1);
	fprintf(stderr, "Cannot execute %s: %s\n", av[1], strerror(errno));
	exit(1);
}
