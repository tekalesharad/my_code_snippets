#include <stdio.h>
#define CERT_TIME " "
#define CURR_TIME " "

main() {

	char *date="Thu Oct 31 16:59:41 IST 2013";
	int remaining;

	if ( year_local > year_cert )
	  printf("Expired.. \n"); 
	else if ( year_local < year_cert ) {
	 if ( month_cert - month_local > 9 )
	   remaining = 1;
	}
	else {
	 if ( month_cert - month_local < 2 )
	   remaining = 1;
	}
  


}
