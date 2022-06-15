/*
* see chapter#01 topic 1.4 polymorphism in c++ book.(R1. Data structure and algorithm in c++ 2nd edition - Adam Drozdek)
* declaration based call - jo ap pointer 'p' se koi function call kren tou wo 'p' pointer jis class ki type se declare huwa ho*, ALRIGHT!!
* jb declaration based call jati hai, agay se virtual na mily tou all good.(ye delaration based call successfully ho jaye gi)
* jb declaration based call jati hai, agay se wo call/function virtual mily tou wo value based function k pas jata
* agr yahan wo func na milay tou crash, agr milay(naam bs same ho, chly ga) lakin non-virtual tou crash(~).
* compile time pe ap ko ye p hmesha dec class me defined functions hi allow kry ga(tou mtlb ap ko usi name k functions value based classes me bnany ho gy)
  in other words, p se sirf f aur g call hon gy, ye f aur g kisi b class k ho skty.

~ => agr non virtual function hai but ye drived class hai declaration based class ki, tou non-virtual b chlay ga.
virtual-value based call.
non-virtual-declaration based call.

*/

#include <iostream>
using namespace std;
class class1 {
public:
    virtual void f() {
        cout << "Function f() in class1\n";
    }
     void g() {
        cout << "Function g() in class1\n";
    }

};
class class2 {
public:
    void f() {
        cout << "Function f() in class2\n";
    }
    void g() {
        cout << "Function g() in class2\n";
    }
};
class class3 {
public:
    void h() {
        cout << "Function h() in class3\n";
    }
};

int main(void) {
    class1 object1, * p;
    class2 object2;
    class3 object3;

    p = &object1;
    p->f();
    p->g();

    p = (class1*)&object2;
    p->f();
    p->g();


    p = (class1*)&object3;
    //p->f();           //run time crash(fun def not found in value based class i.e class3), it will not crash, if class1 f() is not virtual. 
    p->g();
    //p->h();          // compile time error
    return 0;


    //'p' pointer declaration type((class1)) ki base pe call k liye jata hai, wahan se virtual dekh k wapsi 
    //krta hai aur phir aa k p ki value ki base pe call k liye us value based class k function k pas jata hai.
    
    /*agr 'p' ptr ko virtual function na milay tou program chal jata usi declaration based call k sath. 
   agr 'p' ptr ko virtual function milay aur wo valu based class me na ho tou program crash krta*/
    

}
