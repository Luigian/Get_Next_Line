# Get Next Line

### Compilation:

`make all`
First time compilation:

`make fclean`
Delete files generated from compilation:

`make re`
Delete files generated from compilation and recompile:


### Execution:

`./test_gnl"`
Read from Standard Input:

`./test_gnl "file_path"`
Read from a single file.

`./test_gnl "file_path_1" "file_path_2" "file_path_3"`
Read from multiple files.

`./test_gnl "file_path_1" "file_path_2" "file_path_3" mix n`
Read n lines from multiple files.

### Returning values:
`1` when it read a line.

`0` when it finished reading a file.

`-1` when an error occurs.
