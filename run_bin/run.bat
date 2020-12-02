echo "copy new execute file"

copy ..\build\cwmd\Debug\cwmd.exe .
copy ..\build\loginapp\Debug\loginapp.exe .
copy ..\build\dbmgr\Debug\dbmgr.exe .
copy ..\build\timerd\Debug\timerd.exe .
copy ..\build\logapp\Debug\logapp.exe .
copy ..\build\baseapp\Debug\baseapp.exe .
copy ..\build\cellapp\Debug\cellapp.exe .

echo "delete all log files"
del /s /Q .\log





echo "run servers "

start .\cwmd.exe .\cfg.ini
start .\loginapp.exe .\cfg.ini 1 .\log\loginlog_1