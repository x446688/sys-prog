/*
 * Copyright (c) 1996 W. Richard Stevens.  All rights reserved.
 *
 * Permission to use or modify this software for educational or
 * for commercial purposes, and without fee, is hereby granted,
 * provided that the above copyright notice appears in connection
 * with any and all uses, with clear indication as to any
 * modifications made.  The author RESERVES the sole rights of
 * reproduction, publication and distribution and hence permission
 * to print this source code in any book, reference manual,
 * magazine, or other type of publication, including any digital
 * medium, must be granted in writing by W. Richard Stevens.
 *
 * The author makes no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 */
/*

	P. S. : Some parts of this code are rewritten based on the original files

*/

#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
int main(){
	key_t key = ftok("tmp/test.tst", 42);
	printf("Ключ IPC: %d\n",key);
	int i, msqid;
	for (i = 0; i < 10; i++) {
		msqid=msgget(key, IPC_CREAT|0666);
		printf("msqid = %d\n", msqid);
		msgctl(msqid, IPC_RMID, NULL);
	}
	exit(0);
}
