#include <list>
#include <array>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


// Compile definitions
#define GPU_MODE  true
#define SHARED_MEMORY false
#define DEBUG_MODE true
#define SPARSE_MODE false




#if GPU_MODE

    // GPU libraries
    #include <cuda_runtime.h>

    // GPU Variable Structs
    typedef struct {
        int width;
        int height;
        int stride;
        float* elements;
    } GMatrix;

    typedef struct {
        GMatrix A; GMatrix B;
        GMatrix C; GMatrix D;
        dim3 dimBlock; dim3 dimGrid;
    } GPU_MODEL;

    typedef struct {
        GMatrix u; 
        GMatrix x; 
        GMatrix y;
    } GPU_VARS;
#else //GPU_MODE
#if SPARSE_MODE
#else //SPARSE_MODE

    // CPU libraries
    #include "Eigen/Dense"
    using namespace Eigen;

    // CPU Variable Structs
    typedef struct {
        MatrixXd A; MatrixXd B;
        MatrixXd C; MatrixXd D;
    } CPU_MODEL;

    typedef struct {
        VectorXd u; 
        VectorXd x; 
        VectorXd y;
    } CPU_VARS;
#endif //SPARSE_MODE
#endif //GPU_MODE


// CUDA kernels 

#if GPU_MODE
#if SHARED_MEMORY
    __device__ float GetElement (const GMatrix A, int row, int col) {
        return A.elements[row*A.stride + col];
    }

    __device__ float SetElement (GMatrix A, int row, int col, float value) {
        A.elements[row*A.stride + col] = value;
    }

    __device__ GMatrix GetSubMatrix (GMatrix A, int BLOCK_SIZE, int ROW, int COL) {
        
        GMatrix Asub;
        Asub.width = BLOCK_SIZE;
        Asub.height = BLOCK_SIZE;
        Asub.stride = A.stride;
        Asub.elements = &A.elements[A.stride * BLOCK_SIZE * ROW + BLOCK_SIZE * COL];
        
        return Asub;
    }

    __global__ void updateState(GMatrix A, GMatrix B, int BLOCK_SIZE, GMatrix u, GMatrix x) {
        
        // Block row and column
        int blockRow = blockIdx.y;
        int blockCol = blockIdx.x;

        // Each thread block computes one sub-matrix xSub of x
        GMatrix xSub = GetSubMatrix(x, BLOCK_SIZE, blockRow, blockCol);

        // Each thread computer one element of Csub
        // by accumulating results into xValue
        float xValue = 0;

        // Thread row and column within xSub
        int row = threadIdx.y;
        int col = threadIdx.x;

        // Loop over all the sub-matrices of A and B that are
        // required to compute the Csub
        // Multiply each pair of sub-matrices together 
        // and accumulate the results
        for (int k = 0; k < (B.width / BLOCK_SIZE); ++k) {

            // Get sub-matrix Bsub of B
            GMatrix Bsub = GetSubMatrix(B, BLOCK_SIZE, blockRow, k);

            // Get sub-matrix uSub of u
            GMatrix uSub = GetSubMatrix(u, BLOCK_SIZE, k, blockCol);

            // Shared memory used to store Bsub and uSub
            __shared__ float Bs[BLOCK_SIZE][BLOCK_SIZE];
            __shared__ float uS[1][BLOCK_SIZE];

            // Load Bsub and uSub from device memory to shared memory
            // Each thread loads one element of each sub-matrix
            Bs[row][col] = GetElement(Bsub, row, col);
            uS[row][col] = GetElement(uSub, row, col);

            // Synchronize to make sure the sub-matrices are loaded
            // before starting the computation
            __syncthreads();

            // Multiply Bsub and uSub together
            for (int m = 0; m < BLOCK_SIZE; ++m)
                xValue += Bs[row][m] * uS[1][m];
            
            // Synchronize to make sure that the preceding
            // computation is done before laoding two new
            // sub-matrices of A and B in the next iteration
            __syncthreads();
        }

        // Compute the states influence
        float a1; float a2;

        if (row )
        

        // Write Csub to device memory 
        // Each thread writes one element
        SetElement(xSub, row, col, xValue);
    }

    __global__ void MatMulKernel(GMatrix A, GMatrix B, int BLOCK_SIZE, GMatrix C) {
        
        // Block row and column
        int blockRow = blockIdx.y;
        int blockCol = blockIdx.x;

        // Each thread block computes one sub-matric Csub of C
        GMatrix Csub = GetSubMatrix(C, BLOCK_SIZE, blockRow, blockCol);
        
        // Each thread computes one element of Csub
        // by accumulating results into Cvalue
        float Cvalue = 0;

        // Thread row and column within Csub
        int row = threadIdx.y;
        int col = threadIdx.x;
        
        // Loop over all the sub-matrices of A and B that are
        // required to compute the Csub
        // Multiply each pair of sub-matrices together 
        // and accumulate the results
        for (int k = 0; k < (A.width / BLOCK_SIZE); ++k) {

            // Get sub-matrix Asub of A
            GMatrix Asub = GetSubMatrix(A, BLOCK_SIZE, blockRow, k);

            // Get usb-matrix Bsub of B
            GMatrix Bsub = GetSubMatrix(B, BLOCK_SIZE, k, blockCol);

            // Shared memory used to store Asub and Bsub
            __shared__ float As[BLOCK_SIZE][BLOCK_SIZE];
            __shared__ float Bs[BLOCK_SIZE][BLOCK_SIZE];

            // Load Asub and Bsub from device memory to shared memory
            // Each thread loads one element of each sub-matrix
            As[row][col] = GetElement(Asub, row, col);
            Bs[row][col] = GetElement(Bsub, row, col);

            // Synchronize to make sure the sub-matrices are loaded
            // before starting the computation
            __syncthreads();

            // Multiply Asub and Bsub together
            for (int m =0; m < BLOCK_SIZE; ++m)
                Cvalue += As[row][m] * Bs[m][col];
            
            // Synchronize to make sure that the preceding
            // computation is done before laoding two new
            // sub-matrices of A and B in the next iteration
            __syncthreads();
        } 

        // Write Csub to device memory 
        // Each thread writes one element
        SetElement(Csub, row, col, Cvalue);
    }
