#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void save_vector(vector<int>vec, string filename) {
	ofstream file(filename, ios::binary);
	
	size_t element_count = vec.size();
	file.write(reinterpret_cast<const char*>(&element_count), sizeof(element_count));

	for (auto& element : vec) {
		file.write(reinterpret_cast<const char*>(&element), sizeof(element));
	}
	file.close();

	cout << filename + " was saved successfully!" << endl;
}

vector<int> load_vector(string filename) {
	ifstream file(filename, ios::binary);

	if (!file) {
		cout << filename + " was not found :(";
	}
	else {
		vector<int>vec;

		size_t element_count;

		file.read(reinterpret_cast<char*>(&element_count), sizeof(element_count));

		for (size_t i{0}; i < element_count; i++) {
			int element;

			file.read(reinterpret_cast<char*>(&element), sizeof(element));

			vec.push_back(element);
		}

		cout << filename + " was loaded successfully!" << endl;

		return vec;
	}
}

int main() {
	vector<int>numbers;
	int a = 10;
	int b = 20;
	int c = 30;

	numbers.push_back(a);
	numbers.push_back(b);
	numbers.push_back(c);

	save_vector(numbers, "numbers.bin");

	vector<int>same_numbers;

	same_numbers = load_vector("numbers.bin");

	for (size_t i{ 0 }; i < same_numbers.size(); i++) {
		cout << same_numbers[i] << endl;
	}
}
