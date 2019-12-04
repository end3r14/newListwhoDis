#include "disTable.h"

using namespace std;

int main()
{
	DisTable dTable;
	
	Dis a("Bibb County, Alabama", "575", "507", "1008", "1825", "731", "1212");
	Dis b("Hey", "Hey", "Hey", "Hey", "Hey", "Hey", "Hey");
	Dis c("Roosevelt County, Montana", "496", "266", "468", "990", "289", "487");
	Dis d("Claiborne Parish, Louisiana", "752", "735", "1109", "1580", "598", "1005");
	Dis e("Concordia Parish, Louisiana", "740", "400", "745", "1407", "538", "779");
	Dis f("Clay County, Tennessee", "400", "333", "708", "1262", "392", "710");

	Dis sample("Bibb County, Alabama", "Hey", "Hey", "Hey", "Hey", "Hey", "Hey");
	Dis sample2("*", "*", "*", "*", "Hey", "*", "*");

	dTable.disInsert(a);
	dTable.disInsert(b);
	dTable.disInsert(c);
	dTable.disInsert(d);
	dTable.disInsert(e);
	dTable.disInsert(e);
	cout << endl << endl << endl;
	dTable.dList.printDisList();
	cout << "YEAHHHHHHHH" << endl;
	dTable.disSelect(sample);
	cout << endl << endl;
	dTable.disPrint();


	//dTable.dList.deleteNode(f);
	//dTable.dList.selectNode(f);
	//
	//dTable.dList.insertNode(a);
	//dTable.dList.insertNode(b);
	//dTable.dList.insertNode(c);
	//dTable.dList.insertNode(d);
	//dTable.dList.insertNode(sample);
	//dTable.dList.insertNode(f);
	//dTable.dList.printDisList();


	//dTable.dList.selectNode(f);
	//cout << endl;

	//dTable.dList.selectNode(f);
	//dTable.dList.selectNode(sample2);
	//dTable.dList.deleteNode(a);
	//dTable.dList.printDisList();

	//dTable.dList.insertNode(f);
	//dTable.dList.printDisList();

	//dTable.disInsert(a);
	//cout << endl;
	//dTable.disInsert(b);
	//cout << endl;
	//dTable.disInsert(c);
	//cout << endl;
	//dTable.disInsert(d);
	//cout << endl;
	//dTable.disInsert(e);
	//cout << endl;
	//dTable.disInsert(f);
	//cout << endl;
	//dTable.disPrint();
	//cout << endl;
	//dTable.disInsert(a);
	//cout << endl;
	//dTable.disPrint();
	//cout << endl;
	//dTable.disSelect(a);
	//cout << endl;
	////dTable.disDelete(a);
	////dTable.disDelete(a);
	//cout << endl;
	//dTable.disPrint();
	//cout << endl;
	//dTable.disInsert(b);
	//cout << endl;
	//dTable.disPrint();
	//cout << endl;
	//dTable.disUpdate(sample);
	//cout << endl;
	//dTable.disPrint();
	//cout << endl;
	//dTable.disSelect(sample);

	return 0;
}