#else

    __global__ void updateStateKernel( GMatrix A, GMatrix B, GMatrix u, int IN_SIZE, GMatrix x ) {
        
        // Get the kernel index
        int row = threadIdx.x;

        // Compute the reference index for the state
        int i = 2 * int(row / 2);
        
        // The new state will be accumulated in the
        // variable xValue
        float xValue = 0;

        // Compute the input influence
        for (int k = 0; k < IN_SIZE; k++)
            xValue += B.elements[row * B.stride + k] * u.elements[k];
        
        // Compute the state influence
        xValue += A.elements[2*row] * x.elements[i] + A.elements[2*row + 1] * x.elements[i+1];

        // Save the elements on the output component
        x.elements[row] = xValue;
    }

#endif
#endif 

// FEM model

class FEM {

    public:
        /** CONST ATTRIBUTES
         *  
        */
        
        double* A; double* B; double* C; double* D;                 // Pointers to SS model
        
        int n_states; int n_inputs; int n_outputs;                  // Major size variables
        vector <string> in_names; vector <string> out_names;        // I/O respective names
        vector <int> in_sizes; vector <int> out_sizes;              // I/O respective sizes

        /** CONSTRUCTOR
         *  
        */
        
        /** MAIN ATTRIBUTES
         *  
        */

        #if GPU_MODE
            GPU_MODEL model;                                          // GPU state space model structure
            GPU_VARS state;                                           // GPU state space variables structure
        #else //GPU_MODE
        #if SPARSE_MODE
        #else //SPARSE_MODE
            CPU_MODEL model;                                          // CPU state space model structure
            CPU_VARS state;                                           // CPU state space variables structure
        #endif // SPARSE_MODE                                            
        #endif // GPU_MODE
        
        /** MAIN METHODS
         *  
        */

        void Init (void) {

        }

        void Start (bool COND_INIT) {
            // Variables assignment
            assignComputationMatrices();
            assignSimulationVariables();
            if ( COND_INIT ) {
                //assignInitialConditions();
            }
        }

        void Update (double* u) {
            
            updateState( u );
        }

        list <VectorXd> Output (vector <string> names) {
            
            #if GPU_MODE

            #else //GPU_MODE
            #if SPARSE_MODE
            #else //SPARSE_MODE
            cout << "Computing the output..." << endl;
            state.y = model.C * state.x;

            int i; list <VectorXd> outputs;
            for (int k = 0; k < names.size(); k++) {
                i = 0;
                for (int j = 0; j < out_names.size(); j++) {
                    if (out_names.at(j) == names.at(k)) {
                        #if DEBUG_MODE
                            cout << "Getting block matrix... from " << i << " to " << out_sizes.at(j) << endl;
                        #endif// DEBUG_MODE
                        VectorXd new_feature = state.y.segment(i, out_sizes.at(j));
                        #if DEBUG_MODE
                            cout << "Adding to list..." << endl;
                        #endif // DEBUG_MODE
                        outputs.push_back( new_feature );
                    }
                    i += out_sizes.at(j);
                }
            }
            return outputs;
            #endif //SPARSE_MODE
            #endif //GPU_MODE
        }

        void Terminate (void) {

        }

        /** S&G METHODS
         * 
        */

        void setDimensions (int dim[]) {
            n_states  = dim[0];
            n_inputs  = dim[1];
            n_outputs = dim[2];
        }

