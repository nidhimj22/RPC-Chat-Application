#include "chat.h"

operand *
printmessage_1_svc(operand *argp, struct svc_req *rqstp)
{
	static operand  result;
	FILE *fp ;
	fp=fopen("messages","a+") ;

	char *input1 ;
	char *input2 ;
	input1=(char*)malloc(100*sizeof(char));
	input2=(char*)malloc(100*sizeof(char));

	printf("%s : %s \n",argp->myname,argp->message) ;
	fprintf(fp,"%s : %s \n",argp->myname,argp->message);
	result.message[0]='\0' ;
	result.myname[0]='\0' ;	
	result.yourname[0]='\0' ;
	strcat(result.yourname,argp->myname) ;

	strcat(result.myname,argp->yourname) ;
	
	printf("REPLY\n") ;
	scanf("%s",input2) ;
	strcat(result.message,input2) ;
	fclose(fp) ;
	return &result;
}
