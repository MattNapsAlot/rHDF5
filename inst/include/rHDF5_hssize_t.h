#ifndef RHDF5_HSSIZE_T_H
#define RHDF5_HSSIZE_T_H

namespace Rcpp{
        template <>
        inline SEXP wrap( const hssize_t& mb ) {
                size_t& foo = (size_t&)mb ;
                return wrap(foo) ;
        }

        template <>
        inline hssize_t as( SEXP s ) {
                size_t tmp = as<size_t>(s) ;
                return (hssize_t)tmp;
        }
}

#endif
