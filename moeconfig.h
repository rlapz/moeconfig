#ifndef MOECONFIG_H
#define MOECONFIG_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define SET_DEFAULT	1	/* config_set_default enabled */
#define SET_VALUE	1	/* config_set_value enabled */

#define BUFFER_SIZE	64
#define DELIMITER	"="
#define COMMENT		"#"
#define LSECTION	'!'
#define CONFIG_FILE	"config.conf"

#if SET_DEFAULT
int config_set_default(const char *conf);
#endif

char *config_get_value(char *dest, const char *section,
		const char *key);
#if SET_VALUE
/* only set value */
void config_set_value(const char *section, const char *key,
		const char *value);
#endif

#endif
