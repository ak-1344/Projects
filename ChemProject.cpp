/*
This project is made as a team project for chemistry.
Team members:
ANSHIKA JAIN 	23BCE1445
SONALI 		    23BCE1572
ADITYA 		    23BCE1344
ARJUN DEVRAJ	23BCE1409
ESHITA GUPTA	23BCE1326
*/

//Header Files
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;

//Basic funtions used
void clearLine() {
    cout << "\033[2K"; // Clears the entire line
    cout << "\033[A";  // Moves cursor up one line
}
void delay(int sec){
    Sleep(sec * 1000);
}
void timer(int a){
    for(int i=a;i>0;i--){
        cout<<endl<<i;
        delay(1);
        clearLine();
    }
}
void instructions(){
    system("cls");
    cout<<endl;
    cout<<"Welcome to the \"KineticSolver: A C++ Based Computational Tool for Chemical Kinetics Analysis\"\n";
    cout<<"This program help you to solve problems of chemical kinetics easily with the help of preprogrmmed attributes.\n";
    cout<<"Please follow all the instruction carefully and input correct values for fluent processing.";
    cout<<endl<<endl;
    for(int i=15;i>0;i--){
        clearLine();
        cout<<"\nThe program will run in "<<i<<" sec";
        delay(1);
        
    }
}
void end(){
    system("cls");
    cout<<endl<<endl;
    cout<<"Program terminated!!"<<endl;
    cout<<"Thank you for using KineticSolver: A C++ Based Computational Tool for Chemical Kinetics Analysis";
    delay(100);
}

/*(First order reaction functions)*/
// Function to calculate rate constant (k)
double calculateRateConstant(int formula) {
    double k = 0.0;
    double Ci, Cf, x, Pi, Pf, T, T_half, n, Ai;

    switch (formula) {
        case 1: // k = ln(Ci/Cf) / T
            {
            cout << "Enter initial concentration (Ci): ";
            cin >> Ci;
            cout << "Enter final concentration (Cf): ";
            cin >> Cf;
            cout << "Enter time (T): ";
            cin >> T;
            if(Ci>Cf){
            k = log(Ci / Cf) / T;
            }
            else{
                cout<<"Invalid Input\nRerun the program\n";
            }
            break;
            }
        case 2: // k = ln(100 / (100 - x)) / T
            {
            cout << "Enter percentage of reactants consumed (x): ";
            cin >> x;
            cout << "Enter time (T): ";
            cin >> T;
            k = log(100.0 / (100.0 - x)) / T;
            break;
            }
        case 3: // k = ln(1 / (1 - x)) / T
            {
            cout << "Enter fraction of reactants consumed (x): ";
            cin >> x;
            cout << "Enter time (T): ";
            cin >> T;
            k = log(1.0 / (1.0 - x)) / T;
            break;
            }
        case 4: // k = ln(Pi/Pf) / T
            {
            cout << "Enter initial pressure (Pi): ";
            cin >> Pi;
            cout << "Enter final pressure (Pf): ";
            cin >> Pf;
            cout << "Enter time (T): ";
            cin >> T;
            if(Pi>Pf){
            k = log(Pi / Pf) / T;
            }
            else{
                cout<<"Invalid Input\nRerun the program\n";
            }
            break;
            }
        case 5: // k = 0.693 / T_half
            {
            cout << "Enter half life of reaction (T_half): ";
            cin >> T_half;
            k = 0.693 / T_half;
            break;
            }
        default:
            cout << "Invalid option!";
            break;
    }
    return k;
}
// Function to calculate total time (T)
double calculateTotalTime(int formula, double k) {
    double T = 0.0;
    double Ci, Cf, x, Pi, Pf, T_half, n;

    switch (formula) {
        case 1: // T = ln(Ci/Cf) / k
            cout << "Enter initial concentration (Ci): ";
            cin >> Ci;
            cout << "Enter final concentration (Cf): ";
            cin >> Cf;
            if(Ci>Cf){
            T = log(Ci / Cf) / k;
            }
            else{
                cout<<"Invalid Input\nRerun the program\n";
            }
            break;
        case 2: // T = ln(100 / (100 - x)) / k
            cout << "Enter percentage of reactants consumed (x): ";
            cin >> x;
            
            T = log(100.0 / (100.0 - x)) / k;
            break;
        case 3: // T = ln(1 / (1 - x)) / k
            cout << "Enter fraction of reactants consumed (x): ";
            cin >> x;
            T = log(1.0 / (1.0 - x)) / k;
            break;
        case 4: // T = ln(Pi/Pf) / k
            cout << "Enter initial pressure (Pi): ";
            cin >> Pi;
            cout << "Enter final pressure (Pf): ";
            cin >> Pf;
            if(Pi>Pf){
            T = log(Pi / Pf) / k;
            }
            else{
                cout<<"Invalid Input\nRerun the program\n";
            }
            break;
        case 5: // T = 0.693 / k
            cout << "Enter number of half life cycles (n): ";
            cin >> n;
            T = 0.693 / (k * n);
            break;
        default:
            cout << "Invalid option!";
            break;
    }

    return T;
}
// Function to calculate half life of reaction (T_half)
double calculateHalfLife(double k) {
    double T_half = 0.0;
    
    T_half = 0.693 / k;
    
    return T_half;
}
// Function to calculate rate of reaction (R)
double calculateRateOfReaction(double k, double Ai) {
    double R = 0.0;

    R = k * pow(Ai, 1);
    
    return R;
}

