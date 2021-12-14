#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h> 

#define BUF_SIZE 100
#define NAME_SIZE 20

unsigned WINAPI SendMsg(void* arg);
unsigned WINAPI RecvMsg(void* arg);
void ErrorHandling(char* msg);
void Requeset();

char name[NAME_SIZE] = "[User2]";
char msg[BUF_SIZE];
char nameother[NAME_SIZE];
SOCKET hSock;
HANDLE hSndThread, hRcvThread;

int main(int argc, char* argv[]){
	WSADATA wsaData;
	
	SOCKADDR_IN servAdr;
	
	int strLen;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hSock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAdr.sin_port = htons(atoi("31254"));

	if (connect(hSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("connect() error");

	while (1) {
		printf("what's your name?");
		fgets(name, NAME_SIZE, stdin);
		send(hSock, name, sizeof(name), 0);
		recv(hSock, msg, sizeof(msg), 0);
		if (strcmp(msg, "fail\n")) break;
		printf("re : ");
	}
	
	printf("ä�� ������ ���ӵǾ����ϴ�.\n");
	
	while (1) {
		printf("�޴��� �������ּ���.\n");
		printf("(����ڸ���ƮȮ��: !L or !l, ä�� ��û : !R or !r, ���� : !Q or !q) : ");

		fgets(msg, BUF_SIZE, stdin);

		if (!strcmp(msg, "!q\n") || !strcmp(msg, "!Q\n")){
			closesocket(hSock);
			exit(0);
		}
		send(hSock, msg, sizeof(msg), 0);

		if (!strcmp(msg, "!l\n") || !strcmp(msg, "!L\n")){
			while ((strLen = recv(hSock, msg, sizeof(msg), 0)) != 0) {
				if (!strcmp(msg, "Req\n")) {
					Requeset();
					break;
				}
				if (!strcmp(msg, "fail\n")) break;
				fputs(msg, stdout);
			}
		}
		else if (!strcmp(msg, "!R\n") || !strcmp(msg, "!r\n")) {
			printf("����� �Է��ϼ���.");
			fgets(msg, BUF_SIZE, stdin);
			send(hSock, msg, sizeof(msg), 0);
			while ((strLen = recv(hSock, msg, sizeof(msg), 0)) != 0) {
				if (!strcmp(msg, "Req\n")) Requeset();
				if (strcmp(msg, "fail\n")) break;
				printf("�������� �ʴ� ����� �Դϴ�. �ٽ� �Է��ϼ���.");
				fgets(msg, BUF_SIZE, stdin);
				send(hSock, msg, sizeof(msg), 0);
			}
			printf("��û ��\n");
			strcpy(nameother, msg);
			recv(hSock, msg, sizeof(msg), 0);
			if (!strcmp(msg, "Req\n")) Requeset();
			if (!strcmp(msg, "fail\n")) {
				printf("��û ����\n");
			}
			else {
				int i;
				for (i = 0; i < NAME_SIZE; i++) {
					if (nameother[i] == '\n') break;
				}
				nameother[i] = '\0';
				printf("[%s]�԰� ��ȭ�� �����մϴ�.(����: !E or !e)\n", nameother);

				hSndThread =
					(HANDLE)_beginthreadex(NULL, 0, SendMsg, (void*)&hSock, 0, NULL);
				hRcvThread =
					(HANDLE)_beginthreadex(NULL, 0, RecvMsg, (void*)&hSock, 0, NULL);
				
				WaitForSingleObject(hSndThread, INFINITE);
				WaitForSingleObject(hRcvThread, INFINITE);
				
			}
		}
		
	}

	closesocket(hSock);
	WSACleanup();
	return 0;
}

void Requeset() {
	char nameMsg[NAME_SIZE + BUF_SIZE];
	int i;

	recv(hSock, nameMsg, NAME_SIZE + BUF_SIZE - 1, 0);
	
	for (i = 0; i < NAME_SIZE; i++) {
		if (nameMsg[i] == '\n') break;
	}
	nameMsg[i] = '\0';
	printf("[%s]�����κ��� ��ȭ��û�� �����߽��ϴ�. (����: !Y or !y, ����: !N or !n):", nameMsg);
	fgets(msg, BUF_SIZE, stdin);
	send(hSock, msg, sizeof(msg), 0);
	if (!strcmp(msg, "!n\n") || !strcmp(msg, "!N\n")) return;
	printf("[%s]�԰� ��ȭ�� �����մϴ�.(����: !E or !e)", nameMsg);

	hSndThread =
		(HANDLE)_beginthreadex(NULL, 0, SendMsg, (void*)&hSock, 0, NULL);
	hRcvThread =
		(HANDLE)_beginthreadex(NULL, 0, RecvMsg, (void*)&hSock, 0, NULL);

	if (hRcvThread == -1) {
		return;
		hSndThread = -1;
	}
	if (hSndThread == -1) return;
	
	WaitForSingleObject(hSndThread, INFINITE);
	WaitForSingleObject(hRcvThread, INFINITE);
	
}

unsigned WINAPI SendMsg(void* arg){  // send thread main
	SOCKET hSock = *((SOCKET*)arg);
	char nameMsg[NAME_SIZE + BUF_SIZE];
	int strLen;
	
	while (1){
		fgets(msg, BUF_SIZE, stdin);
		send(hSock, msg, sizeof(msg), 0);
		if (!strcmp(msg, "!e\n") || !strcmp(msg, "!E\n")) {
			fputs("", stdout);
			printf(" ��ȭ���� �����ϴ�.\n");
			return -1;
		}	
	}
	
	return 0;
}

unsigned WINAPI RecvMsg(void* arg){   // read thread main
	int hSock = *((SOCKET*)arg);
	char nameMsg[NAME_SIZE + BUF_SIZE];
	int strLen,i;
	while (1){
		strLen = recv(hSock, nameMsg, NAME_SIZE + BUF_SIZE - 1, 0);
		if (!strcmp(nameMsg, "!e\n") || !strcmp(nameMsg, "!E\n")) {
			strLen = recv(hSock, nameMsg, BUF_SIZE, 0);
			for (i = 0; i < NAME_SIZE; i++) {
				if (nameMsg[i] == '\n') break;
			}
			nameMsg[i] = '\0';
			printf("[%s]���� ��ȭ���� �������ϴ�.\n", nameMsg);
			return -1;
		}
		if (strLen == -1)
			return -1;
		nameMsg[strLen] = 0;
		fputs("", stdout);
		fputs(nameMsg, stdout);
	}
	return 0;
}

void ErrorHandling(char* msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}