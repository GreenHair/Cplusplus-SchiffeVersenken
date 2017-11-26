#include <iostream>
#include <windows.h> // Damit es beep macht
#include <future> // Damit die Musik "nebenher" abspielt

using namespace std;

void musik(){

	Beep(0,500); // Kleine Pause beim Start, damit er sich nicht verschluckt :-)
	
	Beep(311.127,950);
	Beep(293.665,350);
	Beep(261.626,350);
	Beep(293.665,350);
	Beep(311.127,350);
	Beep(391.995,350);
	Beep(466.164,950);
	
	Beep(440.000,350);
	Beep(391.995,350);
	Beep(440.000,350);
	Beep(466.164,350);
	Beep(587.330,350);
	Beep(698.456,1600);
	
	Beep(0,500);
	
	Beep(349.228,950);
	Beep(329.628,350);
	Beep(293.665,350);
	Beep(329.628,350);
	Beep(349.228,350);
	Beep(440.000,350);
	Beep(523.251,950);
	
	Beep(493.883,350);
	Beep(440.000,350);
	Beep(493.883,350);
	Beep(523.251,350);
	Beep(659.255,350);
	Beep(783.991,1600);
}

int main(int argc, char** argv) {

// Wird die Musik in das Schiffeversenken-Spiel eingebaut, sollte sie parallel zum Rest laufen, damit man am Anfang nicht so lange warten muss.
// Dann einfach musik() auskommentieren und den Kommentar aus der Zeile
//	auto f = std::async(std::launch::async, musik);
// wegnehmen. Die Zeile cout << "Hier spielt die Musik" << endl; wird dann angezeigt, während die Musik spielt.
	musik();

	cout << "Hier spielt die Musik" << endl;

	system("Pause");
	return 0;
}
