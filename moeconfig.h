#ifndef MOECONFIG_H
#define MOECONFIG_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 64
#define DELIMITER "="
#define COMMENT "#"
#define LSECTION '!'
#define CONFIG_FILE "config.conf"

int config_set_default(const char *conf);
char *config_get_value(char *dest, const char *section,
		const char *key);
/* only set value */
void config_set_value(const char *section, const char *key,
		const char *value);

#endif
