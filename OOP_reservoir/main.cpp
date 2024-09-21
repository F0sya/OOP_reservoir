#include <iostream>
#include <string>
using namespace std;

class Reservoir {
private:
	string _name, _type;
	double _width, _length, _depth;
public:
	Reservoir() {
		_name = "";
		_type = "";
		_width = 0;
		_length = 0;
		_depth = 0;
	}
	explicit Reservoir(string name, string type, double width, double length, double depth) {
		_type = type;
		_name = name;
		_width = width;
		_length = length;
		_depth = depth;
	}

	 Reservoir(const Reservoir& other) {
		_name = other._name;
		_type = other._type;
		_width = other._width;
		_length = other._length;
		_depth = other._depth;
	}
	// length, width and depth in kilometres

	double GetVolume() {
		return (_width * _length * _depth);
	}

	double GetArea() {
		return (_width * _length);
	}

	string GetName() {
		return _name;
	}
	string GetType() {
		return _type;
	}
	double GetWidth() {
		return _width;
	}
	double GetLength() {
		return _length;
	}
	double GetDepth() {
		return _depth;
	}
	void SetName(string name) {
		_name = name;
	}
	void SetType(string type) {
		_type = type;
	}
	void SetDepth(double depth) {
		_depth = depth;
	}
	void SetLength(double length) {
		_length = length;
	}
	void SetWidth(double width) {
		_width = width;
	}

	void PrintInfo() {
		cout << "Name: " <<  _name << endl;
		cout << "Type: " << _type << endl;
		cout << "Width: " << _width << endl;
		cout << "Length: " << _length << endl;
		cout << "Depth: " << _depth << endl;
	}
};

class List {
private:
	Reservoir* _reservoirs;
	int _reservoirsCount;
public:
	List() {
		_reservoirs = nullptr;
		_reservoirsCount = 0;
	}
	explicit List(Reservoir* reservoirs, int reservoirsCount) {
		_reservoirs = reservoirs;
		_reservoirsCount = reservoirsCount;
	}

	int getReservoirsCount(){
		return _reservoirsCount;
	}
	
	void AddReservoir(Reservoir reservoir) {
		Reservoir* newReservoir = new Reservoir[_reservoirsCount + 1];

		for (int i = 0; i < _reservoirsCount; i++) {
			newReservoir[i] = _reservoirs[i];
		}
		newReservoir[_reservoirsCount] = reservoir;
		_reservoirsCount++;
		delete[] _reservoirs;
		_reservoirs = newReservoir;
	}

	void RemoveReservoirByName(string target) {
		Reservoir* newReservoir = new Reservoir[_reservoirsCount - 1];
		int index = NULL;
		for (int i = 0; i < _reservoirsCount; i++) {
			if (_reservoirs[i].GetName() == target) {
				index = i;
			}
		}
		if (index != NULL) {
			for (int i = 0; i < index; i++) {
				newReservoir[i] = _reservoirs[i];
			}
			for (int i = index + 1; i < _reservoirsCount; i++) {
				newReservoir[i - 1] = _reservoirs[i];
			}
			_reservoirsCount--;
			delete[] _reservoirs;
			_reservoirs = newReservoir;
			cout << "\n---------------------------\n";
			cout << "Removed" << target << endl;
			cout << "\n---------------------------\n";
		}
		else {
			cout << "No occurencies";
		}

	}

	void CompareTypes(string name1, string name2) {
		int index1 = NULL;
		int index2 = NULL;
		for (int i = 0; i < _reservoirsCount; i++) {
			if (_reservoirs[i].GetName() == name1) {
				index1 = i;
			}
			if (_reservoirs[i].GetName() == name2) {
				index2 = i;
			}
		}
		cout << "\n---------------------------\n";
		
		cout << "Comparing Result: ";
		(_reservoirs[index1].GetType() == _reservoirs[index2].GetType()) ? cout << "Similar types" : cout << "Different types"; cout << "\n\n";
		cout << "First object has type: " << _reservoirs[index1].GetType() << endl;
		cout << "Second object has type: " << _reservoirs[index2].GetType() << endl;
		cout << "\n---------------------------\n";
	}