        void setModel (
                double* A_PAR, double* B_PAR, 
                double* C_PAR, double* D_PAR ) {
            
            A = A_PAR; B = B_PAR; C = C_PAR; D = D_PAR;
            #if DEBUG_MODE
                cout << "Creating the model matrices..." << endl;
            #endif // DEBUG_MODE
        }

        void setInputs (
                vector <string> names,
                vector <int> sizes ) {
            in_names = names;
            in_sizes = sizes;
            cout << "Input settings..." << endl;
        }

        void setOutputs (
                vector <string> names,
                vector <int> sizes ) {
            out_names = names; 
            out_sizes = sizes;
            #if DEBUG_MODE
                cout << "Output  settings..." << endl;
            #endif // DEBUG_MODE
        }


    private:
        /** PRIV ATTRIBUTES
         *  
        */

        /** PRIV METHODS
         *  
        */

        void assignComputationMatrices (void) {

            #if GPU_MODE
                // Create model matrices as GPU_MODEL
                model.A.height = model.A.stride = model.A.width = n_states;
                model.B.height = model.B.stride = n_states; model.B.width = n_inputs;
                model.C.height = model.C.stride = n_outputs; model.C.width = n_states;
                model.D.height = model.D.stride = n_outputs; model.D.width = n_inputs;

                // Load matrices to device memory
                size_t size = model.A.width * model.A.height * sizeof(float);
                cudaMalloc(&model.A.elements, size);
                cudaMemcpy(model.A.elements, A, size, cudaMemcpyHostToDevice);        
                size = model.B.width * model.B.height * sizeof(float);
                cudaMalloc(&model.B.elements, size);
                cudaMemcpy(model.B.elements, B, size, cudaMemcpyHostToDevice);
                size = model.C.width * model.C.height * sizeof(float);
                cudaMalloc(&model.C.elements, size);
                cudaMemcpy(model.C.elements, C, size, cudaMemcpyHostToDevice);
                size = model.D.width * model.D.width * sizeof(float);
                cudaMalloc(&model.D.elements, size);
                cudaMemcpy(model.D.elements, D, size, cudaMemcpyHostToDevice);

            #else //GPU_MODE
            #if SPARSE_MODE
                // ToDo Sparse computing
            #else
                // Initialize the matrix sizes 
                model.A = MatrixXd::Zero(n_states, n_states);
                model.B = MatrixXd::Zero(n_states, n_inputs);
                model.C = MatrixXd::Zero(n_outputs, n_states);
                model.D = MatrixXd::Zero(n_outputs, n_inputs);
                for (int nx  = 0; nx < n_states; nx++) {
                    // assign state matrix
                    for (int nx_j = 0; nx_j < n_states; nx_j++)
                        model.A(nx, nx_j) = *(A + (n_states * nx) + nx_j);
                    // assign input matrix
                    for (int nu = 0; nu < n_inputs; nu++)
                        model.B(nx, nu) = *(B + (n_inputs * nx) + nu);
                    // assing output matrix
                    for (int ny = 0; ny < n_outputs; ny++)
                        model.C(ny,nx) = *(C + (n_states * ny) + nx);
                }
            #endif
            #endif 
        }

        void assignSimulationVariables (void) {

            #if GPU_MODE
                // Create state matrices as GPU_VARS
                state.x.height = state.x.stride = n_states; state.x.width = 1;
                state.u.height = state.u.stride = n_inputs; state.u.width = 1;
                state.y.height = state.y.stride = n_outputs; state.y.width = 1;

                // Laod matrices to device memory
                size_t size = state.x.height * sizeof(float);
                cudaMalloc(&state.x.elements, size);
                size = state.u.height * sizeof(float);
                cudaMalloc(&state.u.elements, size);
                size = state.y.height * sizeof(float);
                cudaMalloc(&state.y.elements, size);

            #else 
            #if SPARSE_MODE
                // ToDo Sparse computing
            #else
                state.u = VectorXd::Zero(n_inputs);
                state.x = VectorXd::Zero(n_states);
                state.y = VectorXd::Zero(n_outputs);
            #endif
            #endif
        }


        void updateState (float* u) {
 
            #if GPU_MODE
                cudaMemcpy(state.u.elements, u, state.u.height, cudaMemcpyHostToDevice);
                updateStateKernel<<1,state.x.height>>(model.A.elements, model.B.elements, state.u.elements, state.x.height, state.x.elements);
            #else //GPU_MODE
            #if SPARSE_MODE
            #else //SPARSE_MODE
                for (int k = 0; k < n_inputs; k++)
                    state.u(k) = *( u + k );
                state.x = (model.A * state.x) + (model.B * state.u);    
            #endif //SPARSE_MODE
            #endif //GPU_MODE
        }
};

