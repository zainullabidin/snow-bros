
// Minahil

#include"../../include/DB/Data_base.h"
#include <iostream>

// constructor
Data_base::Data_base(int cap) : count(0), capacity(cap) {
    lines = new string[cap];
}

// destructor
Data_base::~Data_base() {
    clear();
    delete[] lines;
    lines = nullptr;
}



//getters
string Data_base::getLine(int index) const {
    if (index < 0 || index >= count) 
        return "";
    return lines[index];
}

int Data_base::getCount() const {
    return count;
}

int Data_base::getCapacity() const {
    return capacity;
}


// setetrs
void Data_base::setCount(int Count) {
    count = Count;
}
void Data_base::setCapacity(int Capacity) {
    capacity = Capacity;
}

// replaces lines or sets lines at index
void Data_base::setLine(int index, const string& line) {
    if (index < 0 || index >= capacity)  // check capacity, not count
        return;
    lines[index] = line;
}

// doubling the capacity to make the sys flexible
void Data_base::resize() {
    capacity *= 2;

    // created a new array with double capacity and stored previous vals
    string *newLines = new string[capacity];
    for (int i = 0; i < count; i++) {
        newLines[i] = lines[i];
    }
    delete[] lines;
    lines = nullptr;
    lines = newLines;
}

void Data_base::readAllLines(const string& filename) {
    clear();
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Error while opening file: " << filename;
        return;
    }

    // skip empty lines and if capacity finishes, add more space
    string line;
    while (getline(file, line)) {       // getline -> returns false if end of file
        if (line.empty())
            continue;

        if (count >= capacity)
            resize();

        lines[count++] = line;
    }
    file.close();
}

void Data_base::writeAllLines(const string& filename) {
    ofstream out;
    out.open(filename);

    if (!out) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < count; i++)
        out << lines[i] << "\n";

    out.close();
}

void Data_base::appendLine(const string& filename, const string& line) {
    
    // Add to current memory 
    if (count >= capacity) resize();
    lines[count++] = line;          // ← ADD THIS

    
    ofstream out;
    out.open(filename, ios::app);   // only writes at end of line

    if (!out) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    out << line << "\n";
    out.close();
}

// ifstraem -> only for reading
bool Data_base::fileExists(const string& filename) {
    ifstream file;
    file.open(filename);

    if (!file.is_open())
        return false;

    file.close();
    return true;
}

// ofstream -> writing + making
void Data_base::createFileIfMissing(const string& filename) {
    if (!fileExists(filename)) {
        ofstream file;
        file.open(filename);
        file.close();
    }
}

// resets the count, so that if we read a new file, it doesn't take the previous count value
void Data_base::clear() {
    count = 0;
}

// free split string function for file data reading
void splitstring(string line, char delimeter, string parts[], int &partCount){
    partCount = 0;
    string current = "";

    for(int i = 0 ; i < line.size(); i++){
        // if no | -> keep storing occuring values
        if(line[i] != delimeter) {
            current += line[i];
        }

        // if | -> store the current value in parts array and reset current value
        else {
            parts[partCount++] = current;
            current = "";
        }
    }

    // to add last val also 
    if(!current.empty())
        parts[partCount++] = current;
}