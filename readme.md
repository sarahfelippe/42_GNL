# Deliverable

Create a function in C that reads each line of a file (substring until character '\n'), returns the line it has just read and goes to the next line of the file

# Constrains of the project

- Turn-in files [mandatory]: get_next_line.c, get_next_line_utils.c, get_next_line.h
- Turn-in files [bonus]: get_next_line_bonus.c, get_next_line_utils_bonus.c, get_next_line_bonus.h

- Allowed standard functions in C: read, malloc, free
	* read
		include <unistd.h>
		ssize_t read(int fd, void *buf, size_t count)
			function attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
			function returns the number of bytes read, ZERO if EOF is reached, or -1 if an error occurs
	* malloc
		include <stdlib.h>
		void *malloc(size_t size)
			function allocates a number equal to 'size' in memory heap for variables
	* free
		include <stdlib.h>
		void free(void *ptr)
			function frees the memory space pointed by 'ptr' and previously allocated by malloc/calloc

- All files must follow 42 norm

- Function must read from a file descriptor (parameter)

- Function must return the read line (string) including the character '\n', NULL if there's nothing to return (empty file or end of file), NULL if there's an error

- Function must read each line of a file regardless of BUFFER_SIZE determined during compilation (cc -Wall -Wextra -Werror -D BUFFER_SIZE=XX *.c)

# Types of scenarios

Scenario 1

IF
- File is empty; or
- Read reached EOF; or
- File descriptor is -1; or
- BUFFER_SIZE is 0; or 
- Strings with malloc/calloc cannot be allocated; or
- read function returns -1

EXPECTED BEHAVIOUR
- Function must return NULL

Scenario 2.1

IF
- File is not empty; and
- File hasn't reached EOF; and
- File has one single line (no character '\n'); and
- Line length until character EOF is smaller than or equal to BUFFER-SIZE

EXPECTED BEHAVIOUR
- Function must iterate line (string) until EOF

Scenario 2.2

IF
- File is not empty; and
- File hasn't reached EOF; and
- File has one single line (no character '\n'); and
- Line length until character EOF is greater than BUFFER-SIZE

EXPECTED BEHAVIOUR
- Function must iterate string until BUFFER-SIZE and call read function again until it reaches EOF
- Piece of line read before BUFFER_SIZE must be saved in a temporary string to be later concatenated/joined to the rest of line until EOF

Scenario 3.1

IF
- File is not empty; and
- File hasn't reached EOF; and
- File has at least two lines (at least one character '\n'); and
- Line length until character '\n' is smaller than or equal to BUFFER-SIZE

EXPECTED BEHAVIOUR
- Function must iterate line (string) until character '\n', concatenated/join the current piece of line read with previous ones
- Function must return the joined/concatenated string

Scenario 3.2

IF
- File is not empty; and
- File hasn't reached EOF; and
- File has at least two lines (at least one character '\n'); and
- Line length until character '\n' is greater than BUFFER-SIZE

EXPECTED BEHAVIOUR
- Function must iterate string until BUFFER-SIZE and call read function again until it reaches EOF or character '\n'
- Piece of line read before BUFFER_SIZE must be saved in a temporary string to be later concatenated/joined to the rest of line until EOF or '\n'

# Function logic

- If any scenario described in 1 happens, 'get_next_line' must return NULL
- Line is read during the lenght of BUFFER_SIZE and read piece must be saved in a static string until EOF or '\n' are found. While EOF or '\n' are not found, all pieces read must be concatenated/joined in the static string
- When EOF or '\n' are found, line read until EOF or '\n' must be returned by function 'get_next_line'
- If there is a piece of line read after '\n', this piece must be saved (and concatenated/joined with future ones) until EOF or '\n' are found
