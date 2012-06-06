#ifndef RHDF5_H5F_CLOSE_DEGREE_T_H
#define RHDF5_H5F_CLOSE_DEGREE_T_H

namespace Rcpp{
        template <>
        inline SEXP wrap( const H5F_close_degree_t& mb ) {
                int& foo = (int&)mb ;
                return wrap(foo) ;
        }

        template <>
        inline H5F_close_degree_t as( SEXP s ) {
                int tmp = as<int>(s) ;
                return (H5F_close_degree_t)tmp;
        }
}

#endif
