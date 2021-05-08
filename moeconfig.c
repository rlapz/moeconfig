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

	char buffer[BUFFER_SIZE+1] = {0};
	char *line = NULL;
	char *current = NULL;
	char *k = NULL;
	/* int linecount = 1; */

	/* find section */
	while ((line = fgets(buffer, BUFFER_SIZE, f))) {
		/* linecount++; */
		if ((current = strstr(line, COMMENT)))
			*current = '\0'; /* cut # char, ignore the rest */

		line = ltrim(rtrim(line)); /* clear white chars */
		if (line[0] != LSECTION) {
			/* memset(buffer, '\0', sizeof(buffer)); */
			continue;
		}

		if (strncmp(line+1, section, strlen(section)) == 0) {
			/* section found */
			/* then find value of key */
			while ((k = fgets(buffer, BUFFER_SIZE, f)) && (k[0] != LSECTION)) {
				k = ltrim(rtrim(k));

				if ((current = strstr(k, COMMENT)))
					*current = '\0';
				if (strlen(k) == 0 || !strstr(k, DELIMITER))
					continue;

				k = strtok(k, DELIMITER); /* split string by token(delimiter) */
				/* compare key */
				if (strncmp(rtrim(ltrim(k)), key, strlen(key)) == 0) {
					k = strtok(NULL, DELIMITER);
					k = rtrim(ltrim(k));
					if (strlen(k) == 0)
						goto cleanup;
					/* value found */
					strncpy(dest, k, strlen(k));
					break;
				}
			}
			break;
		}
	}
cleanup:
	fclose(f);
	return dest;
}

void
config_set_value(const char *section, const char *key,
		const char *value)
{
	/* TODO */
}
