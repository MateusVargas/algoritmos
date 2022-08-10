#include <stdlib.h>
#include <time.h>
main()
{
	time_t timer;
	timer = time(NULL);

	printf("horario de brasilia: %s",
		asctime(localtime(&timer)));		
}
