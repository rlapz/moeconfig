#include "../moeconfig.h"

int
main(void)
{
	char buffer[255];
	puts(config_get_value(buffer, "DEFAULT", "string"));
	//memset(buffer, '\0', sizeof(buffer));
	puts(config_get_value(buffer, "GUEST", "user"));

	return 0;
}
