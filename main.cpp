
#include "python.h"
#include "string"
#include "thread"
#include "vector"
#include <chrono>

int run_once()
{
  Py_SetProgramName(L"app");

  //Adjust the following line and remove the x.
  xPy_SetPythonHome(L"C:\\Program Files\\Python39"); 

  auto current_path = Py_GetPath();
  //Adjust the following line and remove the x.
  xauto newPath = std::wstring(current_path) + L";" + L"d:\\asyncio_crash_in_second_run";
  Py_SetPath(newPath.c_str());
  Py_InitializeEx(0);

  auto mod = PyImport_ImportModule("ThreadingAsync");
  auto ts = PyEval_SaveThread();

  std::this_thread::sleep_for(std::chrono::seconds(6));

  PyEval_RestoreThread(ts);
  Py_DecRef(mod);
 
  Py_FinalizeEx();
  return 0;
}



int main()
{
  run_once();
  run_once();
}