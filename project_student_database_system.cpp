#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
using namespace std;
struct student{
    int roll;
    string name;
    float marks;
};

bool login() {

    string user, pass;
    string fileUser, filePass;

    ifstream in("login.txt");

    if (!in) {
        cout << "Login file not found!\n";
        return false;
    }

    cout << "\n===== LOGIN =====\n";

    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    in >> fileUser >> filePass;     //Agar password me space ho (future me), tab >> kaam nahi karega. Tab getline() use karte hain.

//Abhi ke liye ye perfect hai 👍

    in.close();

    if (user == fileUser && pass == filePass) {
        cout << "\n✅ Login Successful!\n";
        return true;
    }
    else {
        cout << "\n❌ Wrong Username or Password!\n";
        return false;
    }
}





void addstudent(){
     student s;
    ofstream out("data.txt",ios::app);//out is ofstrem variable it can be anything just like other variable

    cout<<"enter roll: ";
    cin>>s.roll;

    cin.ignore(); //used for ignoring newline 
    cout<<"enter name";
    getline(cin,s.name);

    cout<<"enter marks:";
    cin>>s.marks;

    out<<s.roll<<" "<<s.name<<" "<<s.marks<<" "<<endl;

    out.close();

    cout<<"student Added\n";


}

void viewstudent(){
    student s;
    ifstream in("data.txt");

    if(!in){
        cout<<"file not found\n";
        return;
    }

    cout<<"\n.........student record.............\n";

    while(in>>s.roll>>s.name>>s.marks){
        cout<<"roll:"<<s.roll<<"  |name..."<<s.name
        <<"  |marks"<<s.marks<<endl;
    }
    in.close();

}

bool changePassword() {

    string oldPass, newPass;
    string user, fileUser, filePass;

    ifstream in("login.txt");

    if (!in) {
        cout << "Login file not found!\n";
        return false;
    }

    in >> fileUser >> filePass;
    in.close();

    cout << "\n===== CHANGE PASSWORD =====\n";

    cout << "Enter Username: ";
    cin >> user;

    cout << "Enter Old Password: ";
    cin >> oldPass;

    if (user == fileUser && oldPass == filePass) {

        cout << "Enter New Password: ";
        cin >> newPass;

        ofstream out("login.txt");   // overwrite

        out << user << " " << newPass;
        out.close();

        cout << "\n✅ Password Changed! Please Login Again.\n";

        return true;   // success
    }
    else {
        cout << "\n❌ Wrong Username or Password!\n";
        return false;
    }
}



void deletestudent(int rollno){
    student s;
    ifstream in("data.txt");
    ofstream out("temp.txt");

    if(!in || !out){
        cout<<"File error\n";
        return;

    }

    bool found =false;
    while(in>>s.roll>>s.name>>s.marks){

        if(s.roll == rollno){
            found =true;         //skip this record
            
        }
        else{
            out<<s.roll<<" "<<s.name<<" "
            <<s.marks<<endl;
        }
    }
    in.close();
    out.close();

    remove("data.txt");
    rename("temp.txt","data.txt");

    if (found){
        cout<<"record deleted successfully\n";

    }
    else cout<<"not found\n";

}

void searchstudent(){
    student s;
    ifstream in("data.txt");

    int rollNo;
    bool found = false;

    cout<<"enter your roll number to search\n";
    cin>>rollNo;

    while(in>>s.roll>>s.name>>s.marks){
        if(s.roll == rollNo){
            cout<<"\n new student found\n";
            cout<<"roll:"<<s.roll<<endl;
            cout<<"name:"<<s.name<<endl;
            cout<<"marks:"<<s.marks<<endl;

            found =true;
            break;
        }
    }
    if(!found){
        cout<<"\n student not found\n";
    }
    in.close();

}

void updatestudent(int rollNumber){

    student s;
    ifstream in("data.txt");
    ofstream out("temp.txt");

    if(!in || !out){
        cout<<"file error!\n";
        return;
    }

    bool found = false;

    while(in >> s.roll >> s.name >> s.marks){

        if(s.roll == rollNumber){   // ✅ fixed ==
            found = true;

            cout<<"\n=== Enter New Name ===\n";
            cin.ignore();
            getline(cin, s.name);

            cout<<"Enter New Marks: ";
            cin>>s.marks;
        }

        // Write (updated or old)
        out << s.roll << " " << s.name << " " << s.marks << endl;
    }

    in.close();
    out.close();

    remove("data.txt");          // ✅ fixed name
    rename("temp.txt","data.txt");

    if(found)
        cout<<"Record Updated Successfully\n";
    else
        cout<<"Record Not Found\n";
}


int main() {

    while (true) {   // 🔁 LOGIN LOOP

        cout << "\n--- Please Login First ---\n";

        if (!login()) {
            cout << "Login Failed! Try Again.\n";
            continue;
        }

        cout << "\nWelcome! Login Successful 🎉\n";

        int choice, num;
        bool logout = false;

        while (!logout) {   // 🔁 MENU LOOP

            cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";

            cout << "1. Add Student\n";
            cout << "2. View Students\n";
            cout << "3. Delete Student\n";
            cout << "4. Search Student\n";
            cout << "5. Update Student\n";
            cout << "6. Change Password\n";
            cout << "7. Logout\n";
            cout << "8. Exit\n";

            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                addstudent();
                break;

            case 2:
                viewstudent();
                break;

            case 3:
                cout << "Enter Roll to Delete: ";
                cin >> num;
                deletestudent(num);
                break;

            case 4:
                searchstudent();
                break;

            case 5:
                cout << "Enter Roll to Update: ";
                cin >> num;
                updatestudent(num);
                break;

            case 6:
                if (changePassword()) {
                    logout = true;   // force logout
                }
                break;

            case 7:
                cout << "Logged Out!\n";
                logout = true;
                break;

            case 8:
                cout << "Goodbye 👋\n";
                return 0;

            default:
                cout << "Invalid Choice!\n";
            }
        }
    }

    return 0;
}