/*(Arhenius equation functions)*/
// Function to calculate the rate constant (k)
double calculateRateConstant(double A, double Ea, double R, double T) {
    return A * exp(-Ea / (R * T));
}
// Function to calculate the activation energy (Ea)
double calculateActivationEnergy(double k, double A, double R, double T) {
    return (-R * T * log(k / A));
}
// Function to calculate the temperature (T) in the Arrhenius equation
double calculateTemperature(double k, double A, double Ea, double R) {
    return (-Ea / (R * log(k / A)));
}
// Function to calculate the pre-exponential factor (A)
double calculatePreExponentialFactor(double k, double Ea, double R, double T) {
    return (k / exp(-Ea / (R * T)));
}

/*(Temp dependecy)*/
double find_k(double half_time){
    return log(2)/half_time;
}


//zeroth order main function
void zero_order()
    {
        cout << "Please enter what you want to find?\n1.k\n2.t\n3.Initial Concentration(a0)\n4.Final Concentration(at)\n5.Time to complete the reaction\n6.Half-time of the reaction\n\nPlease enter the choice number:";
        int choice;
        cin >> choice;
        cout << "\n";

        switch (choice){
        case 1:
        {
            int n;
            cout << "Enter the set of input given\n1.t,a0,at are given\n2.t(100%) is given" << endl;
            cin >> n;
            if (n == 1)
            {
                double t, a0, at,result;
                cout << "Enter t" << endl;
                cin >> t;
                cout << "Enter a0" << endl;
                cin >> a0;
                cout << "Enter at" << endl;
                cin >> at;
                if(at<a0){
                result=(a0-at)/t;
                cout << "k = " <<result << " s^-1";
                }
                else{
                    cout<<"Invalid Input\nRerun the program";
                }
            }
            else if(n==2)
            {
                double t, a0;
                cout << "Enter time after 100% reaction is complete" << endl;
                cin >> t;
                cout << "Enter a0" << endl;
                cin >> a0;
                cout << "k = " << a0 / t << " s^-1" << endl;
            }
            else
            {
                cout<<"Invalid Input\nRerun the program\n";
            }
        }
        break;
        case 2:
        {
            double k, a0, at, result;
            cout << "Enter k" << endl;
            cin >> k;
            cout << "Enter a0" << endl;
            cin >> a0;
            cout << "Enter at" << endl;
            cin >> at;
            if(at<a0){
            result=(a0 - at) / k;
            cout << "t = " << result<< " s" << endl;
            }
            else{
                cout<<"Invalid Input\nRerun the program\n";
            }
        }
        break;
        case 3:
        {
            double k, t, at;
            cout << "Enter k" << endl;
            cin >> k;
            cout << "Enter t" << endl;
            cin >> t;
            cout << "Enter at" << endl;
            cin >> at;
            cout << "a0 = " << (k * t) + at << endl;
        }
        break;
        case 4:
        {
            double k, t, a0;
            cout << "Enter k" << endl;
            cin >> k;
            cout << "Enter t" << endl;
            cin >> t;
            cout << "Enter a0" << endl;
            cin >> a0;
            cout << "at = " << a0 - (k * t) << endl;
        }
        break;
        case 5:
        {
            double k, a0;
            cout << "Enter k" << endl;
            cin >> k;
            cout << "Enter a0" << endl;
            cin >> a0;
            cout << "After 100% reaction is complete\nt = " << a0 / k << " s" << endl;
        }
        break;
        case 6:
        {
            int n;
            cout << "Enter the set of input given\n1.a0,k \n2.t(100%)" << endl;
            cin >> n;
            if (n == 1)
            {
                double a0, k;
                cout << "Enter k" << endl;
                cin >> k;
                cout << "Enter a0" << endl;
                cin >> a0;
                cout << "Half time t = " << a0 / (2 * k) << " s\n";
            }
            else if(n==2)
            {
                double t;
                cout << "Enter time after 100% reaction is complete" << endl;
                cin >> t;
                cout << "Half time t = " << t / 2 << endl;
            }
            else
            {
                cout<<"Invalid Input\nRerun the program.\n";
            }
        }
        }
    }
