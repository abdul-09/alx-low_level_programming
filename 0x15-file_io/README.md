C-FILE I\O

1. read_textfile - a function that reads a taext file and prints
  		   it to the POSIX standard output.

2. create_file - a function that creates a file, if text content
		is NULL create an empty file, if successful return
		1 else -1 .

3. append_text_to_file - appends text to the end of file.
   If text content is NULL, it does not add anything to the file.
   returns 1 if the file exists and -1 if the file doesn't exist
   or if you don't have required permissions to write the file.

4. cp - a program that copies content of a file to another file.
   If the number of arguments is not correct one it exits with
   code 97.If file exists it truncates it,if it doesn't exists it exists with code 98.
   If it cannot create it or if write to file_to fails it exits with code 99.
   If it can't close the file descriptor, it exits with code 100.
   It reads 1024 bytes at a time. Permissions of created file is: rw-rw-r--

5. Elf - a program that displays information contained in the ELF header at the start of the ELF file.
   if the file is not an ELF file, or on Error exit with status code 98,
   and display a comprehensive error message to STDERR.
