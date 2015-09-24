#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>


int opt_apparent_size = 0;
int opt_follow_links = 0;

static int valid_name (const char *name) {
	return strcmp(name, "..") && strcmp(name, ".");
}

static int du_file (const char *path) {
	struct stat st;
	int status, size;
	char link_path[PATH_MAX + 1], entry_path[PATH_MAX + 1];
	DIR *dirp;
	struct dirent *dp;

	if ((status = lstat(path, &st)) != -1) {

		if (S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)) {
			size = opt_apparent_size ? st.st_size : st.st_blocks;

			if (S_ISLNK(st.st_mode) && opt_follow_links) {
				status = readlink(path, link_path, PATH_MAX);	

				if (status > 0) {
					link_path[status] = '\0';
					size += du_file(link_path);
				}
			}

			return size;

		} else if (S_ISDIR(st.st_mode)) {
			size = opt_apparent_size ? st.st_size : st.st_blocks;

			if ((dirp = opendir(path)) != NULL) {

				while ((dp = readdir(dirp))) {
					if (valid_name(dp->d_name)) {
						snprintf(entry_path, PATH_MAX, "%s/%s", path, dp->d_name);
						size += du_file(entry_path);
					}
				}

				closedir(dirp);

				return size;

			} else {
				fprintf(stderr, "Error during an opening file\n");
				return -1;
			}
		}

		fprintf(stderr, "Ignored type for entry %s\n", path);

		return -1;

	} else {
		fprintf(stderr, "Error during the path of the hierarchy\n");
		return -1;
	}
}

int main (int argc, char **argv) {
	int i, j, size;
	char *path;

	path = argv[argc - 1];

	for (i = 1; i < argc - 1; i++) {
		for (j = 1; j < strlen(argv[i]); j++) {
			if ((j == 0) && (argv[i][j] != '-')) {
				fprintf(stderr, "USAGE : mdu [-b | -L] [path]\n");
				exit(EXIT_FAILURE);
			}
			else if (j != 0) {
				switch (argv[i][j]) {
					case 'L':
						opt_follow_links = 1;
						break;
					case 'b' :
						opt_apparent_size = 1;
						break;
					default:
						fprintf(stderr, "Unknown option\n");
						exit(EXIT_FAILURE);
						break;
				}
			}
		}
	}

	if ((size = du_file(path)) != -1) {
		printf("%d\t%s\n", size, path);
		exit(EXIT_SUCCESS);
	} else {
		exit(EXIT_FAILURE);
	}
}
