#include "../moeconfig.h"

int
main(void)
{
	char buffer[255] = {0};
	puts(config_get_value(buffer, "DEFAULT", "user"));
	puts(config_get_value(buffer, "GUEST", "user"));

	return 0;
}
