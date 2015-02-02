/*
 * ====================================================================================
 *
 *       Filename:  directls.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/2014 15:27:10
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#include "directls.h"
#include "sort.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int compare_dir( const void *key1, const void *key2)
{
	int retval;

	if( (retval = strcmp(((const Directory *)key1)->name, ((const Directory *)key2)->name)) > 0 )
		return 1;
	else if( retval < 0 )
		return -1;
	else 
		return 0;
}

int directls(const char *path, Directory **dir )
{
	DIR 	*dirptr;
	Directory  *temp;
	struct dirent 	*curdir;
	int count, i;

	if((dirptr = opendir(path) ) == NULL )
		return -1;

	*dir = NULL;
	count = 0;

	while((curdir = readdir(dirptr)) != NULL )
	{
		count++;
	
		if((temp = (Directory *)realloc(*dir, count *sizeof(Directory))) == NULL )
		{
			free(*dir);
			return -1;
		}
		else
		{
			*dir = temp;
		}
		
		printf("the name is %s\n", curdir->d_name);
		strcpy(((*dir)[count-1]).name, curdir->d_name );
	}
	closedir(dirptr);

	if( qksort(*dir, count, sizeof(Directory), 0, count -1, compare_dir) != 0 )
		return -1;

	return count;
}

int main()
{
	Directory **dir;
	int count = directls("/Users/liulu/Code/", dir );

	printf("the count is %d\n", count );
	/* for( int i =0; i<count; i++ ) */
	/* { */
		/* printf("the directory name is %s\n", (*dir)[i].name); */
	/* } */

	free(*dir);
	dir = NULL; 
	return 0;
}
