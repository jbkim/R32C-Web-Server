#ifndef _ROMFS_H_
#define _ROMFS_H_

#include "types.h"

typedef struct _ROMFILE ROMFILE;

struct _ROMFILE
{
	ROMFILE *romfs_next;	/* Link to next ROMFILE structure. */
	u_char  *romfs_name;	/* Filename */
	u_int    romfs_size;	/* File size. */
	char *romfs_data;	/* File contents. */
};

extern ROMFILE* romfs_list;


#endif /* _ROMFS_H_ */
