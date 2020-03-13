#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
namespace fs = std::filesystem;



struct vivod
{
	char date [20];
	char value[5];
	char sek[2];
};

int main() {
	while (true)
	{
		int helper = 0;
		int amount_of_elements = 0;
		std::string pp;  

		std::cout << "Enter device : "; std::cin >> pp;
		std::cout << std::endl;


		for (auto& p : fs::directory_iterator("logs")) {
			amount_of_elements++;


		}

		/////////////
		//
		//////////
		vivod* win = new vivod[amount_of_elements];
		
		if (pp[0] == '\0' || pp[0] == '1' || pp[0] == '2' || pp[0] == '3' || pp[0] == '4' || pp[0] == '5' || pp[0] == '6' || pp[0] == '7' || pp[0] == '8' || pp[0] == '9' || pp[0] == '0' || pp[0] == '\n') {



		}
		else {



			
			int counter = 0;



			for (auto& p : fs::directory_iterator("logs")) {


				std::string oo = p.path().string();
				int s = 10;
				for (int i = 0; i < 16; i++) {
					win[counter].date[i] = oo[s];
					s++;
				}
				win[counter].date[16] = '\0';





				std::ifstream file(p.path());
				while (file) {
					std::string pp1;
					getline(file, pp1);
					win[counter].sek[0] = pp1[0];
					win[counter].sek[1] = '\0';
					if (pp1[0] == 32 || pp1[0] == '\0') {

					}
					else {
						int trriger = 0;
						int pokaz = 0;

						for (int i = 0; i < 40; i++) {
							if (pp1[i] == 58) {
								trriger++;
							}
							else if (trriger == 1 || trriger == 2) {
								if (trriger == 2) {
									int ee = pp1.size() - i;
									
									for (int r = 0; r < ee; r++) {
										win[counter].value[r] = pp1[i + r];
									}
									win[counter].value[ee] = '\0';
									helper = 1;
									//std::cout << pp1 << std::endl;  // пометка вина
									counter++;
									break;
								}
								else {
									if (pp1[i] == pp[pokaz]) {

										
									}
									else if (pp1[i] != pp[pokaz]) {
										break;
									}
									
									pokaz++;
								}

							}
						}
					}

				}
				file.close();
				
			}
		}


		if (helper == 1) {
			std::cout << " date/time \t \t value" << std::endl;
			std::cout << std::endl;

			for (int i = 0; i < amount_of_elements; i++) {
				std::cout << win[i].date  << ":" << win[i].sek << "\t" << win[i].value << std::endl;

			}
		}
		else {
			std::cout << "device not found" << std::endl;
		}


	}


	/*delete [] win;*/
	return 0;
}
