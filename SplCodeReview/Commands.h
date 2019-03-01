#pragma once

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <string>
#include "FileSystem.h"


//all commands expect no spaces as first in args,
//and do not expect the commandit self but its flags(exception for error command which expects the command only)
class BaseCommand {
private:
	std::string args;

public:
	BaseCommand(std::string args);
	std::string getArgs();
	virtual void execute(FileSystem & fs) = 0;
	virtual std::string toString() = 0;
	virtual ~BaseCommand();
};

class PwdCommand : public BaseCommand {
private:
public:
	PwdCommand(std::string args);
	void execute(FileSystem & fs); // Every derived class should implement this function according to the document (pdf)
	virtual std::string toString();
};

class CdCommand : public BaseCommand {
private:
public:
	CdCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class LsCommand : public BaseCommand {
private:
public:
	LsCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class MkdirCommand : public BaseCommand {
private:
public:
	MkdirCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class MkfileCommand : public BaseCommand {
private:
public:
	MkfileCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class CpCommand : public BaseCommand {
private:
public:
	CpCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class MvCommand : public BaseCommand {
private:
public:
	MvCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
	bool isMovingLegal(std::string path, std::string workingPath);
};

class RenameCommand : public BaseCommand {
private:
public:
	RenameCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class RmCommand : public BaseCommand {
private:
public:
	RmCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class HistoryCommand : public BaseCommand {
private:
	const std::vector<BaseCommand *> & history;
public:
	HistoryCommand(std::string args, const std::vector<BaseCommand *> & history);
	void execute(FileSystem & fs);
	std::string toString();
};


class VerboseCommand : public BaseCommand {
private:
public:
	VerboseCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class ErrorCommand : public BaseCommand {
private:
public:
	ErrorCommand(std::string args);
	void execute(FileSystem & fs);
	std::string toString();
};

class ExecCommand : public BaseCommand {
private:
	const std::vector<BaseCommand *> & history;
public:
	ExecCommand(std::string args, const std::vector<BaseCommand *> & history);
	void execute(FileSystem & fs);
	std::string toString();
};


#endif

