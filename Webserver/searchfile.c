/**
 @file		searchfile.c
*/

#include <string.h>

#include "types.h"
#include "w5100.h"
#include "romfs.h"

#include "searchfile.h"

extern ROMFILE* romfl_list;


/**
 @brief 	Search a file from ROM FILE 
 */
u_char search_file(
	u_char * name, 		/**< file name */
	char ** buf, 		/**< file contents to be return */
	u_int * len			/**< file length to be return */
	) 
{
	int i;
    	ROMFILE *romfs;
    
	i = 0;

    	for (romfs = romfs_list; romfs; romfs = romfs->romfs_next)
    	{
		if (!strcmp(name, romfs->romfs_name))
		{
			*len = romfs->romfs_size;
			*buf = romfs->romfs_data;
			return ++i;
		}
	}

	return 0;
}
