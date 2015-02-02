/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  queue implemented by list
 *
 *        Version:  1.0
 *        Created:  10/05/2014 15:41:48
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "../list/list.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue( Queue *queue, const void *data );
int queue_dequeue( Queue *queue, void **data );

#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data )
#define queue_size list_size

#endif
