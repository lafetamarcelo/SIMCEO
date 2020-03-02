#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

#include "Eigen/Dense"
using namespace Eigen;

#include "FEM.cpp"

// Variables
#define TEST_MODE false

// Macros
#define INIT_FROM_ARRAY(ar) (ar, ar + sizeof(ar) / sizeof(ar[0]))

void showlist(list <VectorXd> g) 
{ 
    list <VectorXd> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << *it << endl; 
    cout << '\n'; 
} 


int main(void) {
    
    int dim[3] = {2, 3, 4};
    
    double A[2][2] = { {2,2}, {1,3} };
    double B[2][3] = { {2,3,4}, {3,1,4} };
    double C[4][2] = { {2,3}, {4,5}, {6,7}, {8,9} };
    double D[3][2] = { {4,5}, {6,7}, {8,9} };

    static const string iNames[] = {"iFirst", "iSecond"};
    static const string oNames[] = {"oFirst", "oSecond"};
    static const int iSizes[] = {1, 1};
    static const int oSizes[] = {3, 1};
        
    vector <string> iVecNames INIT_FROM_ARRAY(iNames); 
    vector <string> oVecNames INIT_FROM_ARRAY(oNames); 
    vector <int> iVecSizes INIT_FROM_ARRAY(iSizes); 
    vector <int> oVecSizes INIT_FROM_ARRAY(oSizes); 
    
    // create a fem objetc
    FEM fem; 

    fem.setDimensions( dim );          
    fem.setInputs( iVecNames, iVecSizes );
    fem.setOutputs( oVecNames, oVecSizes );
    fem.setModel( *A, *B, *C, *D );

    fem.Start(false);

    // Show some informations
    cout << "Showing the A matrix:" << endl;
    cout << fem.model.A << endl;
    cout << "Showing the B matrix:" << endl;
    cout << fem.model.B << endl;
    cout << "Showing the C matrix:" << endl;
    cout << fem.model.C << endl;
    cout << "Showing the D matrix:" << endl;
    cout << fem.model.D << endl;
    
    // Testing model update
    cout << "Updating the model states..." << endl; 
    
    double inputs[3] = {1.0, 1.0, 1.0};
    fem.Update( inputs );

    inputs[0] = 0.1; inputs[1] = 0.1; inputs[2] = 0.1;
    fem.Update( inputs );

    cout << "Computing the output..." << endl;
    list<VectorXd> outputs = fem.Output( oVecNames );

    // Show the results
    cout << "The computed results:" << endl;
    cout << "   -- the states:" << endl;
    cout << fem.state.x << endl;
    cout << "   -- the inputs:" << endl;
    cout << fem.state.u << endl;
    cout << "   -- the outputs:" << endl;
    showlist(outputs);
    cout << "The front of output:" << endl;
    cout << outputs.front() << endl; 
    cout << "The back of output:" << endl;
    cout << outputs.back() << endl; 
}
