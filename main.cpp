#include<iostream>
#include<fstream>
using namespace std;

//Function Prototypes.
char ** create_2D(int r, int c);
char * create_1D(int s);
void del_2D(char ** p, int s);
void del_1D(char * p);
void read_courses(ifstream & fin, char ** p, int r);
void display_2D(char ** p, int r);
bool check_equal(char * p1, char * p2);
char ** shrink(char ** p, int & r, int f);
void copy(char ** n, char ** p, int r, int f);

//Main Function.
int main()
{
	//Creating 5 2D Arrays for storing course code, credit hour and student ids.
	//1 2D Array for each course.
	char ** c1 = create_2D(3, 8);
	char ** c2 = create_2D(3, 8);
	char ** c3 = create_2D(3, 8);
	char ** c4 = create_2D(3, 8);
	char ** c5 = create_2D(3, 8);
	
	char ** courses = create_2D(5, 100);
	
	int x1 = 2, x2 = 2, x3 = 2, x4 = 2, x5 = 2;
	
	ifstream fin;
	fin.open("Courses.txt");
	
	if (!fin)
	{
		cout << "\nFile not found.\n";
	}
	else
	{
				
		
		read_courses(fin, courses, 5);
		
		fin.close();
		fin.open("Courses.txt");
		char arr[100];
		
		fin>>c1[0];
		fin>>c1[1];
		fin.get(arr,100);
		fin>>c2[0];
		fin>>c2[1];
		fin.get(arr,100);
		fin>>c3[0];
		fin>>c3[1];
		fin.get(arr,100);
		fin>>c4[0];
		fin>>c4[1];
		fin.get(arr,100);
		fin>>c5[0];
		fin>>c5[1];
		fin.get(arr,100);
		
		fin.close();
		
		
	}
	while (true)
	{
		cout << "\n**********Menu***********" << endl;
		char choice;
		cout << "\nPress 1 for Enrollment of the Student in a Course.\n"
			"Press 2 for drop a Specified Course.\n"
			"Press 3 for Display Students Enrolled courses.\n"
			"Press 4 for Display Total number of Students enrolled in particular course.\n"
			"Press 5 for Display course not enrolled by any student.\n"
			"Press 0 to Exit the Program.\n"
			"Enter Choice: ";
		cin >> choice;

		if (choice == '0')
		{
			del_2D(c1,3);
			del_2D(c2,3);
			del_2D(c3,3);
			del_2D(c4,3);
			del_2D(c5,3);
			
			del_2D(courses, 5); 
			
			return 0;
		}

		switch (choice)
		{
		case '1':
		{
			int opt;
			cout << "\nChoose a course from the following courses: " << endl;
			display_2D(courses, 5);
			cout << "Your choice: ";
			cin >> opt;
			
			char* id = create_1D(9);
			cout << "\nEnter Student ID: ";
			cin >> id;				
				
			switch(opt)
			{
				case 1:
					c1[x1++] = id;
					cout << "\nYou have been enrolled successfully." << endl;
					break;
				case 2:
					c1[x2++] = id;
					cout << "\nYou have been enrolled successfully." << endl;
					break;
				case 3:
					c1[x3++] = id;
					cout << "\nYou have been enrolled successfully." << endl;
					break;
				case 4:
					c1[x4++] = id;
					cout << "\nYou have been enrolled successfully." << endl;
					break;
				case 5:
					c1[x5++] = id;
					cout << "\nYou have been enrolled successfully." << endl;
					break;
				default:
					cout << "\nInvalid course. Try Again." << endl;
					break;
			}
			del_1D(id);
			break;
		}
		case '2':
		{
			char * id = create_1D(9);
			cout<<"\nEnter Student ID: ";
			cin >> id;
			
			int a = 0;
			
			char * code = create_1D(9);
			cout << "\nEnter Course Code: ";
			cin >> code;
			
			if(check_equal(code, c1[0]))
			{
				if(x1 == 2 )
				{
					cout << "\nStudent is not registered in this course.\n";
				}
				else
				{
					bool flag = false;
					for(int i = 2; i < x1; i++)
					{
						if(check_equal(id, c1[i]))
						{
							a = i;
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						cout << "\nStudent is not registered in this course.\n";
					}
					else
					{
						c1 = shrink(c1, x1, a);
						cout << "\nCourse dropped successfully.\n";
					}
				}
			}
			else if(check_equal(code, c2[0]))
			{
				if(x2 == 2 )
				{
					cout << "\nStudent is not registered in this course.\n";
				}
				else
				{
					bool flag = false;
					for(int i = 2; i < x2; i++)
					{
						if(check_equal(id, c2[i]))
						{
							a = i;
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						cout << "\nStudent is not registered in this course.\n";
					}
					else
					{
						c2 = shrink(c2, x2, a);
						cout << "\nCourse dropped successfully.\n";
					}

				}
			}
			else if(check_equal(code, c3[0]))
			{
				if(x3 == 2)
				{
					cout << "\nStudent is not registered in this course.\n";
				}
				else
				{
					bool flag = false;
					for(int i = 2; i < x3; i++)
					{
						if(check_equal(id, c3[i]))
						{
							a = i;
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						cout << "\nStudent is not registered in this course.\n";
					}
					else
					{
						c3 = shrink(c3, x3, a);
						cout << "\nCourse dropped successfully.\n";
					}

				}
			}
			else if(check_equal(code, c4[0]))
			{
				if(x4 == 2)
				{
					cout << "\nStudent is not registered in this course.\n";
				}
				else
				{
					bool flag = false;
					for(int i = 2; i < x4; i++)
					{
						if(check_equal(id, c4[i]))
						{
							a = i;
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						cout << "\nStudent is not registered in this course.\n";
					}
					else
					{
						c4 = shrink(c4, x4, a);
						cout << "\nCourse dropped successfully.\n";
					}

				}
			}
			else if(check_equal(code, c5[0]))
			{
				if(x5 == 2)
				{
					cout << "\nStudent is not registered in this course.\n";
				}
				else
				{
					bool flag = false;
					for(int i = 2; i < x5; i++)
					{
						if(check_equal(id, c5[i]))
						{
							a = i;
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						cout << "\nStudent is not registered in this course.\n";
					}
					else
					{
						c5 = shrink(c5, x5, a);
						cout << "\nCourse dropped successfully.\n";
					}

				}
			}
			else
			{
				cout << "\nInvalid Course Code. Try Again.\n";
				break;
			}
			
			del_1D(id);
			del_1D(code);
			break;
		}
		case '3':
		{
			char * id = create_1D(9);
			int * count = new int;
			count = 0;
			
			cout << "Enter Student ID: ";
			cin >> id;
			
			if(x1 != 2)
			{
				for(int i = 2; i < x1; i++)
				{
					if(check_equal(id, c1[i]))
					{
						cout << "\n" << c1[0] << "\t" << c1[1] << endl;
						count++;
						break;
					}
				}
			}
			
			if(x2 != 2)
			{
				for(int i = 2; i < x2; i++)
				{
					if(check_equal(id, c2[i]))
					{
						cout << "\n" << c2[0] << "\t" << c2[1] << endl;
						count++;
						break;
					}
				}
			}
			
			if(x3 != 2)
			{
				for(int i = 2; i < x3; i++)
				{
					if(check_equal(id, c3[i]))
						{
							cout << "\n" << c3[0] << "\t" << c3[1] << endl;
							count++;
							break;
						}
					}
			}
			
			if(x4 != 2)
			{
				for(int i = 2; i < x4; i++)
				{
					if(check_equal(id, c4[i]))
					{
						cout << "\n" << c4[0] << "\t" << c4[1] << endl;
						count++;
						break;
					}
				}
			}
			
			if(x5 != 2)
			{
				for(int i = 2; i < x5; i++)
				{
					if(check_equal(id, c5[i]))
					{
						cout << "\n" << c5[0] << "\t" << c5[1] << endl;
						count++;
						break;
					}
				}
			}
			
			if(count == 0)
			{
				cout << "\nNo student is currently enrolled in any course." << endl;
			}
			
			delete count;
			del_1D(id);
			break;
		}
		case '4':
		{
			char * code = create_1D(8);
			cout << "\nEnter the Course code: ";
			cin >> code;
			if(check_equal(code, c1[0]))
			{
				cout << "\nTotal enrolled students for this course are: " << x1 - 2 << endl;
			}
			else if(check_equal(code, c2[0]))
			{
				cout << "\nTotal enrolled students for this course are: " << x2 - 2 << endl;
			}
			else if(check_equal(code, c3[0]))
			{
				cout << "\nTotal enrolled students for this course are: " << x3 - 2 << endl;
			}
			else if(check_equal(code, c4[0]))
			{
				cout << "\nTotal enrolled students for this course are: " << x4 - 2 << endl;
			}
			else if(check_equal(code, c5[0]))
			{
				cout << "\nTotal enrolled students for this course are: " << x5 - 2 << endl;
			}
			else
			{
				cout << "\nInvalid Code Course. Try Again.";
				break;
			}
			del_1D(code);
			break;
		}
		case '5':
		{
			if(x1 == 2)
			{
				cout << c1[0] << endl;
			}
			if(x2 == 2)
			{
				cout << c2[0] << endl;
			}
			if(x3 == 2)
			{
				cout << c3[0] << endl;
			}
			if(x4 == 2)
			{
				cout << c4[0] << endl;
			}
			if(x5 == 2)
			{
				cout << c5[0] << endl;
			}
			if(x1 != 2 && x2 != 2 && x3 != 2 && x4 !=2 && x5 != 2)
			{
				cout << "\nNo Course Found.\n";
			}
			break;
		}
		default:
			cout << "\nInvalid Input. Please try again." << endl;
			break;
		}
	}
}

char ** create_2D(int r, int c)
{
	char ** p = new char * [r];
	for(int i = 0; i < r; i++)
	{
		p[i] = new char[c];
	}
	return p;
}
char * create_1D(int s)
{
	char * p = new char [s];
	return p;
}
void del_2D(char ** p, int s)
{
	for(int i = 0; i < s; i++)
	{
		delete[]p[i];
	}
	delete[]p;
	p = 0;
}
void del_1D(char * p)
{
	delete[]p;
	p = 0;
}
void read_courses(ifstream & fin, char ** p, int r)
{
	for(int i = 0; i < r; i++)
	{
		fin.getline(p[i], 100);
	}
}
void display_2D(char ** p, int r)
{
	for(int i = 0; i < r; i++)
	{
		cout << i + 1 << ". " << p[i] << endl;
	}
}
bool check_equal(char * p1, char * p2)
{
	bool flag = true;
	for(int i = 0; i < 8; i++)
	{
		if(p1[i] != p2[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}
char ** shrink(char ** p, int & r, int f)
{
	char ** n = create_2D(r - 1, 1);
	copy(n, p, r - 1, f);
	r--;
	del_2D(p, r);
	return n;
}
void copy(char ** n, char ** p, int r, int f)
{
	int k = 0;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; p[i][j] != '\0'; j++)
		{			
			if(i != f)
			{
				n[k][j] = p[i][j];
			}
		}
		k++;
	}
}