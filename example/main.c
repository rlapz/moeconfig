#include "../moeconfig.h"

int
main(void)
{
	char buffer[255] = {0};
	config_get_value(buffer, "DEFAULT", "string");
	printf("%s\n", buffer);
	//memset(buffer, '\0', sizeof(buffer));
	config_get_value(buffer, "GUEST", "user");
	printf("%s\n", buffer);

	return 0;
}
