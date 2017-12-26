#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    string stolb;
    string cinn;
    string sdvig;
    getline(cin, cinn);
    cin.clear();
    int k=0;
    while (cinn[k] != ',') {
        str = str + cinn[k];
        k++;
    }
    k++;
    for (int i = k; i < cinn.length(); i++) {
        stolb = stolb + cinn[i];
    }
    k=0;
    if (stolb == "") {
        cout << "An error while reading" << endl;
    } else {
        cinn="";
        int flag=1;
        int stolb_int, str_int;
        stolb_int = atoi(stolb.c_str());
        str_int = atoi(str.c_str());
        string **array;
        array= new string *[str_int];
        for (int i=0; i<str_int; i++) array[i]= new string [stolb_int];
        for (int i=0; i<str_int; i++) {
            for (int j=0; j<stolb_int; j++)
                array[i][j]= "";
        }
        for (int i=0; i<str_int; i++) {
            getline (cin, cinn);
            cin.clear();
            cinn= cinn+' ';
            if (cinn.length() < (2 * stolb_int)) {
                flag=0;
                break;
            }
            for (int j=0; j<stolb_int; j++) {
                while (cinn[k]!=' ') {
                    array[i][j] =  array[i][j] + cinn[k];
                    k++;
                }
                k++;
            }
            k=0;
        }
        if (flag==0) cout << "An error while reading" << endl;
        else {
            cin.clear();
            cin>> sdvig;
            int curr_kvadr=1;
            string array1;
            int length_int=0;
            int z=0;
            string part2, part1;
            int kvadr;
            if ((str_int % 2) == 0) {
                kvadr = str_int / 2;
            } else
                kvadr = (str_int / 2) + 1;
            while (curr_kvadr != (kvadr + 1)) {
                for (int i = (curr_kvadr - 1); i < (stolb_int - curr_kvadr + 1); i++) {
                    array1= array1 + array[curr_kvadr - 1][i]+' ';
                    length_int++;
                }
                for (int i = curr_kvadr; i < (str_int - curr_kvadr + 1); i++) {
                    array1=array1+array[i][stolb_int - curr_kvadr]+' ';
                    length_int++;
                }
                for (int i = (stolb_int - curr_kvadr - 1); i > (curr_kvadr - 2); i--) {
                    array1 = array1 + array[str_int - curr_kvadr][i]+ ' ';
                    length_int++;
                }
                for (int i = (str_int - curr_kvadr - 1); i > (curr_kvadr - 1); i--) {
                    array1 = array1 + array[i][curr_kvadr - 1]+ ' ';
                    length_int++;
                }
                if ((length_int- atoi(sdvig.c_str()))<=0) part1 = array1;
                else {
                    while (k != (length_int - atoi(sdvig.c_str()))) {
                        part2 = part2 + array1[z];
                        if (array1[z] == ' ') k++;
                        z++;
                    }
                    for (int i = part2.length(); i < (array1.length()-1); i++) {
                        part1 = part1 + array1[i];
                    }
                }
                k=0;
                array1= part1+' '+part2+' ';
                for (int i = (curr_kvadr - 1); i < (stolb_int - curr_kvadr + 1); i++) {
                    array[curr_kvadr - 1][i] = "";
                    while ((array1[k])!=' ') {
                        array[curr_kvadr - 1][i]=
                            array[curr_kvadr - 1][i]+ array1[k];
                        k++;
                    }
                    k++;
                }
                for (int i = curr_kvadr; i < (str_int - curr_kvadr + 1); i++) {
                    array[i][stolb_int - curr_kvadr] = "";
                    while (array1[k]!=' ') {
                        array[i][stolb_int - curr_kvadr] =
                            array[i][stolb_int - curr_kvadr] + array1[k];
                        k++;
                    }
                    k++;
                }
                for (int i = (stolb_int - curr_kvadr - 1); i > (curr_kvadr - 2); i--) {
                    array[str_int - curr_kvadr][i] ="";
                    while (array1[k]!=' ') {
                        array[str_int - curr_kvadr][i]
                            = array[str_int - curr_kvadr][i] + array1[k];
                        k++;
                    }
                    k++;
                }
                for (int i = (str_int - curr_kvadr - 1); i > (curr_kvadr - 1); i--) {
                    array[i][curr_kvadr - 1]="";
                    while (array1[k]!=' ') {
                        array[i][curr_kvadr - 1] =  array[i][curr_kvadr - 1] + array1[k];
                        k++;
                    }
                    k++;
                }
                curr_kvadr++;
                array1="";
                part1="";
                part2="";
                k=0;
                z=0;
                length_int=0;
            }
            for (int i = 0; i < str_int; i++) {
                for (int j = 0; j < stolb_int; j++) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }

        }
    }
}
