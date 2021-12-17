#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int weights[12] = {0};

int main(int argc, char *argv[]) {
    //Maximum number of students
    const int maxStudents = 20;
    //Maximum number of assignments
    const int maxAssignments = 10;
    //Course code is first argument and is required
    string courseCode = argv[1];
    //default number of assignments if no second argument 
    int n = 5;
    int maxMarks[12] = {0};
    int overallweights[12] = {0};
    string studentIds [maxStudents] = {""};
    string invalidIds [50]= {""};
    int studentMarks[maxStudents] = {0};
    //determines if the optional second argument exists
    if (argc == 3){
        istringstream ss1{argv[2]};
        ss1 >> n;
    }
    //Adds the Midterm and Final Exam to the assignment
    n = n + 2;
    for (int i = 0; i < n; i++){
        cin >> maxMarks[i];
        cin >> overallweights[i];
        }
string line;
int invalid = 0;
int valid = 0;
bool validity;
int columns;
cin.ignore();
int totalMarks = 0;


while (getline(cin, line)) {
    for(int i = 0; i < n;i++){
        weights[i] = overallweights[i];
    }
    validity = true;
    int totalMarks = 0;
    string userId;
    int cols = 0;
    istringstream ss2{line};
    istringstream ss1{line};
    istringstream marks{line};
    string store;
    string compare;
    int tempMark = 0;
    columns = 0;
    int counts_cols = 0;
    string student;
    int num = n - 2;
    
    while(getline(ss1, compare,' ')){
            if (columns == 0){
            ostringstream temp;
            temp << compare;
            userId = temp.str();
            }
            columns++;
        }
        int m = n + 1;
    if (columns == m) {
        int counter = 0;
        int k = 0; 
    while(getline(ss2, store, ' ')) {   
                if (!validity){
                    break;
                }
                istringstream row { store };
                int x;
                string acco;
                if (row >> x) {
                    if (x > maxMarks[counter - 1] || x < 0){
                        invalidIds[invalid] = userId;
                        ++invalid;
                        validity = false;
                        break;
                    } else {
                        
                        tempMark = tempMark + ((weights[counter - 1] * x) / maxMarks[counter - 1]);
                        validity = true;
                    }
                }
                else if (store == "ACC"){
                        if (counter - num >= 1 ) {
                            invalidIds[invalid] = userId;
                        ++invalid;
                        validity = false;
                        break;
                        }
                    if (counter == num){
                        weights[counter + 1] += weights [counter - 1];

                    } else {
                        for (int l = counter; l < num - 1; l++) {
                            weights[l] += (weights[counter - 1] / (num - counter));
                        }
                        weights[num - 1] += ((weights[counter - 1] / (num - counter)) + (weights[counter - 1] % (num - counter)));
                    }
            }
            else{
                if(store != "" && counter != 0){
                    invalidIds[invalid] = userId;
                        ++invalid;
                        validity = false;

                }
            }
                ++counter;
                ++k;
    } 
        if (validity){
            studentIds[valid] = userId;
            studentMarks[valid] = tempMark;
            totalMarks = totalMarks + tempMark;
            ++valid;
            }
        ++cols;
    }
     else {
        invalidIds[invalid] = userId;
        ++invalid;
        validity = false;
    }
}
cout << courseCode << endl;
for (int i = 0 ; i < invalid; i++){
    if(invalidIds[i] != ""){
    cout << invalidIds[i] << " invalid" << endl;
    }
}
cout << "Valid records: " << valid << endl;
for (int i = 0 ; i < valid; i++){
    cout << studentIds[i] << " " << studentMarks[i] << endl;
    totalMarks = totalMarks + studentMarks[i];

}
if (valid == 0){
    cout << "Average: " << 0 << endl; 

}
else {
cout << "Average: " << totalMarks / valid << endl; 
}
}