//First Order main function
void first_order(){
    int k,T,T_half,R;
    int choice;
    cout << "What do you want to find?\n";
    cout << "1. Rate constant (k)\n";
    cout << "2. Total time (T)\n";
    cout << "3. Half life of reaction (T_half)\n";
    cout << "4. Rate of reaction (R)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int formula;
            cout << "Select the formula to use:\n";
            cout << "1. k = ln(Ci/Cf) / T\n";
            cout << "2. k = ln(100 / (100 - x)) / T\n";
            cout << "3. k = ln(1 / (1 - x)) / T\n";
            cout << "4. k = ln(Pi/Pf) / T\n";
            cout << "5. k = 0.693 / T_half\n";
            cout << "Enter your choice: ";
            cin >> formula;
            k = calculateRateConstant(formula);
            cout << "Rate constant (k) = " << k << endl;
            break;
        }
        case 2: {
            int formula;
            cout << "Select the formula to use:\n";
            cout << "1. T = ln(Ci/Cf) / k\n";
            cout << "2. T = ln(100 / (100 - x)) / k\n";
            cout << "3. T = ln(1 / (1 - x)) / k\n";
            cout << "4. T = ln(Pi/Pf) / k\n";
            cout << "5. T = 0.693 / (k * n)\n";
            cout << "Enter your choice: ";
            cin >> formula;
            cout << "Enter rate constant (k): ";
            cin >> k;
            T = calculateTotalTime(formula, k);
            cout << "Total time (T) = " << T << endl;
            break;
        }
        case 3: {
            double k;
            cout<<"Formula:   T_half = 0.693 / rate_constant "<<endl;
            cout << "Enter rate constant (k): ";
            cin >> k;
            T_half = calculateHalfLife(k);
            cout << "Half life of reaction (T_half) = " << T_half << endl;
            break;
        }
        case 4: {
            double k, Ai;
            cout<<"Formula:  Rate= k* initial concenteration "<<endl;
            cout << "Enter rate constant (k): ";
            cin >> k;
            cout << "Enter initial concentration (Ai): ";
            cin >> Ai;
            R = calculateRateOfReaction(k, Ai);
            cout << "Rate of reaction (R) = " << R << endl;
            break;
        }
        default:
            cout << "Invalid option!";
            break;
    }
}
//Arhenius equation main function
void Arhenius_Equation() {
    double k, A, Ea, R, T;

    // Prompt user to choose which variable to find
    int choice;
    cout << "Choose which variable you want to find:\n";
    cout << "1. Rate constant (k)\n";
    cout << "2. Pre-exponential factor (A)\n";
    cout << "3. Activation energy (Ea)\n";
    cout << "4. Temperature (T)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            // Prompt user to enter values for A, Ea, R, and T
            cout << "Enter the values:\n";
            cout << "Pre-exponential factor (A): ";
            cin >> A;
            cout << "Activation energy (Ea): ";
            cin >> Ea;
            cout << "Gas constant (R): ";
            cin >> R;
            cout << "Temperature in Kelvin (T): ";
            cin >> T;
            // Calculate and print the rate constant (k)
            cout << "Rate constant (k): " << calculateRateConstant(A, Ea, R, T) << endl;
            break;
        case 2:
            // Prompt user to enter values for k, Ea, R, and T
            cout << "Enter the values:\n";
            cout << "Rate constant (k): ";
            cin >> k;
            cout << "Activation energy (Ea): ";
            cin >> Ea;
            cout << "Gas constant (R): ";
            cin >> R;
            cout << "Temperature in Kelvin (T): ";
            cin >> T;
            // Calculate and print the pre-exponential factor (A)
            cout << "Pre-exponential factor (A): " << calculatePreExponentialFactor(k, Ea, R, T) << endl;
            break;
        case 3:
            // Prompt user to enter values for k, A, R, and T
            cout << "Enter the values:\n";
            cout << "Rate constant (k): ";
            cin >> k;
            cout << "Pre-exponential factor (A): ";
            cin >> A;
            cout << "Gas constant (R): ";
            cin >> R;
            cout << "Temperature in Kelvin (T): ";
            cin >> T;
            // Calculate and print the activation energy (Ea)
            cout << "Activation energy (Ea): " << calculateActivationEnergy(k, A, R, T) << endl;
            break;
        case 4:
            // Prompt user to enter values for k, A, Ea, and R
            cout << "Enter the values:\n";
            cout << "Rate constant (k): ";
            cin >> k;
            cout << "Pre-exponential factor (A): ";
            cin >> A;
            cout << "Activation energy (Ea): ";
            cin >> Ea;
            cout << "Gas constant (R): ";
            cin >> R;
            // Calculate and print the temperature (T)
            cout << "Temperature (T): " << calculateTemperature(k, A, Ea, R) << endl;
            break;
        default:
            cout << "Invalid choice!\n";
    }
}
//Temperature dependencies of reaction rates
double temp_dependency(){
    double k1,k2,Ea,T1,T2;
    double R=8.314462618;
    int temp;
    cout<<"INSTRUTIONS:\nPlease enter all the values only (no units), but units must be same!\nEnter temperature in Kelvin and rate constants in s^-1\n";
    cout<<"\nIf you want to enter the number 9.51 * 10^-9, enter it in this format 9.51e-9 \n\n";
    cout<<"Please enter what you want to find?\n1.k1\n2.k2\n3.Ea\n4.T1\n5.T2\nPlease enter the choice number:";
    cin>>temp;

    switch (temp)
    {
    case 1:{
        int temp1;
        cout<<"Enter the set of input given:\n1. half time of reaction 1\n2. k2,Ea,T1,T2\n3. halftime of reaction 2, Ea,T1,T2\nPlease enter the choice: ";
        cin>>temp1;

        if(temp1==1){
            cout<<"Enter the half time of reaction 1: ";
            cin>>k1;
            cout<<"The value of k1 is:"<<find_k(k1);
            break;
        }else if(temp1==3){
            cout<<"Enter the half time of reaction 2: ";
            cin>>k2;
            k2=find_k(k2);
        }else if(temp1==2){
            cout<<"Enter the value of k2: ";
            cin>>k2;
        }

        cout<<"Enter the value of Ea: "; cin>>Ea;
        cout<<"Enter the value of T1: "; cin>>T1;
        cout<<"Enter the value of T1: "; cin>>T2;

        k1 = k2/( exp(  (-Ea/R)*( (1/T2)-(1/T1) )  ) );
        cout<<"k2: "<<k2<<"s^-1" <<endl;
        cout<<"Ea: "<<Ea<<" J/mol"<<endl;
        cout<<"T1: "<<T1<<" K"<<endl;
        cout<<"T2: "<<T2<<" K"<<endl;
        cout<<"The value of k1 is "<< k1<<"s^-1";
    }
        break;
    
    case 2:
        {
        int temp1;
        cout<<"Enter the set of input given:\n1. half time of reaction 2\n2. k1,Ea,T1,T2\n3. halftime of reaction 1, Ea,T1,T2\nPlease enter the choice: ";
        cin>>temp1;

        if(temp1==1){
            cout<<"Enter the half time of reaction 2: ";
            cin>>k2;
            cout<<"The value of k2 is:"<<find_k(k2);
            break;
        }else if(temp1==3){
            cout<<"Enter the half time of reaction 1: ";
            cin>>k1;
            k2=find_k(k1);
        }else if(temp1==2){
            cout<<"Enter the value of k1: ";
            cin>>k1;
        }

        cout<<"Enter the value of Ea: "; cin>>Ea;
        cout<<"Enter the value of T1: "; cin>>T1;
        cout<<"Enter the value of T1: "; cin>>T2;

        k2 = k1*exp(  (-Ea/R)*( (1/T2)-(1/T1) )  ) ;
        cout<<"k1: "<<k1<<"s^-1" <<endl;
        cout<<"Ea: "<<Ea<<" J/mol"<<endl;
        cout<<"T1: "<<T1<<" K"<<endl;
        cout<<"T2: "<<T2<<" K"<<endl;
        cout<<"The value of k2 is "<< k2<<"s^-1";
    }
        break;
    
    case 3:
        {
            int temp1;
            cout<<"Enter the input format: \n1. Half time of both reactions, T1,T2\n2. Half time of reacton 1,k2,T1,T2\n3. k1,Half time of reaction 2,T1,T2\n4. k1,k2,T1,T2\nPlease enter your choice: ";
            cin>>temp1;

            if(temp1==1){
                cout<<"Enter the half time of reaction 1(in s): ";
                cin>>k1;
                cout<<"Enter the half time of reaction 2(in s): ";
                cin>>k2;
                k1=find_k(k1);
                k2=find_k(k2);
            }else if(temp1==2){
                cout<<"Enter the half time of reaction 1: ";
                cin>>k1;
                k1= find_k(k1);
                cout<<"Enter the value of k2: ";
                cin>>k2;
            }else if(temp1==3){
                cout<<"Enter the value of k1: ";
                cin>>k1;
                cout<<"Enter the half time of reaction 2: ";
                cin>>k2;
                k2= find_k(k2);
            }else if(temp1==4){
                cout<<"Enter the value of k1: ";
                cin>>k1;
                cout<<"Enter the value of k2: ";
                cin>>k2;
            }
            cout<<"Enter the value of T1: "; cin>>T1;
            cout<<"Enter the value of T2: "; cin>>T2;

            Ea = -R* log(k2/k1) * ( T1*T2/(T1-T2) );

            cout<<"The value of k1: "<<k1<<" s^-1"<<endl;
            cout<<"The value of k2: "<<k2<<" s^-1"<<endl;
            cout<<"The value of T1: "<<T1<<" K"<<endl;
            cout<<"The value of T2: "<<T2<<" K"<<endl;
            cout<<"The value of Ea is found to be :"<<Ea<<" J/mol"<<endl;
    }
        break;
    
    case 4:
    {
         int temp1;
        cout<<"Enter the input format: \n1. Half time of both reactions, Ea,T2\n2. Half time of reacton 1,k2,Ea,T2\n3. k1,Half time of reaction 2,Ea,T2\n4. k1,k2,Ea,T2\nPlease enter your choice: ";
        cin>>temp1;

        if(temp1==1){
                cout<<"Enter the half time of reaction 1(in s): ";
                cin>>k1;
                cout<<"Enter the half time of reaction 2(in s): ";
                cin>>k2;
                k1=find_k(k1);
                k2=find_k(k2);
            }else if(temp1=2){
                cout<<"Enter the half time of reaction 1: ";
                cin>>k1;
                k1= find_k(k1);
                cout<<"Enter the value of k2: ";
                cin>>k2;
            }else if(temp1==3){
                cout<<"Enter the value of k1: ";
                cin>>k1;
                cout<<"Enter the half time of reaction 2: ";
                cin>>k2;
                k2= find_k(k2);
            }else if(temp1==4){
                cout<<"Enter the value of k1: ";
                cin>>k1;
                cout<<"Enter the value of k2: ";
                cin>>k2;
            }
            cout<<"Enter the value of Ea: "; cin>>Ea;
            cout<<"Enter the value of T2: "; cin>>T2;

            T1 = 1/ ( (1/T2) - ( R*log(k1/k2)/ Ea) );

            cout<<"The value of k1: "<<k1<<" s^-1"<<endl;
            cout<<"The value of k2: "<<k2<<" s^-1"<<endl;
            cout<<"The value of Ea: "<<Ea<<" J/mol"<<endl;
            cout<<"The value of T2: "<<T2<<" K"<<endl<<endl;
            cout<<"The value of T1 is found to be :"<<T1<<" K"<<endl;
    }
        break;
    
    case 5:
    {
        int temp1;
        cout<<"Enter the input format: \n1. Half time of both reactions, Ea,T1\n2. Half time of reacton 1,k2,Ea,T1\n3. k1,Half time of reaction 2,Ea,T1\n4. k1,k2,Ea,T1\nPlease enter your choice: ";
        cin>>temp1;

        if(temp1==1){
                cout<<"Enter the half time of reaction 1(in s): ";
                cin>>k1;
                cout<<"Enter the half time of reaction 2(in s): ";
                cin>>k2;
                k1=find_k(k1);
                k2=find_k(k2);
            }else if(temp1=2){
                cout<<"Enter the half time of reaction 1: ";
                cin>>k1;
                k1= find_k(k1);
                cout<<"Enter the value of k2: ";
                cin>>k2;
            }else if(temp1==3){
                cout<<"Enter the value of k1: ";
                cin>>k1;
                cout<<"Enter the half time of reaction 2: ";
                cin>>k2;
                k2= find_k(k2);
            }else if(temp1==4){
                cout<<"Enter the value of k1: ";
                cin>>k1;
                cout<<"Enter the value of k2: ";
                cin>>k2;
            }
            cout<<"Enter the value of Ea: "; cin>>Ea;
            cout<<"Enter the value of T1: "; cin>>T1;

            T2 = 1/ ( (1/T1) + ( R*log(k1/k2)/ Ea) );

            cout<<"The value of k1: "<<k1<<" s^-1"<<endl;
            cout<<"The value of k2: "<<k2<<" s^-1"<<endl;
            cout<<"The value of Ea: "<<Ea<<" J/mol"<<endl;
            cout<<"The value of T1: "<<T1<<" K"<<endl<<endl;
            cout<<"The value of T2 is found to be :"<<T2<<" K"<<endl;
    }
        break;
    default:
        cout<<"You entered a wrong option, please try with valid option!!";
        break;
    }
}


