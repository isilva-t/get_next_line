# Get Next Line (GNL)

## Description
A C function that reads a line from a file descriptor. This project introduces the concept of static variables in C and provides a useful tool for reading from file descriptors line by line.

## Function Prototype
```c
char *get_next_line(int fd);
```

## Features
- Returns one line at a time from a file descriptor
- Works with files and standard input
- Returns NULL when there is nothing more to read or if an error occurs
- Handles the newline character ('\n') properly

## How It Works
- Uses a static variable to keep track of remaining content between function calls
- Reads from the file descriptor into a buffer
- Processes the buffer to return a complete line
- Saves any remaining content for subsequent calls

## Usage

### Compilation
```shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can adjust the buffer size to optimize performance:
- For standard files, a buffer size of 42 or 1024 works well
- For larger files, consider larger buffer sizes

### Example Implementation
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
        
    // Read file line by line
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);  // Important: free the allocated memory
    }
    
    close(fd);
    return (0);
}
```

## Important Notes
- Always free the returned line when you're done with it
- The function handles the newline character at the end of each line
- Returns NULL on EOF or when error happen
- Compatible with various buffer sizes
- Memory management is critical to avoid leaks

This function will be integrated into my libft for use in future projects.
