#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#define BUF_SIZE 1024
void ErrorHandling(char* message);

int main()
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[BUF_SIZE];
	int strLen = 0,recvLen=0,recvCnt;
	
	while (1) {
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
			ErrorHandling("WSAStartup() error!");

		hSocket = socket(PF_INET, SOCK_STREAM, 0);
		if (hSocket == INVALID_SOCKET)
			ErrorHandling("hSocket() error");

		memset(&servAddr, 0, sizeof(servAddr));
		servAddr.sin_family = AF_INET;
		servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		servAddr.sin_port = htons(atoi("35142"));
		if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
			ErrorHandling("connect() error!");
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;
		strLen = send(hSocket, message, strlen(message), 0);
		recvLen = 0;
		while (recvLen < strLen) {
			recvCnt = recv(hSocket, &message[recvLen], BUF_SIZE, 0);
			if (recvCnt == -1) ErrorHandling("read() error!");
			recvLen += recvCnt;
		}
		printf("Message form server : %s", message);
		closesocket(hSocket);
	}

	closesocket(hSocket);
	WSACleanup();
	return 0;
}

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}