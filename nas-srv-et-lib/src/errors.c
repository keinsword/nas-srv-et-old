#include <stdlib.h>
#include <syslog.h>
#include "../hdr/errors.h"

error errTable[20];

void errTableInit() {
	errTable[0].errCode = INCORRECT_ARGS;
	errTable[0].errDesc = "Incorrect program arguments!\n";
	errTable[0].isCritical = 1;

	errTable[1].errCode = SOCKET_ERR;
	errTable[1].errDesc = "Error creating the socket!\n";
	errTable[1].isCritical = 1;

	errTable[2].errCode = FD_BLOCKING_ERR;
	errTable[2].errDesc = "Error switching socket FD to blocking mode!\n";
	errTable[2].isCritical = 1;

	errTable[3].errCode = SET_SOCK_OPT_ERR;
	errTable[3].errDesc = "Error setting option to socket FD!\n";
	errTable[3].isCritical = 1;

	errTable[4].errCode = BIND_ERR;
	errTable[4].errDesc = "Can't bind!\n";
	errTable[4].isCritical = 1;

	errTable[5].errCode = LISTEN_ERR;
	errTable[5].errDesc = "Error switching socket to the listening state!\n";
	errTable[5].isCritical = 1;

	errTable[6].errCode = ACCEPT_ERR;
	errTable[6].errDesc = "Can't accept the connection with client!\n";
	errTable[6].isCritical = 0;

	errTable[7].errCode = NO_MORE_PLACE;
	errTable[7].errDesc = "No more place for new clients!\n";
	errTable[7].isCritical = 0;

	errTable[8].errCode = IDENTIFY_ERR;
	errTable[8].errDesc = "Can't identify the client!\n";
	errTable[8].isCritical = 0;

	errTable[9].errCode = READ_ERR;
	errTable[9].errDesc = "Error reading new message!\n";
	errTable[9].isCritical = 0;

	errTable[10].errCode = CHECKSUM_ERR;
	errTable[10].errDesc = "Checksum missmatch!\n";
	errTable[10].isCritical = 0;

	errTable[11].errCode = SERVICE_ERR;
	errTable[11].errDesc = "Non-existing service was requested!\n";
	errTable[11].isCritical = 1;

	errTable[12].errCode = SEND_ERR;
	errTable[12].errDesc = "Error sending message!\n";
	errTable[12].isCritical = 0;

	errTable[13].errCode = CONNECT_ERR;
	errTable[13].errDesc = "Can't connect to server!\n";
	errTable[13].isCritical = 1;

	errTable[14].errCode = HOST_IS_OFFLINE;
	errTable[14].errDesc = "Host is offline!\n";
	errTable[14].isCritical = 1;

	errTable[15].errCode = PART_SEND_ERR;
	errTable[15].errDesc = "Error sending message by parts!\n";
	errTable[15].isCritical = 0;

	errTable[16].errCode = EXITPR;
	errTable[16].errDesc = "Closing program...\n\n";
	errTable[16].isCritical = 1;

	errTable[17].errCode = CONFIG_ERR;
	errTable[17].errDesc = "Reading config is crashed!\n";
	errTable[17].isCritical = 1;

	errTable[18].errCode = CONNECT_OF_ERR;
	errTable[18].errDesc = "Can't connect to server: no more place!\n";
	errTable[18].isCritical = 1;

	errTable[19].errCode = PART_READ_ERR;
	errTable[19].errDesc = "Error reading message by parts!\n";
	errTable[19].isCritical = 0;
}

void handleErr(short errCode) {
	int i, n;
	for(i = 0; i < sizeof(errTable)/sizeof(errTable[0]); i++)
		if(errTable[i].errCode == errCode) {
			n = i;
			break;
		}
	syslog(LOG_INFO, "%s", errTable[n].errDesc);
	if(errTable[n].isCritical == 1)
		exit(EXIT_FAILURE);
}
