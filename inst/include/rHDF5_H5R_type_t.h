#ifndef RHDF5_H5R_TYPE_T_H
#define RHDF5_H5R_TYPE_T_H

namespace Rcpp{
        template <>
        inline SEXP wrap( const H5R_type_t& mb ) {
//                int& foo = (int&)mb ;
                return wrap( (int) mb) ;
        }

        template <>
        inline H5R_type_t as( SEXP s ) {
                int tmp = as<int>(s) ;
                return (H5R_type_t)tmp;
        }
}

#endif
