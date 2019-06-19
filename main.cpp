#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

class Student
{
private:
    string name;
public:
    Student (string n);
    string GetStudentName();
    void print();
    void Replace (int x, int y);

};

Student::Student(string s)
{
    int position;
    string tempname;
    int counter = 0;
    cout << "Enter your name :" << endl;
    getline(cin, s);
    for (int i=0; i<s.length(); i++)
    {
        if (s.at(i)==' ')
            counter++;
    }
    if (counter==0)
    {
        tempname.append(s);
        s.append(" ");
        s.append(tempname);
        s.append(" ");
        s.append(tempname);
    }
    if (counter==1)
    {
        position=s.find(" ");
        tempname.append(s,position+1,s.length());
        s.append(" ");
        s.append(tempname);
    }

    name = s;
    //cout << name << endl;
}

void Student::print()
{
    int counter = 1;
    cout << counter << ")";
    for (int i=0; i<name.length(); i++)
    {
        if (name[i]!=' ' )
            cout << name[i];
        else{
            counter++;
            cout << endl;
            cout << counter << ")";
        }
    }
    cout<< endl;
}
void Student::Replace(int x, int y)
{
    int position1,position2;
    string s1, s2, s3,s4;
    int s2l,s4l;
    int z;
    cout << "Which index would you like to replace? ";
    cin >> x;
    cout << "which index would you like to replace with? ";
    cin >> y;

    s1.append(name,x,name.length());
    position1=s1.find(" ");
    s2.append(s1,0,position1);
    s3.append(name,y,name.length());
    position2=s3.find(" ");
    s4.append(s3,0,position2);
    //cout<<s2<<" "<<s4<<endl;

    if (s2.length()<s4.length())
    {
        z=s4.length()-s2.length();
        if (x<y){
                name.replace(x,s2.length(),s4);
                name.replace(y+z,s4.length(),s2);
        }
        if (x>y){
                name.replace(y,s4.length(),s2);
                name.replace(x-z,s2.length(),s4);
        }
    }
    if (s2.length()>s4.length())
    {
        z=s2.length()-s4.length();
        if(x<y){
                name.replace(x,s2.length(),s4);
                name.replace(y-z,s4.length(),s2);
        }
        if (x>y){
                name.replace(y,s4.length(),s2);
                name.replace(x+z,s2.length(),s4);
        }
    }
    cout<<"Name After Replacement : ";
    cout << name << endl;
}

int main()
{
    int x;
    int y;
    string s;

    Student s1(s);
    s1.print();
    s1.Replace(x,y);

    return 0;
}
