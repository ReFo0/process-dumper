# PE File Dumper

![](https://img.shields.io/github/stars/refo0/process-dumper)
![](https://img.shields.io/github/forks/refo0/process-dumper)

This C++ code functions as a PE (Portable Executable) file dumper, allowing you to extract the entire contents of a running executable and save it as a separate file.

## Description

This code utilizes the Windows API to locate and extract the contents of the current process's executable and save it to a new file with a "_dump.exe" extension.

## How It Works

1. The code retrieves the base address of the current process's executable.
2. It creates a copy of the entire executable in memory.
3. It updates the section headers to match the new location and size of the sections.
4. The dumped content is then saved as a new file with "_dump.exe" appended to the original file name.

<img width=900 src="https://github.com/ReFo0/processdumper/blob/ReFo/polygon.jpg">

