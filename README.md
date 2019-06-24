# Get Next Line

Compilation:
`make all`

Read from Standard Input:

`./test_gnl"`

Read from a single file:
`./test_gnl "file_path"`

Read from multiple files:
`./test_gnl "file_path_1" "file_path_2" "file_path_3"`

Read n lines from multiple files:
`./test_gnl "file_path_1" "file_path_2" "file_path_3" mix n

Return value:
`return 1 when it read a line`
`return 0 when it finished reading a file`
`return -1 when an error occurs`