	void CompareAreas(string name1, string name2) {
		int index1 = NULL;
		int index2 = NULL;
		for (int i = 0; i < _reservoirsCount; i++) {
			if (_reservoirs[i].GetName() == name1) {
				index1 = i;
			}
			if (_reservoirs[i].GetName() == name2) {
				index2 = i;
			}
		}
		if (_reservoirs[index1].GetType() == _reservoirs[index2].GetType()) {
			cout << "\n---------------------------\n";

			cout << "Comparing Result: ";
			if (_reservoirs[index1].GetArea() > _reservoirs[index2].GetArea()) {
				cout << _reservoirs[index1].GetName() << " area" << " > " << _reservoirs[index2].GetName() << " area" << endl;
			}
			else if(_reservoirs[index1].GetArea() == _reservoirs[index2].GetArea()) {
				cout << _reservoirs[index1].GetName() << " area" << " = " << _reservoirs[index2].GetName() << " area" << endl;
			}
			else {
				cout << _reservoirs[index1].GetName() << " area" << " < " << _reservoirs[index2].GetName() << " area" << endl;
			}
			cout << "First object has area: " << _reservoirs[index1].GetArea() << "sq.km" << endl;
			cout << "Second object has area: " << _reservoirs[index2].GetArea() << "sq.km" << endl;
			cout << "\n---------------------------\n";
		}
		else {
			cout << "\n---------------------------\n";
			cout << "Can't be compared because has different types";
			cout << "\n---------------------------\n";
		}
	}

	void Print() const {
		cout << "\n---------------------------\n";
		for (int i = 0; i < _reservoirsCount; i++) {
			cout << "Reservoir " << i + 1 << ":" << endl;
			_reservoirs[i].PrintInfo();
			cout << endl;
		}
		cout << "\n---------------------------\n";
	}

	void Copy(string name) {
		int index = NULL;
		for (int i = 0; i < _reservoirsCount; i++) {
			if (_reservoirs[i].GetName() == name) {
				index = i;
			}
		}
		AddReservoir(Reservoir::Reservoir(_reservoirs[index].GetName(), _reservoirs[index].GetType(), _reservoirs[index].GetWidth(), _reservoirs[index].GetLength(), _reservoirs[index].GetDepth()));
	}

};


int main() {
	int choice;
	List list;
	Reservoir reservoir1("Indian", "Ocean", 17.5, 18.5, 20.5);
	Reservoir reservoir2("Calm", "Ocean", 17.5, 18.5, 20.5);
	Reservoir reservoir3("Atlantic", "Ocean", 17.5, 18.5, 20.5);
	Reservoir reservoir4("Dnipro", "Ocean", 20, 18.5, 20.5);

	list.AddReservoir(reservoir1);
	list.AddReservoir(reservoir2);
	list.AddReservoir(reservoir3);
	list.AddReservoir(reservoir4);

	while (true) {
		cout << "\n----------MENU------------\n";
		cout << "1.Show the list of reservoirs" << endl;
		cout << "2.Add new reservoir to list" << endl;
		cout << "3.Remove reservoir from list" << endl;
		cout << "4.Compare reservoirs by type" << endl;
		cout << "5.Compare areas of similar type reservoirs" << endl;
		cout << "6.Duplicate reservoirs by name" << endl;
		cout << "\n----------MENU------------\n";

		cin >> choice;

		cin.ignore();

		switch (choice) {
		case 1:
			list.Print();
			break;
		case 2: {
			string name, type;
			double width, length, depth;
			cout << "Enter a name: " << endl;
			getline(cin, name);
			cout << "Enter a type: " << endl;
			getline(cin, type);
			cout << "Enter a width in km: " << endl; cin >> width;
			cout << "Enter a length in km: " << endl; cin >> length;
			cout << "Enter a depth in km: " << endl; cin >> depth;
			Reservoir newReservoir(name, type, width, length, depth);
			list.AddReservoir(newReservoir);
			break;
		}
		case 3: {
			string name;
			cout << "Enter a name to remove: ";
			getline(cin, name);
			list.RemoveReservoirByName(name);
		}
		case 4: {
			string name1, name2;
			cout << "Enter a first name to compare types: ";
			getline(cin, name1);
			cout << "Enter a second name to compare types: ";
			getline(cin, name2);
			list.CompareTypes(name1, name2);
		}
		case 5: {
			string name1, name2;
			cout << "Enter a first name to compare areas: ";
			getline(cin, name1);
			cout << "Enter a second name to compare areas: ";
			getline(cin, name2);
			list.CompareAreas(name1, name2);
		}
		case 6: {
			string name;
			cout << "Enter a name of reservoir you wanna copy: ";
			getline(cin, name);
			list.Copy(name);
		}
		}
	}

	return 0;
}