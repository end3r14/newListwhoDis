#pragma once
#include <iostream>
#include <string>

class Dis
{
private:
	std::string geoname;
	std::string hearing;
	std::string vision;
	std::string cognitive;
	std::string ambulatory;
	std::string selfcare;
	std::string independent;
	std::string key;
	
	
public:
	Dis();
	//Dis(std::string g, std::string h, std::string v, std::string c,std::string a, std::string s, std::string i);
	Dis(std::string g, std::string h, std::string v, std::string c, std::string a, std::string s, std::string i);
	void print();
	std::string showTuple();
	void setGeoN(std::string g);
	std::string getGeoN();
	void setH(std::string h);
	std::string getH();
	void setV(std::string v);
	std::string getV();
	void setC(std::string c);
	std::string getC();
	void setA(std::string a);
	std::string getA();
	void setS(std::string s);
	std::string getS();
	void setI(std::string i);
	std::string getI();
	std::string getKey();
	
	
};