#pragma once
#ifndef FILES_H_
#define FILES_H_

#include <string>
#include <vector>

class BaseFile {
private:
	std::string name;

public:
	BaseFile(std::string name);
	std::string getName() const;
	void setName(std::string newName);
	virtual int getSize() = 0;
	virtual bool isDirec() = 0;
	virtual ~BaseFile();
	//custom
	static bool compareByName(BaseFile* f1, BaseFile* f2);
	static bool compareBySize(BaseFile* f1, BaseFile* f2);



};

class File : public BaseFile {
private:
	int size;

public:
	File(std::string name, int size); // Constructor
	int getSize(); // Return the size of the file
	bool isDirec();

};

class Directory : public BaseFile {
private:
	std::vector<BaseFile*> children;
	Directory *parent;

public:
	Directory(std::string name, Directory *parent); // Constructor
	Directory *getParent() const; // Return a pointer to the parent of this directory
	void setParent(Directory *newParent); // Change the parent of this directory
	void addFile(BaseFile* file); // Add the file to children
	void removeFile(std::string name); // Remove the file with the specified name from children
	void removeFile(BaseFile* file); // Remove the file from children
	void sortByName(); // Sort children by name alphabetically (not recursively)
	void sortBySize(); // Sort children by size (not recursively)
	std::vector<BaseFile*> getChildren(); // Return children
	int getSize(); // Return the size of the directory (recursively)
	std::string getAbsolutePath();  //Return the path from the root to this
	//custom
	Directory* findDir(std::string name)const;//returns a pointer to a specific file if found and null else
	bool isDirec();//returns true
	std::string toString();
	File* findfile(std::string name)const;
	void removeChild(std::string name);
	//rule of five
	virtual ~Directory();
	Directory(const Directory& other);
	Directory &operator=(const Directory &dir);
	Directory(Directory&& other);
	Directory& operator=(Directory&& dir);

};

#endif