#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int estaciones[] = {580,980,1190,1250,1420};
    int frecuencia;
    cin >> frecuencia;
    if(frecuencia < 540 || frecuencia > 1520) cout << "error\n";
    else {
    	if(frecuencia < 580) {
    		cout << "adelante " << 580-frecuencia << "\n";
    	}
    	else if(frecuencia > 1420) {
    		cout << "atras " << frecuencia-1420 << "\n";
    	} else {
    		int i;
	    	for(i=0;i<4;i++) {
	    		if(frecuencia >= estaciones[i] && frecuencia <= estaciones[i+1]) {
	    			break;
	    		}
	    	}
	    	i++;
	    	int atras = abs(estaciones[i-1] - frecuencia);
	    	int adelante = abs(estaciones[i] - frecuencia);
	    	if(adelante <= atras) cout << "adelante " << adelante << "\n";
	    	else cout << "atras " << atras << "\n";
    	}
    }
}
