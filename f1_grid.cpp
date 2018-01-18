#include <iostream>
using namespace std;

int nd = 18;

struct drivers {
	string name [18];
	int no [18];
	float time [18];
	int gridpos [18];
};

void placeGrid (drivers &d) {
    for(int a = 0;a < nd ;a++){
        for(int i = 0 ;i < nd-1 ;i++){
            if(d.time[i] > d.time[i+1]){
                    float var = 0;
                    var = d.time[i+1];
                    d.time[i+1] = d.time[i];
                    d.time[i] = var;

                    string var2;
                    var2 = d.name[i+1];
                    d.name[i+1] = d.name[i];
                    d.name[i] = var2;

                    var = d.no[i+1];
                    d.no[i+1] = d.no[i];
                    d.no[i] = var;


            }
        }
    }
}

void drawGrid (drivers &d) {
    for(int i = 0 ;i < nd ;i++){
        for(int a = 0 ;a < 3 ;a++){
			d.gridpos[i] =i+1;
			switch(a){
			    case 0:
				    cout << d.gridpos[i] << endl << "-----------------------";
                    break;
				case 1:
				    cout << d.no[i];
                    break;
				case 2:
				    cout << d.name[i];
                    break;
			}
        cout << endl;
        }
    cout << endl;
    }
}


int main(){
	cout << "Register drivers\n";
	drivers D;

	for (int i = 0; i < nd; i++) {
        cout << "\nDriver no. " << i+1;
        cout << "\nEnter driver name: ";
        cin >> D.name[i];
        cout << "Enter car no.: ";
        cin >> D.no[i];
        cout << "Enter lap time: ";
        cin >> D.time[i];
	}

	placeGrid(D);
	drawGrid(D);

	return 0;

}
