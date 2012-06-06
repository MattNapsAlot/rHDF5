#ifndef RHDF5_H5FD_MEM_T_H
#define RHDF5_H5FD_MEM_T_H

using namespace H5 ;

namespace Rcpp{
        template <>
        inline SEXP wrap( const H5FD_mem_t& mb ) {
                int& foo = (int&)mb ;
                return wrap(foo) ;
        }

        template <>
        inline H5FD_mem_t as( SEXP s ) {
                int tmp = as<int>(s) ;
                return (H5FD_mem_t)tmp;
        }
}

#endif
