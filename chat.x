struct operand
{ 
	char myname[100];	
	char message[100] ;
	char yourname[100] ;
};


program MESSAGEPROG {
   version PRINTMESSAGEVERS {
     operand PRINTMESSAGE(operand) = 1;
   } = 1;
} = 0x20000001;
