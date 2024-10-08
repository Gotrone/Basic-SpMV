#include "spmv.h"
#include <stdio.h>
#include <stdlib.h>

// CSRMatrix is already defined in spmv.h, no need to redefine it here

// Convert dense matrix to CSR format
CSRMatrix convert_to_CSR(double *mat, unsigned int n)
{
    // Step 1: Count the number of non-zero elements (nnz)
    unsigned int nnz = 0;
    for (unsigned int i = 0; i < n * n; i++) {
        if (mat[i] != 0.0) {
            nnz++;
        }
    }

    // Step 2: Allocate memory for CSR structure
    CSRMatrix csr;
    csr.n = n;
    csr.values = (double *)malloc(nnz * sizeof(double));
    csr.col_indices = (unsigned int *)malloc(nnz * sizeof(unsigned int));
    csr.row_ptr = (unsigned int *)malloc((n + 1) * sizeof(unsigned int));

    // Step 3: Fill the CSR structure
    unsigned int k = 0;
    for (unsigned int i = 0; i < n; i++) {
        csr.row_ptr[i] = k;  // Start of the i-th row
        for (unsigned int j = 0; j < n; j++) {
            if (mat[i * n + j] != 0.0) {
                csr.values[k] = mat[i * n + j];
                csr.col_indices[k] = j;
                k++;
            }
        }
    }
    csr.row_ptr[n] = k;  // End of the last row

    return csr;
}

// Free memory for CSR matrix
void free_CSR(CSRMatrix *csr) {
    free(csr->values);
    free(csr->col_indices);
    free(csr->row_ptr);
}

// Perform sparse matrix-vector multiplication using CSR format
int my_sparse(const unsigned int n, CSRMatrix csr, double vec[], double result[])
{
    // Initialize the result vector
    for (unsigned int i = 0; i < n; i++) {
        result[i] = 0.0;
    }

    // Perform the sparse matrix-vector multiplication
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int k = csr.row_ptr[i]; k < csr.row_ptr[i + 1]; k++) {
            result[i] += csr.values[k] * vec[csr.col_indices[k]];
        }
    }

    return 0;  // Success
}
