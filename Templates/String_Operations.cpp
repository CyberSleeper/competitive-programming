#include <iostream>
#include <string>
using namespace std;
int main(){
    string a="Pak Dengklek";
    cout << a.find("Deng");
    cin >> a;
    a[0]='0'+1;
    cout << 't'+a << endl;
    cout << a.insert(4, "Komang ") << endl;
    cout << endl << endl << a.substr(0,8) << endl;
    cout << a.size() << endl;
    while(a.find('e')<100){
        a.insert(a.find('e'), "\n");
        a.erase(a.find('e'),1);
    }
    cout << a;
    cout << a.insert(4, "Komang ") << endl;
    a="Pak Dengklek";
    cout << a + " Bertani" << endl;
    a="Pak Dengklek";
    cout << a.erase(2,4) << endl;
    a="PAK DENGKLEK";
    for(int p=0;p<a.size();p++){
        a[p]-='A'-'a';
    }
    cout << a;

}
