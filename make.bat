@echo off
call checkvid
tsc /zq /m keyscan.pr /smain=keyscan /%jpivid%
del keyscan.exe
