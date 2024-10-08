# Instructions:
Now that you already have a dense version of a matrix - vector product (my_dense() in the provided code skeleton), create a sparse SpMV for CSR sparse matrices:
- convert the sparse matrix in a dense format (mat) into a sparse matrix in CSR format

- provide your own implementation of the product between the CSR matrix and the dense vector in my_sparse() (in the file my_sparse.c)

Once your code is working (please, use control version during the development: I want to see more than just one final commit), upload the code to your own remote repository (gitlab or github or any alternative).

To meet the deadline you have to provide the URL of your remote repository in this AulaCesga's assignment.

# SpMV: Sparse Matrix-Vector product

Use this code skeleton for the associated tasks in HPCTools.

This code is based on the use of GSL (GNU Scientific Library) for the
implementation of the baseline operations used for comparison:
- dense matrix-vector product: `cblas_dgemv()`, you need to link against *libgslcblas*
- sparse matrix-vector product: `gsl_spblas_dgemv()`, you need to link against *libgsl*

The dense product, cblas_dgemv(), can be found in other CBLAS
implementation. You just need to change the library to be linked,
eg. `-lopenblas` instead of `-lgslcblas`

The basetype in GSL for working with sparse matrices is `gsl_spmatrix`.
GSL also provides functions to help convert you dense matrices into a
sparse format.

