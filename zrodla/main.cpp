#include <iostream>
#include <string>
#include <windows.h>

int main(int argc, char* argv[]) {
	// definicja prototypu wskaznika do funkcji zwracajacej dlugosc stringa
	typedef unsigned int(*stringLength) (std::string);

	/*
		pathToDll - sciezka do biblioteki
		receivedString - string pobierany ze standardowego wejscia
		dllHandle - uchwyt do biblioteki
	*/
	std::string pathToDll, receivedString;
	HINSTANCE dllHandle = NULL;

	// sprawdz czy sciezka do DLL i string podane jako argumenty
	if(argc != 3) { // jesli nie - popros o podanie
		std::cout << "Podaj sciezke do DLL: ";
		std::cin >> pathToDll;
		std::cout << "Podaj slowo, ktorego dlugosc chcesz poznac: ";
		std::cin >> receivedString;
	} else { // jesli tak - wpisz do odpowiednich zmiennych
		pathToDll = argv[1];
		receivedString = argv[2];
	}

	// zaladuj biblioteke
	dllHandle = LoadLibrary(std::wstring(pathToDll.begin(), pathToDll.end()).c_str()); // przekonwertuj sciezke ze stringa na LPCWSTR
	// sprawdz poprawnosc zaladowania biblioteki
	if(dllHandle != NULL) { // jesli ok 
		// przypisz funkcje do wskaznika
		stringLength stringLengthPtr = (stringLength)GetProcAddress(dllHandle, "stringLength");
		
		// sprawdz przypisanie
		if(stringLengthPtr != NULL) { // jesli ok, to podaj dlugosc slowa
			std::cout << "Dlugosc podanego slowa: " << stringLengthPtr(receivedString) << std::endl;
		} else { // jesli nie, to wyswietl komunikat
			std::cout << "Blad przypisywania wskaznika" << std::endl;
		}

		// zwolnij biblioteke
		FreeLibrary(dllHandle);
		dllHandle = NULL;
	} else { // jesli blad - wyswietl komunikat
		std::cout << "Nie udalo sie zaladowac biblioteki." << std::endl;
	}

	return 0;
}