void action(){
    int flag_outside=1;
    int flag_inside=0;
    while(flag_outside==1){
        system("cls");
        cout<<"Select the task you want to perform: "<<endl;
        cout<<"1. Zeroth order"<<endl;
        cout<<"2. First order"<<endl;
        cout<<"3. Arhenius Equation"<<endl;
        cout<<"4. Temperature dependecy"<<endl;
        cout<<"5. Quit the program"<<endl;
        cout<<"Enter the choice number: ";
        int choice;
        cin>>choice;

        switch (choice)
        {
        case 1:
            {
                system("cls");
                flag_inside=1;
                while(flag_inside==1){
                    cout<<"Opening zeroth order function... \n";
                    delay(5);
                    system("cls");
                    zero_order();
                    cout<<"Do you want to continue? y/n";
                    char temp;
                    cin>>temp;
                    flag_inside= (temp=='y') ? 1:0;
                }
            }
            break;
        case 2:
            {
                system("cls");
                flag_inside=1;
                while(flag_inside==1){
                    cout<<"Opening First order function... \n";
                    delay(5);
                    system("cls");
                    first_order();
                    cout<<"Do you want to continue? y/n";
                    char temp;
                    cin>>temp;
                    flag_inside= (temp=='y') ? 1:0;
                }
            }
            break;
        case 3:
            {
                system("cls");
                flag_inside=1;
                while(flag_inside==1){
                    cout<<"Opening Arhenius equation function... \n";
                    delay(5);
                    system("cls");
                    Arhenius_Equation();
                    cout<<"Do you want to continue? y/n";
                    char temp;
                    cin>>temp;
                    flag_inside= (temp=='y') ? 1:0;
                }
            }
            break;
        case 4:
            {
                system("cls");
                flag_inside=1;
                while(flag_inside==1){
                    cout<<"Opening Temperature dependency function... \n";
                    delay(5);
                    system("cls");
                    temp_dependency();
                    cout<<"Do you want to continue? y/n";
                    char temp;
                    cin>>temp;
                    flag_inside= (temp=='y') ? 1:0;
                }
            }
            break;
        case 5:
            {
                cout<<"Quitting the program in ...."<<endl;
                timer(5);
                flag_outside=0;
            }
            break;
        default:
            cout<<"Wrong choice!!\nPlease enter a correct choice! \n";
            timer(5);
            break;
        }
    }
}

int main(){
    instructions();
    action();
    end();
    return 0;
}