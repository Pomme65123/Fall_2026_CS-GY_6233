#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

	if(argc < 2) {	// argv[0] is the program name and arg[v] should be the file name
		printf("User forgot to provide a file name.\n");
		return 1;
	}

	char ppid_msg[64];
	int ppid_bytes = snprintf(ppid_msg, sizeof(ppid_msg), "Parent Process ID: %d\n", getppid());
	write(STDOUT_FILENO, ppid_msg, ppid_bytes);

	srand(time(NULL));
	int random_sleep = rand()%10;
	sleep(random_sleep);

	// O_RDONLY means to open the file for reading only.
	int file = open(argv[1], O_RDONLY);
	
	if(file == -1) {
		perror("Failed to open the file.\n");
		return 1;
	}

	char buffer[1024];
	size_t input_txt_bytes;

	while((input_txt_bytes = read(file, buffer, sizeof(buffer))) > 0) {
		write(STDOUT_FILENO, buffer, input_txt_bytes);
	}

	close(file);

	return 0;
}
