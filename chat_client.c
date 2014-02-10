#include "chat.h"
#include<pthread.h>

void *chatting(void *);

int
main (int argc, char *argv[])
{

	if (argc != 3 ) {
		// printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

operand printmessage_1_arg;
operand printmessages_1_arg;
  strcpy(printmessage_1_arg.myname,argv[1]);
  strcpy(printmessage_1_arg.message,argv[2]);
strcpy(printmessages_1_arg.myname,argv[1]);
  strcpy(printmessages_1_arg.message,argv[2]);

int choice ;

printf("What do u want to do\n1.Group Chat 2. Indivual Chat\n");
		scanf("%d", &choice);
		if(choice==2)
		{
//	FILE *fp  ;
//fp = fopen("messages","a+");

	CLIENT *clnt;
	char *server;
	server=(char*)malloc(100*sizeof(char)) ;

	operand *result_1;	

	printf("enter ip of frnd\n") ;
	scanf("%s",server) ;

	char *namefrnd ;

	namefrnd = (char*)malloc(100*sizeof(char)) ;	
	printf("enter his name\n") ;	
	scanf("%s",namefrnd) ;
	printmessage_1_arg.yourname[0]='\0' ;
	strcat(printmessage_1_arg.yourname,namefrnd) ;
	
	

	clnt = clnt_create (server, MESSAGEPROG, PRINTMESSAGEVERS, "udp");
	
	if (clnt == NULL) {
		//clnt_pcreateerror (server);
		exit (1);
	}


	while(1)
{
	result_1 = (operand*)printmessage_1(&printmessage_1_arg, clnt);
	if (result_1 == (operand *) NULL) {
		clnt_perror (clnt, "call failed");
	}


			
	printf("%s : %s \n",result_1->myname,result_1->message) ;
	// fprintf(fp,"%s : %s \n",result_1->myname,result_1->message);
	//fclose(fp) ;	
printf("REPLY\n") ;	
scanf("%s",&(printmessage_1_arg.message)) ;

	if(strcmp(printmessage_1_arg.message,"abuse")==0)
		exit(1) ;
}
	
	clnt_destroy (clnt);
		
		}

  		else
		{
			printf("enter number of people u want to add in ");			
			int n;
			scanf("%d",&n);
	int iret1 ;
int iret2 ;
  pthread_t threads1, threads2;

	iret1 = pthread_create(&threads1,NULL,chatting,&printmessage_1_arg);
	sleep(10) ;

	iret2 = pthread_create(&threads2,NULL,chatting,&printmessages_1_arg);
				
		pthread_join(threads1,NULL);

		pthread_join(threads2,NULL);
}

	}


void *chatting(void *optn)
{
  	operand opt = *((operand*)(optn)) ;
	CLIENT *clnt;

	char *server;
	server=(char*)malloc(100*sizeof(char)) ;

	operand *result_1;	

	printf("enter ip of frnd\n") ;
	scanf("%s",server) ;

	char *namefrnd ;

	namefrnd = (char*)malloc(100*sizeof(char)) ;	
	printf("enter his name\n") ;	
	scanf("%s",namefrnd) ;
	opt.yourname[0]='\0' ;
	strcat(opt.yourname,namefrnd) ;	

	
	

	clnt = clnt_create (server, MESSAGEPROG, PRINTMESSAGEVERS, "udp");
	
	if (clnt == NULL) {
		//clnt_pcreateerror (server);
		exit (1);
	}


	while(1)
{
	result_1 = (operand*)printmessage_1(&opt, clnt);
	if (result_1 == (operand *) NULL) {
		clnt_perror (clnt, "call failed");
	}


			
	printf("%s : %s \n",result_1->myname,result_1->message) ;
	
	printf("REPLY\n") ;	
scanf("%s",&(opt.message)) ;

	if(strcmp(opt.message,"abuse")==0)
		exit(1) ;
}
	
	clnt_destroy (clnt);
 
}
