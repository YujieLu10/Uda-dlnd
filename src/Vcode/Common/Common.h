#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<memory>
#include<vector>

using namespace std;

class Param {

};

class BaseCommand {
public:
	virtual void setParams(const shared_ptr<Param>& p) = 0;
	virtual void exec() = 0;
};


class Observer
{
public:
	
	virtual void update(const string& attribute) = 0;
	virtual void commandSucceed(bool flag) = 0;
};

class Observable
{
private:

	vector<shared_ptr<Observer> >observerList;
public:
	void addObserver(shared_ptr<Observer> pobj) {
		observerList.push_back(pobj);
	}

	void notify(const string& attribute) {
		
		for (auto it = observerList.begin(), end = observerList.end(); it != end; it++) {
			(*it)->update(attribute);
		}
	}
	void notify(bool flag) {
		for (auto it = observerList.begin(), end = observerList.end(); it != end; it++) {
			(*it)->commandSucceed(flag);
		}
	}
};

class StringParam:public Param {
private:
	string path;
public:
	void setPath(string p) {
		path = p;
	}
	string getPath() {
		return path;
	}
};

namespace GrayType {
	enum type{
		GRAY_AVERAGE, GRAY_MAX, GRAY_WEIGHTAVE
	};
}

//namespace RemoveBG {
//	enum {
//		THRESHOLD=100
//		//0-255
//	};
//}
//
//namespace Binary {
//	enum {
//		THRESHOLD = 200
//		//0-255
//	};
//}
//namespace Denoise {
//	enum {
//		HALF_RADIUS = 1
//		//1-10
//	};
//}


class ProcessParam :public Param {
private:
	int GrayType;
	int removeBGThreshold;
	int binaryThreshold;
	int denoiseHalfRadius;
public:
	void setType(int t) {
		GrayType = t;
	}
	int getType(){
		return GrayType;
	}
	void setRemoveThreshold(int t) {
		removeBGThreshold = t;
	}
	int getRemoveBGThreshold() {
		return removeBGThreshold;
	}
	void setBinaryThreshold(int t) {
		binaryThreshold = t;
	}
	int getBinaryThreshold() {
		return binaryThreshold;
	}
	void setDenoiseHalfRadius(int r) {
		denoiseHalfRadius = r;
	}
	int getDenoiseHalfRadius() {
		return denoiseHalfRadius;
	}
};