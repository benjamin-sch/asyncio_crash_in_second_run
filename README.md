# example to reproduce a crash with asyncio in a second run of an embedded python interpreter

I've used Python 3.9.2, Windows, 64-bit

Steps to reproduce this crash:

1. download files
2. open VS2019 tools command prompt (I've used native x64) 
3. go to the extracted folder
4. mkdir build 
5. cd build
6. cmake .. 
7. open asyncio_crash_in_second_run.sln
8. change the two commented lines according to the paths on your PC
9. change "startup" project to "asyncio_crash_in_second_run"
10. compile and run project

Assertion: "Assertion failed: Py_IS_TYPE(rl, &PyRunningLoopHolder_Type), file D:\a\1\s\Modules\_asynciomodule.c, line 261"

Assumption: cached_running_holder is a static variable that is not reset after the interpreter is re-initialized.





