#include <unistd.h>
#include <getopt.h>

#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE;

#define _ERROR_ARGUMENT 1
#define _ERROR_SERVER 2
#define _ERROR_CLIENT 3

#define USERNAME_LEN 16
#define FILENAME_LEN 32
#define MESSAGE_BUFFER 256

/*global program variables*/
char username[USERNAME_LEN]="user";
const char path[FILENAME_LEN]="./";
char filename[FILENAME_LEN]="temp_chat";
BYTE flags = 0x00; /*bits are read from right to left
		    0 -> server write [0 -> off, 1-> on]
		    1 -> client write[0 -> off, 1-> on]
		    6 more flags can be added*/
pid_t client;
pid_t server;

/*END global variables*/

void parse_options(int, char**);
void create_server();
void create_client();

int main(int argc, char** argv){
	parse_options(argc, argv);

	/*create server and client processes, parent will manage their state*/
	create_server();
	create_client();

	/*manage server/client state*/
	wait(NULL); /*wait for client to end*/
	kill(server,9); /*if client end its jobs, kill server*/

        return 0;
}

void create_server(){
	pid_t thread;
	FILE* f = NULL;
	char full_path[2*FILENAME_LEN];
	char* message=NULL;
	int len=0;
	char test;

	/*create new thread using fork()*/
	thread = fork();
	if(thread < 0){
		printf("Server client could not be created!");
		exit(_ERROR_SERVER);
	}
	else if(thread > 0){ 
		server = thread;	
		return;
	} /*parent process*/

	sprintf(full_path,"%s%s",path,filename);
	printf("Server has been created\n");

	/*server code*/
	while(1){
		f = fopen(full_path,"r");
		if((test=fgetc(f))==EOF){
			fclose(f);
			sleep(1);
			continue;
		}/*file is empty, no pending messages to show*/
		ungetc(test,f); /*putback test character*/
		while(getline(&message,&len,f)!=EOF)
			printf("%s",message);
		sleep(5);
		fclose(f);
		free(message);
		fclose(fopen(full_path,"w"));
		f = fopen(full_path,"r");
	}
}

void create_client(){
	pid_t thread;
	FILE* f = NULL;
	char full_path[2*FILENAME_LEN];
	char* message=NULL;
	int len=0;

	thread = fork();

	if(thread < 0){
		printf("Server client could not be created!");
		exit(_ERROR_CLIENT);
	}
	else if(thread > 0){ 
		client=thread;
		return;
	} /*parent process*/

	/*client code*/
	sprintf(full_path,"%s%s",path,filename); /*create full path*/
	f = fopen(full_path,"a"); /*open file  in append mode*/
	printf("Client has been created\n");
	fprintf(f,"[%s] joined the chat\n",username);
	fclose(f);
	
	while(1){
		printf(">");
		if(getline(&message, &len, stdin)==EOF)
			break;
		f = fopen(full_path,"a");
		fprintf(f,"[%s] %s", username, message);
		fclose(f);
		free(message);
		sleep(3);
	}

	f =fopen(full_path,"a");
	fprintf(f, "[%s] left the chat\n",username);
	fclose(f);

	exit(EXIT_SUCCESS);
}

void parse_options(int argc, char** argv){
	char c;

	while((c=getopt(argc,argv,":s:u:h"))!=-1){
		switch(c){
			case 'u':{	 
				if(strlen(optarg) > sizeof(username)){
					printf("Username can be up to 15 characters long!");
					exit(_ERROR_ARGUMENT);
				}
				sprintf(username, "%s",optarg);		
				break;
			}

			case 's':{
				if(strlen(optarg) > sizeof(filename)){
					printf("Chat filename can be up to 31 characters long!");
					exit(_ERROR_ARGUMENT);
				}
				sprintf(filename, "%s",optarg);
				break;		
			}

			case 'h':
				 printf("-u -> sets username\n-s -> sets servername\n");
				 exit(EXIT_SUCCESS);
			case ':':
				 printf("option %c needs argument\n",optopt);
				 exit(_ERROR_ARGUMENT);
				 exit(_ERROR_ARGUMENT);
			default:
				 printf("Unknown option: %c\n",optopt);
		}
	}
}
