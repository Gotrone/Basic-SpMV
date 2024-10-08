#ifndef SPMV_H
#define SPMV_H

typedef struct {
    unsigned int n;      // number of rows (or cols for square matrix)
    double *values;      // non-zero values
    unsigned int *col_indices; // column indices of the non-zero values
    unsigned int *row_ptr;     // indices in values[] where each row starts
} CSRMatrix;

// Dense matrix-vector multiplication
int my_dense(const unsigned int n, const double mat[], double vec[], double result[]);

// Sparse matrix-vector multiplication in CSR format
int my_sparse(const unsigned int n, CSRMatrix csr, double vec[], double result[]);

// Convert dense matrix to CSR format
CSRMatrix convert_to_CSR(double *mat, unsigned int n);
void free_CSR(CSRMatrix *csr);

#endif
