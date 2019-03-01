#pragma once
#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include "Files.h"


class FileSystem {
private:
	Directory* rootDirectory;
	Directory* workingDirectory;
public:
	FileSystem();
	Directory& getRootDirectory() const; // Return reference to the root directory
	Directory& getWorkingDirectory() const; // Return reference to the working directory
	void setWorkingDirectory(Directory *newWorkingDirectory); // Change the working directory of the file system
	//custom
	Directory* findpath(std::string path)const; //return a pointer to the needed directory (by path)
	//rule of five
	virtual ~FileSystem();
	FileSystem(const FileSystem& fs);
	FileSystem &operator=(const FileSystem &f2);
	FileSystem(FileSystem&& other);
	bool isMovingLegal(std::string path, std::string workingPath);
	FileSystem& operator=(FileSystem&& f2);

};


#endif
