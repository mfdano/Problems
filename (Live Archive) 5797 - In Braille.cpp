#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main() {
    map <string,int> braile;
    map <int,string> decimal;
    braile["*....."] = 1;
    braile["*.*..."] = 2;
    braile["**...."] = 3;
    braile["**.*.."] = 4;
    braile["*..*.."] = 5;
    braile["***..."] = 6;
    braile["****.."] = 7;
    braile["*.**.."] = 8;
    braile[".**..."] = 9;
    braile[".***.."] = 0;
    decimal[1] = "*....."; 
    decimal[2] = "*.*..."; 
    decimal[3] = "**...."; 
    decimal[4] = "**.*.."; 
    decimal[5] = "*..*.."; 
    decimal[6] = "***..."; 
    decimal[7] = "****.."; 
    decimal[8] = "*.**.."; 
    decimal[9] = ".**..."; 
    decimal[0] = ".***.."; 
    int numberDigits,size,idx;
    char option;
    string row1,row2,row3;
    string braileDigits[105];
    while(scanf("%d",&numberDigits) != EOF) {
            if(numberDigits == 0) break;
            scanf(" %c",&option);
            if(option == 'S') {
                    getline(cin,row1);
                    getline(cin,row1);
                    size = row1.size();
                    for(int i=0;i<size;i++) {
                        printf("%c",decimal[row1[i] - '0'][0]);
                        printf("%c",decimal[row1[i] - '0'][1]);
                        if(i != size-1) printf(" ");
                        else printf("\n");
                   }
                   for(int i=0;i<size;i++) {
                        printf("%c",decimal[row1[i] - '0'][2]);
                        printf("%c",decimal[row1[i] - '0'][3]);
                        if(i != size-1) printf(" ");
                        else printf("\n");
                   }
                   for(int i=0;i<size;i++) {
                        printf("%c",decimal[row1[i] - '0'][4]);
                        printf("%c",decimal[row1[i] - '0'][5]);
                        if(i != size-1) printf(" ");
                        else printf("\n");
                   }
            } else {
                    getline(cin,row1);
                    getline(cin,row1);
                    getline(cin,row2);
                    getline(cin,row3);
                    size = row1.size();
                    idx = 0;
                    for(int i=0;i<size;i+=3) {
                        braileDigits[idx] = "\0";
                        braileDigits[idx] += (row1[i]);
                        braileDigits[idx] += (row1[i+1]);
                        braileDigits[idx] += (row2[i]);
                        braileDigits[idx] += (row2[i+1]);
                        braileDigits[idx] += (row3[i]);
                        braileDigits[idx] += (row3[i+1]);
                        idx++;
                    }
                    for(int i=0;i<idx;i++) printf("%d",braile[braileDigits[i]]); 
                    printf("\n");
            }
    }
    return 0;
}
