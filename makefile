CC = g++
OBJS = auDisktTool.o
.PHONY:clean
	rm $(OBJS)
auDiskTool: auDiskTool.cpp Tool.cpp Configuration.cpp Commandline.cpp Report.cpp
Tool: Tool.h 
Commandline: Commandline.h
Configuration: Configuration.h
Report: Report.h

