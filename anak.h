#ifndef ANAK_H
#define ANAK_H

//membuat classs anak di file header anak.h
class anak {
public:
    string nama;

    anak(string pNama) : nama(pNama) {
        cout << "Anak \""  << nama << "\" ada \n";


    }

};
#endif