#include "moeconfig.h"

static char *
ltrim(char *str)
{
	while (isspace(*str))
		str++;
	return str;
}

static char *
rtrim(char *str)
{
	char *end = str + strlen(str)-1;
	while (isspace(*end)) {
		*end = '\0';
		end--;
	}
	return str;
}

int
config_set_default(const char *conf)
{
	/* TODO */
	return 0;
}

char *
config_get_value(char *dest, const char *section, const char *key)
{
	FILE *f = fopen(CONFIG_FILE, "r");
	if (!f) {
		perror(CONFIG_FILE);
		return NULL;
	}

	char *k				= NULL;
	char *v				= NULL;
	char *line			= NULL;
	char *current			= NULL;
	char buffer[BUFFER_SIZE+1]	= {0};
	size_t value_len		= 0;
	size_t key_len			= strlen(key);
	size_t section_len		= strlen(section);
	/* size_t linecount = 1; */

	/* find section */
	while ((line = fgets(buffer, BUFFER_SIZE, f))) {
		/* linecount++; */
		if ((current = strstr(line, COMMENT)))
			*current = '\0'; /* cut on # char, ignore the rest */

		line = ltrim(line); /* clear left white chars */
		if (line[0] != LSECTION)
			continue;

		if (strncmp(line+1, section, section_len) == 0) {
			/* section found */
			/* then find value of key */
			while ((k = fgets(buffer, BUFFER_SIZE, f)) && (k[0] != LSECTION)) {
				if ((current = strstr(k, COMMENT)))
					*current = '\0';
				if (strlen(k) == 0 || !strstr(k, DELIMITER))
					continue;

				k = strtok(ltrim(k), DELIMITER); /* split string by token(delimiter) */
				/* compare key */
				if (strncmp(k, key, key_len) == 0) {
					v = strtok(NULL, DELIMITER);
					v = rtrim(ltrim(v));
					value_len = strlen(v);
					if (value_len == 0)
						goto cleanup;
					/* value found */
					strncpy(dest, v, value_len);
					dest[value_len] = '\0';
					goto cleanup;
				}
			}
			break;
		}
	}
cleanup:
	fclose(f);
	if (value_len > 0)
		return dest;
	return NULL;
}

void
config_set_value(const char *section, const char *key,
		const char *value)
{
	/* TODO */
}
