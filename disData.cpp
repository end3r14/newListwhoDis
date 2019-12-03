#include "disData.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Dis::Dis()
{
	geoname = "";
	hearing = "-2";
	vision = "-2";
	cognitive = "-2";
	ambulatory = "-2";
	selfcare = "-2";
	independent = "-2";
	key = geoname;
	
	
}

Dis::Dis(std::string g, std::string h, std::string v, std::string c, std::string a, std::string s, std::string i)
{
	geoname = g;
	hearing = h;
	vision = v;
	cognitive = c;
	ambulatory = a;
	selfcare = s;
	independent = i;
	key = geoname;
	
	//ind = -2;
	//jind = -2;
	//addr = nullptr;
}

//Dis::Dis(string g, string f, string e, string s, int h)
//{
//	geoid = g;
//	under5 = f;
//	under18 = e;
//	over65 = s;
//	key = geoid;
//	hashkey = h;
//	ind = -2;
//	jind = -2;
//}

//prints an Age object
void Dis::print()
{
	cout << left << setw(30) << geoname << left << setw(10) << hearing << left << setw(10) <<vision << left << setw(10) << cognitive<< setw(10) << ambulatory << left << setw(10) << selfcare << left << setw(10) <<independent << endl;
}

string Dis::showTuple()
{
	return "(\"" + geoname + "\"," + hearing + "," + vision + "," + cognitive + "," + ambulatory + "," + selfcare + "," + independent + ")";
}

void Dis::setGeoN(string g)
{
	geoname = g;
	key = geoname;
}

string Dis::getH()
{
	return hearing;
}
void Dis::setH(string h)
{
	hearing = h;
	
}

string Dis::getGeoN()
{
	return geoname;
}

void Dis::setV(string v)
{
	vision = v;
}

string Dis::getV()
{
	return vision;
}

void Dis::setC(string c)
{
	cognitive = c;
}

string Dis::getC()
{
	return cognitive;
}

void Dis::setA(string a)
{
	ambulatory = a;
}

string Dis::getA()
{
	return ambulatory;
}
void Dis::setS(string s)
{
	selfcare = s;
}

string Dis::getS()
{
	return selfcare;
}
void Dis::setI(string i)
{
	independent = i;
}

string Dis::getI()
{
	return independent;
}

string Dis::getKey()
{
	return key;
}