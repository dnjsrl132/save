#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h> 

#define BUF_SIZE 100
#define MAX_CLNT 256
#define NAME_SIZE 20

unsigned WINAPI HandleClnt(void* arg);
void SendMsg(char* msg, int len);
void ErrorHandling(char* msg);

int clntCnt = 0;
SOCKET clntSocks[MAX_CLNT];
HANDLE hMutex;
char list[10][NAME_SIZE];
char tempMsg[BUF_SIZE];
char Failmsg[NAME_SIZE] = "fail\n";
char Reqmsg[NAME_SIZE] = "Req\n";
int listLen,strLen;
int conect[10] = { 0, }, conect_num = 1;

int main(int argc, char* argv[]) {

	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSz;
	HANDLE  hThread;
	char tempname[20],select[20],msg[BUF_SIZE];
	
	int i, j=0, k;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hMutex = CreateMutex(NULL, FALSE, NULL);
	hServSock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi("31254"));

	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");
	if (listen(hServSock, 10) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	while (1){
		clntAdrSz = sizeof(clntAdr);
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSz);

		WaitForSingleObject(hMutex, INFINITE);
		clntSocks[clntCnt] = hClntSock;
		ReleaseMutex(hMutex);

		while (1) {
			recv(hClntSock, tempname, sizeof(tempname), 0);
			for (i = 0; i < 10; i++) {
				if (!strcmp(tempname, list[i])) break;
			}
			if (i == 10) break;
			send(hClntSock, Failmsg, strlen(Failmsg), 0);
		}
		send(hClntSock, tempname, strlen(tempname), 0);

		strcpy(list[clntCnt], tempname);
		
		for (j = 0; j < NAME_SIZE; j++) {
			if (list[clntCnt][j] == '\n') break;
		}
		list[clntCnt][j+1] = '\0';

		printf("Connected client IP: %s, clinet name : %s \n", inet_ntoa(clntAdr.sin_addr), list[clntCnt]);

		listLen++;
		clntCnt++;
		
		hThread =
			(HANDLE)_beginthreadex(NULL, 0, HandleClnt, (void*)&hClntSock, 0, NULL);
	}
	closesocket(hServSock);
	WSACleanup();
	return 0;
}

unsigned WINAPI HandleClnt(void* arg) {
	SOCKET hClntSock = *((SOCKET*)arg);
	int strLen = 0, i,j;
	int temp=0;
	char msg[BUF_SIZE];

	for (j = 0; j < 10; j++) {
		if (hClntSock == clntSocks[j]) {
			temp = j;
			break;
		}
	}
	while ((strLen = recv(hClntSock, msg, BUF_SIZE, 0)) != 0) {
			if (!strcmp(msg, "!l\n") || !strcmp(msg, "!L\n")) {
				for (i = 0; i <= 10; i++) {
					if (clntSocks[i]) continue;
					if (i == temp) continue;
					send(hClntSock, list[i], sizeof(list[i]), 0);
					fputs(list[i], stdout);
				}
				send(hClntSock, Failmsg, sizeof(Failmsg), 0);
				fputs(Failmsg, stdout);
			}
			
			else if (!strcmp(msg, "!R\n") || !strcmp(msg, "!r\n")) {
				while ((strLen = recv(hClntSock, msg, sizeof(msg), 0)) != 0) {
					for (i = 0; i < 10; i++) {
						if (!strcmp(msg, list[i])) {
							fputs(Reqmsg, stdout);
							break;
						}
					}
					if (i < 10) {
						break;
					}
					send(hClntSock, Failmsg, sizeof(Failmsg), 0);
					fputs(Failmsg, stdout);
				}
				send(hClntSock, list[i], sizeof(list[i]), 0);
				send(clntSocks[i], Reqmsg, sizeof(Reqmsg), 0);
				send(clntSocks[i], list[i], sizeof(list[i]), 0);
				recv(clntSocks[i], msg, sizeof(msg), 0);
				if (!strcmp(msg, "!N\n") || !strcmp(msg, "!n\n")) {
					send(hClntSock, Failmsg, sizeof(Failmsg), 0);
				}
				else {
					send(hClntSock, list[i], sizeof(list[i]), 0);
					conect[i] = conect[temp] = conect_num++;
				}
			}
			else if (!strcmp(msg, "!E\n") || !strcmp(msg, "!e\n")) {
				for (i = 0; i < 10; i++) {
					if (conect[temp] == conect[i]) {
						conect[i] = 0;
						send(clntSocks[i], msg, sizeof(msg), 0);
						send(clntSocks[i], list[temp], sizeof(list[temp]), 0);
					}
				}
				conect[temp] = 0;
			}
			else {
				SendMsg(msg, temp);
			}
	}

	WaitForSingleObject(hMutex, INFINITE);

	for (i = 0; i < clntCnt; i++){   // remove disconnected client
		if (hClntSock == clntSocks[i]){
			while (i++ < clntCnt - 1)
				clntSocks[i] = clntSocks[i + 1];
			break;
		}
	}
	clntCnt--;
	ReleaseMutex(hMutex);
	closesocket(hClntSock);
	return 0;
}
void SendMsg(char* msg, int temp) {   // send to all
	int i,j;
	char nameMsg[NAME_SIZE+BUF_SIZE];
	char tempMsg[NAME_SIZE];
	WaitForSingleObject(hMutex, INFINITE);
	for (j = 0; j < NAME_SIZE; j++) {
		tempMsg[j] = list[temp][j];
		if (list[temp][j] == '\n') break;
	}
	tempMsg[j] = '\0';
	sprintf(nameMsg, "[%s] %s", tempMsg, msg);
	for (i = 0; i < clntCnt; i++) {
		if(conect[i]==conect[temp])
			send(clntSocks[i], nameMsg, sizeof(nameMsg), 0);
	}

	ReleaseMutex(hMutex);
}
void ErrorHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}