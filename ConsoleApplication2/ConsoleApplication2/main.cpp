#include<iostream>
#include"Header.h"
#include <cassert>
#include<algorithm>
using namespace std;
int menu_choice = 0;
int menu()
{
	cout << endl << "Menu" << endl;
	cout << "1) put a new record to the front of the list" << endl;
	cout << "2) put a new record to the back of the list" << endl;
	cout << "3) print all the records from the begining to the end of the list" << endl;
	cout << "4) print all the records from the end to the begining of the list" << endl;
	cout << "5) delete by value" << endl;
	cout << "6) count the size of the list" << endl;
	cout << "7) sort the list" << endl;
	cout << "8) sum records" << endl;
	cout << "9) replace records in the list with random ones" << endl;
	cout << "10) compare records of the list to the new list" << endl;
	cout << "11) unite two lists into one union" << endl;
	cout << "12) exit" << endl;
	cin >> menu_choice;
	return menu_choice;
}

void message()
{
	cout << "print a year of birth: " << endl;

}

typedef int tip;
List<tip> the_list; // empty list
int main()
{
	int ret = 0;
	List<tip>::iterator list_iter;
	List<tip>::iterator list_iter2;
	int date = 0;
	while (menu_choice != 12){
		switch (menu()){
		case 1:
		{
			//add
			message();
			cin >> date;
			the_list.add_front(date);
			break;
		}
		case 2:
		{
			//add
			message();
			cin >> date;
			the_list.add_rear(date);
			break;
		}
		case 3:
		{
			// print from the beginning to the end
			for (list_iter = the_list.front();
			list_iter != the_list.rear();
			++list_iter) //iterator's increment
			cout << *list_iter << " ";
			cout << endl;
			break;
		}


		case 4:{
			// print from the end to the beginning
			for (list_iter = the_list.rear(); list_iter != the_list.front();)
			{
				--list_iter;   // iterator's decrement
				cout << *list_iter << " ";
			}
			cout << endl;
			break;
		}
		case 5:{
			// delete
			int search = 0;
			message();
			cout << "    to delete" << endl;
			cin >> search;
			the_list.remove_it(the_list.find(search)); //remove element through finding it
			break;
		}
		case 6:{
			cout << "size:" << the_list.size() << endl;
			break;
		}
		case 7:{
			// sort the list
			for (list_iter = the_list.front(); list_iter != the_list.rear();
				list_iter++){
				for (list_iter2 = the_list.front(); list_iter2 != the_list.rear() ; list_iter2++)
				{
					if (*list_iter > *list_iter2)
					iter_swap(list_iter, list_iter2);
				}
			}
			cout << "sort is done " << endl;
			break;
		}
		case 8:{
			// count sum
			int sum = 0;
			for (list_iter = the_list.front(); list_iter != the_list.rear(); list_iter++)
			{
				sum += *list_iter;
			}
			cout << "done" << endl;
			cout << "sum is "<< sum << endl;
			break;
		}

		case 9:{
			//generate random records
			for (list_iter = the_list.front(); list_iter != the_list.rear(); list_iter++)
			{
				*list_iter = 1950 + rand() % (2017 - 1950); // random record - a year of birth between 1950 and 2017
			}
			cout << "done " << endl;
			break;

		}
		case 10:{
			// equal
			List<tip> one_more_list; //create a new empty list
			one_more_list.add_front(1996);
			one_more_list.add_front(1998); //initiallization of a new list
			one_more_list.add_front(2000);
			List<tip>::iterator one_more_list_iter;
			one_more_list_iter = one_more_list.front();
			for (list_iter = the_list.front(); list_iter != the_list.rear(); list_iter++, one_more_list_iter++)
			{
				if (*list_iter != *one_more_list_iter) //if records are not equal
					cout << "not equal"<<endl;
				else cout << "equal" << endl;
			}
			break;

		}

		case 11:{
			// create a union
			List<tip> one_more_list; //create a new empty list
			one_more_list.add_front(2001);
			one_more_list.add_front(1974); //initiallization of a new list
			List<tip>::iterator one_more_list_iter;
			List<tip>::iterator result;
			List<tip> union_list;
			result = union_list.front();
			one_more_list_iter = one_more_list.front();
			for (list_iter = the_list.front(); list_iter != the_list.rear(); list_iter++)
			{
				*result++ = *list_iter;
			}
			for (one_more_list_iter = one_more_list.front(); one_more_list_iter != one_more_list.rear(); one_more_list_iter++)
			{
				*result++ = *one_more_list_iter;
			}
			cout << "done " << endl;
			break;

		}
			return 0;
		}
	}
}