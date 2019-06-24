# Get Next Line

### Compilation:

First time compilation:
`make all`

Delete files generated from compilation:
`make fclean`

Delete files generated from compilation and recompile:
`make re`

### Execution:

Read from Standard Input:
`./test_gnl"`

Read from a single file:
`./test_gnl "file_path"`

Read from multiple files:
`./test_gnl "file_path_1" "file_path_2" "file_path_3"`

Read n lines from multiple files:
`./test_gnl "file_path_1" "file_path_2" "file_path_3" mix n`

### Returning values:
`1` when it read a line
`0` when it finished reading a file
`-1` when an error occurs
