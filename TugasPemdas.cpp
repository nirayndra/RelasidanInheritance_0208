#include <iostream>
#include <string>
#include <vector>
using namespace std;

//pembuatan class user
class user {
public:
    //deklarasi member variabel dari class user
    static int globalId;
    int id;
    string nama;
    string email;

    //pembuatan constructor dan destructor dari class user
    user(string pNama, string pEmail) : nama(pNama), email(pEmail) {
        id = generateId();
        cout << "User \"" << nama << "\" dibuat\n" << endl;
    }

    ~user() {
        cout << "User \"" << nama << "\" dihapus\n" << endl;
    }

    //pembuatan function generateId
    int generateId() {
        return ++globalId;
    }

};

int user::globalId = 0;

//pembuatan class admin sebagai pewaris dari class user
class admin : public user {
public:
    //deklarasi member variabel dari class admin
    vector<user*> daftar_member;

    //pembuatan constructor dan destructor dari class admin
    admin(string pNama, string pEmail) : user(pNama, pEmail) {
        cout << "Admin \"" << nama << "\" dibuat\n" << endl;
    }

    ~admin() {
        cout << "Admin \"" << nama << "\" dihapus\n" << endl;
    }

    //pembuatan function showAllMember
    void showAllMember() {
        cout << "Daftar Member:\n";
        for (auto& m : daftar_member) {
            cout << "- " << m->nama << " | " << m->email << "\n";
        }
        cout << endl;
    }

    //pembuatan function toggleActivationMember
    void toggleActivationMember(user* pUser) {
        cout << "Aktivasi member \"" << pUser->nama << "\" di-toggle\n" << endl;
    }

};

//pembuatan class member sebagai pewaris dari class user
class member : public user {
public:
    //deklarasi member variabel dari class member
    string status;

    //pembuatan constructor dan destructor dari class member
    member(string pNama, string pEmail, string pStatus) : user(pNama, pEmail), status(pStatus) {
        cout << "Member \"" << nama << "\" dibuat\n" << endl;
    }

    ~member() {
        cout << "Member \"" << nama << "\" dihapus\n" << endl;
    }

    //pembuatan function showProfile
    void showProfile() {
        cout << "ID: " << id << "\n";
        cout << "Nama: " << nama << "\n";
        cout << "Email: " << email << "\n";
        cout << "Status: " << status << "\n";
        cout << endl;
    }

};

int main()
{
    //deklarasi dan pemberian nilai variabel object
    admin* varAdmin = new admin("Jasmine", "hashiradaun@gmail.com");
    member* varMember1 = new member("Rayndra", "hashiraikan@gmail.com", "aktif");
    member* varMember2 = new member("Nira", "hiujalan@gmail.com", "nonaktif");

    //menambahkan member ke daftar admin
    varAdmin->daftar_member.push_back(varMember1);
    varAdmin->daftar_member.push_back(varMember2);

    //pemanggilan function showAllMember dari class admin
    varAdmin->showAllMember();

    //pemanggilan function toggleActivationMember dari class admin
    varAdmin->toggleActivationMember(varMember1);

    //pemanggilan function showProfile dari class member
    varMember1->showProfile();
    varMember2->showProfile();

    //mendelete variabel pointer dari memori
    delete varMember1;
    delete varMember2;
    delete varAdmin;

    return 0;
}