## Compiling and Runing with GCC

-   **Build:** `/usr/bin/gcc -g <file_name>.c o <file_path>/<file_name>`
-   **Execute output file:** `./<file_name>`

## VsCode Setup:

-   Build Shortcut: `ctrl+shift+b`
-   Run application: `F5`

**Build Task (.vscode/task.json)**

```json
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "gcc build file",
            "command": "/usr/bin/gcc", // gcc path
            "args": [
                "-g",
                "${file}", //file_name
                "-o",
                "${fileDirname}/bin/${fileBasenameNoExtension}" // output file path
            ],
            "options": {
                "cwd": "/usr/bin" // current working directory set to path location of compiler
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

**Launcher / Debugger Setup**

**.vscode/launch.json**

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/bin/${fileBasenameNoExtension}", //path from where to run executable
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}", // current working directory
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            // Compile before runing actual application
            // this is set to the label of build task
            "preLaunchTask": "gcc build file"
        }
    ]
}
```

## C Minimal Biolerplate

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello world);
    return 0;
}
```
