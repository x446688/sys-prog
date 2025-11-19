#include <sys/ipc.h>
#include <stdio.h>
int main(){
	key_t a = ftok("tmp", 1);
	printf("Ключ IPC: %d",a);
}
